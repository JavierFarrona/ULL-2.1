/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 8
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 05 Nov 2022
 * @brief Archivo: automata.cc
 *        Implementación de la clase automata (DFA)
 * 
 * @details 
 *    05/11/2022 - Creación del fichero
 *    05/11/2022 - Añadidos los constructores
 *    05/11/2022 - Añadidos los getters y setters
 *    05/11/2022 - Añadidas las funciones
 *    05/11/2022 - Añadidas las sobrecargas
 *    12/11/2022 - Adaptada a la práctica 7
 */

#include <vector>
#include "automata.h"

const std::vector<char> kAlphabet = {'S', 'A', 'B', 'C', 'D', 'E', 'F' , 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'K', 'R', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
std::vector<bool> Used = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/// @brief Constructor de copia
DFA::DFA(const DFA& dfa) {
  alphabet_ = dfa.getAlphabet();
  states_ = dfa.getStates();
  num_ = dfa.getNum();
  initial_ = dfa.getInitial();
  finals_ = dfa.getFinals();
}

/// @brief Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const DFA& dfa) {
  out << "Alfabeto: " << dfa.getAlphabet() << std::endl;
  out << "Num: " << dfa.getNum() << std::endl;
  out << "Inicial: " << dfa.getInitial() << std::endl;
  out << "Estados: " << std::endl;
  for (const auto& elem : dfa.getStates()) out << elem << std::endl;
  out << "Finales: " << std::endl;
  for (const auto& elem : dfa.getFinals()) out << elem << std::endl;
  return out;
}

/** 
 *  @brief Busca un estado en el DFA
 *  @param[in] id
 *  @return El estado con ese id
 */
State DFA::find_state(unsigned int id) {
  State state;
  for (const auto& elem : states_) {
    if (elem.getID() == id) state = elem;
  }
  return state;
}

/** 
 *  @brief Muestra el mensaje de error de dfa
 *  @return void, pero termina el programa
 */
void error_dfa() {
  std::cout << "El fichero de especificacion no es un DFA." << std::endl;
  std::cout << "Use la opcion --help para mas informacion." << std::endl;
  exit(EXIT_SUCCESS);
} 

/** 
 *  @brief Comprueba si es DFA
 *  @param[in] state
 *  @return True si es, false si no
 */
void DFA::is_dfa() {
  /// Primera comprobación: no tiene epsilon transiciones
  for (const auto& state : states_) {
    for (const auto& transition : state.getTransitions()) {
      if (transition.getSymbol() == '&') error_dfa();
    }
  }
  /// Segunda comprobación: cada estado tiene una sola transición con cada símbolo
  for (const auto& state : states_) {
    for (const auto& symbol : getAlphabet().getAlphabet()) {
      int contador = 0;
      for (const auto& transition : state.getTransitions()) {
        if (transition.getSymbol() == symbol) ++contador;
      }
      if (contador != 1) error_dfa();
    }
  }
}

/** 
 *  @brief Comprueba si un estado es de muerte
 *  @param[in] state
 *  @return True si es, false si no
 */
bool death(const State& state) {
  bool death = true;
  for (const auto& transition : state.getTransitions()) {
    if (transition.getNextState() != state.getID()) death = false;
  }
  return death;
}

/** 
 *  @brief Comprueba si la cadena es aceptada por el autómata
 *  @param[in] sequence
 *  @return True si es aceptada, false si no
 */
bool DFA::accepted(const Sequence& sequence) {
  std::string string = sequence.getString();
  /// Comprobamos la cadena vacía
  if (string == "&") return initial_.getFinal();
  /// El vector de momento solo tiene el estado inicial
  std::vector<State> states;
  states.push_back(getInitial());
  /// Recorremos la cadena
  for (const auto& elem : string) {
    std::vector<State> new_states;
    Symbol symbol = elem;
    /// Para cada estado del vector
    for (const auto& state : states) {
      /// Buscamos las transiciones
      for (const auto& transition : state.getTransitions()) {
        /// Buscamos las que nos permiten transitar
        if (transition.getSymbol() == symbol) {
          State new_state = find_state(transition.getNextState());
          new_states.push_back(new_state);
        }
      }
    }
    states = new_states;
  }
  /// Comprobamos si son de aceptación
  for (const auto& elem : states) {
    if (elem.getFinal()) return true;
  } 
  return false;
}

/** 
 *  @brief Comprueba si el alfabeto tiene letras mayúsculas
 *  @return void
 */
void checkAlphabet(const Alphabet& alphabet) {
  for (const auto& elem : alphabet.getAlphabet()) {
    for (int i = 0; i < int(kAlphabet.size()); i++) {
      if (kAlphabet[i] == elem) Used[i] = true;
    }
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
  std::cout << "Ha usado mas de 26 estados" << std::endl;
  std::cout << "Los resultados podrían no ser los deseados" << std::endl;
  std::cout << "Simplifique su dfa" << std::endl;
  return '?';
}

/** 
 *  @brief Construye una gramática a partir de un DFA
 *  @return Grammar
 */
Grammar DFA::BuildGrammar() {
  Grammar grammar;
  /// Conjunto de terminales
  checkAlphabet(getAlphabet());
  grammar.setTerminals(getAlphabet()); 
  /// Conjunto de no terminales
  std::set<Symbol> symbols;
  std::vector<Symbol> symbols_vec;
  /// OJO: Comprobar que no han sido usados 
  char initial = getLetter();
  symbols_vec.push_back(initial);
  symbols.insert(initial);
  grammar.setInitial(initial);
  for (int i = 0; i < int(num_ - 1); ++i) {
    char new_char = getLetter();
    symbols.insert(new_char);
    symbols_vec.push_back(new_char);
  }
  grammar.setNonTerminals(symbols);
  /// Inicial
  /// Producciones normales
  set_pair productions;
  std::vector<Symbol> finales;
  std::pair<Symbol, std::vector<Symbol>> production;
  for (const auto& state : states_) {
    /// Comprobamos que no es de muerte
    if (!death(state)) {
      /// Producciones
      for (const auto& transition : state.getTransitions()) {
        finales.push_back(transition.getSymbol().getChar());
        int id = find_state(transition.getNextState()).getID();
        finales.push_back(symbols_vec[id]);
        production.first = symbols_vec[state.getID()];
        production.second = finales;
        finales.clear();
        productions.insert(production);
      }
    } 
  }
  /// Producciones de los estados finales
  for (const auto& elem : finals_) {
    production.first = symbols_vec[elem.getID()];
    finales.push_back('&');
    production.second = finales;
    finales.clear();
    productions.insert(production);
  } 
  /// Arreglamos las producciones que van a estados eliminados
  grammar.setProductions(productions);
  grammar.fixDeath();
  return grammar;
}