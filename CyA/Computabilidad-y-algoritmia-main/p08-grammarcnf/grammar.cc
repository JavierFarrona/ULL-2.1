/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 8
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 12 Nov 2022
 * @brief Archivo: grammar.cc
 *        Implementación de la clase gramática
 * 
 * @details 
 *    12/11/2022 - Creación del fichero
 */

#include "grammar.h"

/** 
 *  @brief Constructor de copia
 *  @param[in] grammar
 */
Grammar::Grammar(const Grammar& grammar) {
  non_terminals_ = grammar.getNonTerminals();
  terminals_ = grammar.getTerminals();
  initial_ = grammar.getInitial();
  productions_ = grammar.getProductions();
}

/** 
 *  @brief Constructor a partir de un fichero
 *  @param[in] file 
 */
Grammar::Grammar(const std::string& file) {
  std::ifstream input_file{file, std::ios_base::in};
  std::string line;
  /// Simbolos terminales: 
  getline(input_file, line);
  int num_terminals = stoi(line);
  Alphabet terminals;
  for (int i = 0; i < num_terminals; i++) {
    getline(input_file, line);
    terminals.add(line);
  }
  terminals_ = terminals;
  /// Simbolos no terminales:
  getline(input_file, line);
  int num_non_terminals = stoi(line);
  Alphabet non_terminals;
  for (int i = 0; i < num_non_terminals; i++) {
    getline(input_file, line);
    non_terminals.add(line);
  }
  non_terminals_ = non_terminals;
  /// Simbolo de arranque:
  getline(input_file, line);
  Symbol initial = line;
  initial_ = initial;
  /// Producciones:
  getline(input_file, line);
  int num_productions = stoi(line);
  set_pair productions;
  std::string elem;
  for (int i = 0; i < num_productions; i++) {
    getline(input_file, line);
    std::stringstream new_line(line);
    pair production;
    /// Primera parte
    getline(new_line, elem, ' ');
    production.first = elem;
    /// Ignoramos el "-->"
    getline(new_line, elem, ' ');
    /// Segunda parte
    getline(new_line, elem, ' ');
    std::vector<Symbol> symbols;
    for (const auto& symbol : elem) {
      symbols.push_back(symbol);
    }
    production.second = symbols;
    productions.insert(production);
  }
  productions_ = productions;
}

/** 
 *  @brief Esta función comprueba que:
 *            1. La gramática no tenga símbolos inútiles
 *            2. La gramática no tenga producciones inútiles
 *            3. La gramática no tenga producciones unitarias
 *            4. La gramática no tenga producciones vacías
 *                NOTA: Salvo que la tenga el incial
 *  @return Void, pero termina el programa si no se cumplen las condiciones 
 */
void Grammar::check() {
  bool useless_productions = false;
  bool useless_symbols = false;
  bool unitary_productions = false;
  bool empty_productions = false;
  /// Comprobamos las producciones vacías
  for (const auto& production : getProductions()) {
    for (const auto& symbol : production.second) {
      if ((symbol == '&') and (production.first != getInitial())) {
        empty_productions = true;
        std::cout << "Se ha encontrado una produccion vacia en " << production.first << std::endl;
      }
    }
  }
  /// Comprobamos las producciones unitarias
  for (const auto& production : getProductions()) {
    if ((production.second.size() == 1) and (non_terminals_.find(production.second[0]))) {
      unitary_productions = true;
      std::cout << "Se ha encontrado una produccion unitaria en " << production.first << std::endl;
    }
  }
  /// Comprobamos los símbolos inútiles
  for (const auto& terminal : getTerminals().getAlphabet()) {
    bool used = false;
    for (const auto& production : getProductions()) {
      for (const auto& symbol : production.second) {
        if (symbol == terminal) used = true;
      }
    }
    if (!used) {
      useless_symbols = true;
      std::cout << "No se ha usado el simbolo " << terminal << std::endl;
    }
  } 
  /// Comprobamos las producciones inútiles
  for (const auto& terminal : getNonTerminals().getAlphabet()) {
    bool used = false;
    for (const auto& production : getProductions()) {
      if (production.first == terminal) used = true;
    }
    if (!used) {
      useless_productions = true;
      std::cout << "El simbolo " << terminal << " no tiene producciones" << std::endl;
    }
  } 
  if (useless_productions or useless_symbols or unitary_productions or empty_productions) {
    std::cout << "Arregle el fichero de entrada" << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/** 
 *  @brief Devuelve la primera letra no usada
 *  @return char
 */
char getLetter() {
  for (int i = 0; i < int(kAlphabet.size()); ++i) {
    if (!Used[i]) {
      Used[i] = true;
      return kAlphabet[i];
    }
  }
  std::cout << "ADVERTENCIA: Ha usado mas de 26 letras" << std::endl;
  std::cout << "Los resultados podrian no ser los deseados" << std::endl;
  std::cout << "Simplifique su gramatica" << std::endl;
  return '?';
}

/** 
 *  @brief Nos prepara los ya usados del alfabeto
 *  @return void
 */
void fixAlphabet(const Alphabet& alphabet) {
  for (const auto& elem : alphabet.getAlphabet()) {
    for (int i = 0; i < int(kAlphabet.size()); i++) {
      if (kAlphabet[i] == elem) Used[i] = true;
    }
  }
}

/** 
 *  @brief Constructor de copia
 *         NOTA: kAlphabet contiene las letras del abecedario
 *         NOTA: Used contiene las letras que ya hemos usado
 *  @return Gramática en forma normal de Chomsky
 */
Grammar Grammar::ConvertToCNF() {
  Alphabet CNF_non_terminals = getNonTerminals();
  fixAlphabet(CNF_non_terminals);
  Alphabet CNF_terminals = getTerminals();
  Symbol CNF_initial = getInitial();
  set_pair productions;

  /// PRIMERA: Cambiar los terminales
  char letter = getLetter();
  Alphabet non_terminals_F1;
  /// Añadimos las nuevas producciones
  for (const auto& symbol : getTerminals().getAlphabet()) {
    std::string non_terminal;
    non_terminal = non_terminal + letter + symbol.getChar(); 
    non_terminals_F1.add(non_terminal);
  }

  /// Cambiamos las viejas
  for (const auto& production : getProductions()) {
    if (production.second.size() > 1) {
      pair new_production;
      new_production.first = production.first;
      std::vector<Symbol> new_symbols;
      for (const auto& symbol : production.second) {
        if (CNF_terminals.find(symbol)) {
          std::string non_terminal;
          non_terminal = non_terminal + letter + symbol.getChar(); 
          new_symbols.push_back(non_terminal);
        } else {
          new_symbols.push_back(symbol);
        }
      }
      new_production.second = new_symbols;
      productions.insert(new_production);
    } else {
      productions.insert(production);
    }
  }

  /// SEGUNDA: Cambiar los no terminales
  set_pair CNF_productions;
  Alphabet non_terminals_F2;
  for (const auto& production : productions) {
    int size = production.second.size();
    if (size > 2) {
      letter = getLetter();
      /// Creamos los nuevos no terminales 
      std::vector<Symbol> symbols_D;
      symbols_D.push_back(production.first);
      for (int i = 0; i < size - 2; i++) {
        std::string non_terminal;
        non_terminal = non_terminal + letter + std::to_string(i);
        non_terminals_F2.add(non_terminal);
        symbols_D.push_back(non_terminal);
      }

      /// Almacenamos de forma temporal
      std::vector<Symbol> symbols_B;
      for (const auto& symbol : production.second) {
        symbols_B.push_back(symbol);
      }

      /// Creamos la nuevas producciones
      int size_D = symbols_D.size() - 1;
      int counter_B = 0;
      for (int i = size_D; i > 0; --i) {
        // std::cout << "Ajam" << std::endl;
        // std::cout << "||" << symbols_D[i - 1] << " --> ";
        // std::cout << symbols_B[counter_B] << " " << symbols_D[i];
        // std::cout << std::endl;
        pair new_production;
        new_production.first = symbols_D[i - 1];
        std::vector<Symbol> new_symbols;
        new_symbols.push_back(symbols_B[counter_B]);
        new_symbols.push_back(symbols_D[i]);
        new_production.second = new_symbols;
        CNF_productions.insert(new_production);
        ++counter_B;
      }
      /// Última producciión
      // std::cout << "||" << symbols_D[size_D] << " --> ";
      // std::cout << symbols_B[counter_B] << " " << symbols_B[size_D + 1];
      // std::cout << std::endl;
      pair new_production;
      new_production.first = symbols_D[size_D];
      std::vector<Symbol> new_symbols;
      new_symbols.push_back(symbols_B[counter_B]);
      new_symbols.push_back(symbols_B[size_D + 1]);
      new_production.second = new_symbols;
      CNF_productions.insert(new_production);
     } else {
      CNF_productions.insert(production);
    }
  }

  /// Arreglamos los no terminales
  for (const auto& symbol : non_terminals_F1.getAlphabet()) {
    CNF_non_terminals.add(symbol);
    pair new_production;
    new_production.first = symbol;
    std::vector<Symbol> new_symbols;
    new_symbols.push_back(symbol.getSymbol()[1]);
    new_production.second = new_symbols;
    CNF_productions.insert(new_production);
  }
  for (const auto& symbol : non_terminals_F2.getAlphabet()) {
    CNF_non_terminals.add(symbol);
  }

  /// Creamos la gramática
  Grammar CNF_grammar;
  CNF_grammar.setTerminals(CNF_terminals); 
  CNF_grammar.setNonTerminals(CNF_non_terminals); 
  CNF_grammar.setInitial(CNF_initial);
  CNF_grammar.setProductions(CNF_productions);
  return CNF_grammar;
}

/// NOTA: kAlphabet
/// NOTA: Used

/** 
 *  @brief Escribe en un fichero la gramática de la siguiente forma:
 *               1. Número de símbolos del alfabeto.
 *                    1.1. Símbolo del alfabeto en cada línea.
 *               2. Número de símbolos no terminales.
 *                    2.1. Símbolo no terminales en cada línea.
 *               3. Símbolo de arranque.
 *               4. Número de producciones de la gramática.
 *                    4.1. Producción en cada línea.
 */              
void Grammar::write(const std::string& kFileName) {
  std::ofstream output_file{kFileName};
  /// Símbolos del alfabeto
  output_file << terminals_.getSize() << std::endl;
  for (const auto& elem : terminals_.getAlphabet()) {
    output_file << elem << std::endl;
  }
  /// Símbolos no terminales
  output_file << non_terminals_.getAlphabet().size() << std::endl;
  for (const auto& elem : non_terminals_.getAlphabet()) {
    output_file << elem << std::endl;
  }
  /// Símbolo de arranque
  output_file << initial_ << std::endl;
  /// Producciones
  output_file << productions_.size() << std::endl;
  for (const auto& elem : getProductions()) {
    output_file << elem.first << " --> ";
    for (const auto& elem : elem.second) {
      output_file << elem;
    }
    output_file << std::endl;
  }
}

/** 
 *  @brief Sobracarga del operador <<
 *  @param[out] out
 *  @param[in] grammar
 *  @return out
 */
std::ostream& operator<<(std::ostream& out, const Grammar& grammar) {
  out << "Conjunto de no terminales: ";
  for (const auto& elem : grammar.getNonTerminals().getAlphabet()) out << elem << " ";
  out << std::endl;
  out << "Conjunto de terminales: ";
  for (const auto& elem : grammar.getTerminals().getAlphabet()) out << elem << " ";
  out << std::endl;
  out << "Inicial: " << grammar.getInitial() << std::endl;
  out << "Conjunto de producciones: " << std::endl;
  for (const auto& elem : grammar.getProductions()) {
    out << elem.first << " --> ";
    for (const auto& elem : elem.second) {
      out << elem;
    }
    out << std::endl;
  }
  out << std::endl;
  return out;
}

/** 
 *  @brief Escribe las producciones por consola
 *  @return void
 */
void Grammar::productions() {
  std::cout << "Conjunto de producciones: " << std::endl;
  for (const auto& letter : getNonTerminals().getAlphabet()) {
    std::cout << letter << " --> ";
    std::string line;
    for (const auto& produc : getProductions()) {
      if (produc.first == letter) {
        std::string production;
        for (const auto& elem : produc.second) {
          production += elem.getSymbol() ;
        }
        line += production + " | ";
      }
    }
    std::string fixed;
    fixed = line.substr(0, line.size() - 3);
    std::cout << fixed;
    line.clear();
    std::cout << std::endl;
  }
}

/// @brief Comprueba si la cadena pertenece a la gramática
bool Grammar::accepted(const std::string& sequence) {
  std::string string;
  std::string derivaciones;
  Symbol state = initial_;
  /// Buscamos producciones
  for (const auto& elem : sequence) {
    for (const auto& prod : productions_) {
      if (prod.first == state) {
        if (prod.second.size() != 1) {
          if (prod.second[0].getChar() == elem) {
            string += prod.second[0].getChar();
            derivaciones += prod.second[0].getChar();
            derivaciones += prod.second[1].getChar();
            state = prod.second[1];
            break;
          }
        }
      }
    }
  }
  /// Buscamos la final
  for (const auto& prod : productions_) {
    if (prod.first == state) {
      if (prod.second.size() == 1) {
        if (prod.second[0].getChar() == '&') {
          derivaciones += prod.second[0].getChar();
          break;
        }
      }
    }
  }
  return (derivaciones[derivaciones.size() - 1] == '&') and (string == sequence);
}
