/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 7
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
#include "sequence.h"

/// @brief Constructor de copia
Grammar::Grammar(const Grammar& grammar) {
  non_terminals_ = grammar.getNonTerminals();
  terminals_ = grammar.getTerminals();
  initial_ = grammar.getInitial();
  productions_ = grammar.getProductions();
}


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
void Grammar::Write(const std::string& kFileName) {
  std::ofstream output_file{kFileName};
  /// Símbolos del alfabeto
  output_file << terminals_.getSize() << std::endl;
  for (const auto& elem : terminals_.getAlphabet()) {
    output_file << elem << std::endl;
  }
  /// Símbolos no terminales
  output_file << non_terminals_.size() << std::endl;
  for (const auto& elem : non_terminals_) {
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
  for (const auto& elem : grammar.getNonTerminals()) out << elem << " ";
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
void Grammar::WriteProductions() {
  std::cout << "Conjunto de producciones: " << std::endl;
  for (const auto& letter : getNonTerminals()) {
    std::cout << letter << " --> ";
    std::string line;
    for (const auto& produc : getProductions()) {
      if (produc.first == letter) {
        std::string production;
        for (const auto& elem : produc.second) {
          production += elem.getChar() ;
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

/// @brief Comprueba si una gramática es regular
bool Grammar::isRegular() {
  return (isRegularLeft() or isRegularRigth());
}

/// @brief Comprueba si una gramática es regular por la izquierda
bool Grammar::isRegularLeft() {
  /// Recorremos las producciones
  for (const auto& prod : productions_) {
    int size = prod.second.size();
    if (int(size != 1)) {
      /// Comprobamos si el primero es no terminal
      if (non_terminals_.find(prod.second[0]) != non_terminals_.end()) {
        /// Comprobamos que el resto son terminales
        for (int i = 1; i < int(size); i++) {
          if (!terminals_.find(prod.second[i])) return false;
        }
      } else {
        for (int i = 0; i < int(size); i++) {
          if (!terminals_.find(prod.second[i])) return false;
        }
      }
    }
  }
  return true;
}

/// @brief Comprueba si una gramática es regular por la derecha
bool Grammar::isRegularRigth() {
  /// Recorremos las producciones
  for (const auto& prod : productions_) {
    int size = prod.second.size();
    if (int(size != 1)) {
      /// Comprobamos que son de la forma A -> uB
      if (non_terminals_.find(prod.second[int(size - 1)]) != non_terminals_.end()) {
        for (int i = int(size - 2); i >= 0; i--) {
          if (!terminals_.find(prod.second[i])) return false;
        }
      } else {
        for (int i = int(size - 1); i >= 0; i--) {
          if (!terminals_.find(prod.second[i])) return false;
        }
      }
    }
  }
  return true;
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

/// @brief Quitamos las producciones que iban al estado de muerte
void Grammar::fixDeath() {
  /// Arreglamos los no terminales
  std::set<Symbol> non_terminals;
  for (const auto& elem : getNonTerminals()) {
    /// Si encontramos una producción suya, se quedan
    for (const auto& prod : getProductions()) {
      if (prod.first == elem) non_terminals.insert(elem);
    }
  }
  setNonTerminals(non_terminals);
  /// Arreglamos las producciones
  set_pair productions;
  for (const auto& prod : getProductions()) {
    if (int(prod.second.size()) != 1) {
      if (non_terminals_.find(prod.second[1].getChar()) != non_terminals_.end()) {
        productions.insert(prod);
      }
      // if (elem[1].getChar())
    }
  }
  setProductions(productions);
}
