/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 6
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 05 Nov 2022
 * @brief Archivo: NFA.cc
 *        Implementación de la clase NFA
 * 
 * @details 
 *    05/11/2022 - Creación del fichero
 *    05/11/2022 - Añadidos los constructores
 *    05/11/2022 - Añadidos los getters y setters
 *    05/11/2022 - Añadidas las funciones
 *    05/11/2022 - Añadidas las sobrecargas
 */

#include <vector>
#include "NFA.h"

/// @brief Constructor de copia
NFA::NFA(const NFA& nfa) {
  alphabet_ = nfa.getAlphabet();
  states_ = nfa.getStates();
  num_ = nfa.getNum();
  initial_ = nfa.getInitial();
  finals_ = nfa.getFinals();
}

/// @brief Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const NFA& nfa) {
  out << "Alfabeto: " << nfa.getAlphabet() << std::endl;
  out << "Num: " << nfa.getNum() << std::endl;
  out << "Inicial: " << nfa.getInitial() << std::endl;
  out << "Estados: " << std::endl;
  for (const auto& elem : nfa.getStates()) out << elem << std::endl;
  out << "Finales: " << std::endl;
  for (const auto& elem : nfa.getFinals()) out << elem << std::endl;
  return out;
}

/// @brief Busca y devuelve el estado con ese id
State NFA::find_state(unsigned int id) {
  State state;
  for (const auto& elem : states_) {
    if (elem.getID() == id) state = elem;
  }
  return state;
}

/// @brief Sobrecarga de la suma de vectores de estados
/// @param states1 
/// @param states2 
/// @return Suma de los dos
std::vector<State> operator+(const std::vector<State>& states1, const std::vector<State>& states2) {
  std::vector<State> add = states1;
  for (const auto& state : states2) {
    add.push_back(state);
  }
  return add;
}

/// @brief Función auxiliar de las combinaciones
/// @param pos 
/// @param str 
/// @return string
std::string return_vector(const std::vector<int> &pos, const std::vector<std::string> &str) {
  std::string sequence;
  for (size_t i = 1; i < pos.size(); ++i) 
    sequence += str[pos[i]].c_str();
  return sequence;
}

/// @brief Combinaciones de n elementos tomados en grupos de m
/// @param n : Número de elementos
/// @param m : Longitud de los grupos
/// @param str : Vector de string con los elementos
std::vector<std::string> combination_with_repetiton(int n, int m, const std::vector<std::string> &str) {
  std::vector<std::string> sequences;
  std::vector<int> pos(m + 1, 0);
  while (true) {
    for (int i = m; i > 0; i -= 1) {
      if (pos[i] > n - 1) {
        pos[i - 1] += 1;
        for (int j = i; j <= m; j += 1)
          pos[j] = pos[j - 1];
      }
    }
    if (pos[0] > 0)
      break;
    sequences.push_back(return_vector(pos, str));
    pos[m] += 1;
  }
  return sequences;
}

/// @brief Muestra las cadenas aceptadas por el autómata de igual o menor longitud
/// @param length 
void NFA::strings(int length) {
  /// Vector de string con a y b 
  std::vector<std::string> symbols;
  for (const auto& symbol : getAlphabet().getAlphabet()) {
    symbols.push_back(symbol.getSymbol());
  }
  /// Llamamos a nuestras combinaciones
  for (int i = 1; i <= length; ++i) {
    std::vector<std::string> sequences = combination_with_repetiton(symbols.size(), i, symbols);
    for (auto& sequence : sequences) {
      std::cout << sequence << " --- ";
      if (accepted(sequence)) std::cout << "Accepted" << std::endl;
      else std::cout << "Rejected" << std::endl;
    }
  }
}

/// @brief Comprueba si un NFA es DFA
/// @return True si lo es, false si no
bool NFA::is_dfa() {
  /// Primera comprobación: no tiene epsilon transiciones
  for (const auto& state : states_) {
    for (const auto& transition : state.getTransitions()) {
      if (transition.getSymbol() == '&') return false;
    }
  }
  /// Segunda comprobación: cada estado tiene una sola transición con cada símbolo
  for (const auto& state : states_) {
    for (const auto& symbol : getAlphabet().getAlphabet()) {
      int contador = 0;
      for (const auto& transition : state.getTransitions()) {
        if (transition.getSymbol() == symbol) ++contador;
      }
      if (contador != 1) return false;
    }
  } 
  /// Si llegamos aquí
  return true;
}

/// Método que le pases un conjunto y te calcule E-clausura
/// Unión de los E-clausura del conjunto
/// Return cuando no tengas épsilon
std::vector<State> NFA::epsilon_transition(std::vector<State>& states) {
  std::vector<State> copy = states;
  for (const auto& state : states) {
    std::vector<State> e_transition;
    std::vector<State> empty;
    for (const auto& transition : state.getTransitions()) {
      if (transition.getSymbol() == '&') {
        e_transition.push_back(find_state(transition.getNextState()));
      }
    }
    if (e_transition != empty) {
      states = states + epsilon_transition(e_transition);
    }
  }
  return copy;
}

/** 
 *  @brief Comprueba si la cadena es aceptada por el autómata
 *  @param[in] sequence
 *  @return True si es aceptada, false si no
 */
bool NFA::accepted(const Sequence& sequence) {
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
    /// Buscamos las E-transiciones
    epsilon_transition(states);
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