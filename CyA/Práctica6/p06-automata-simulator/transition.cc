/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Computabilidad y Algoritmia
* Curso: 2º
* C:\Users\javie\Documents\GitHub\ULL-2.1\CyA\Práctica6\p06-automata-simulator
* Autor: Javier Farrona Cabrera
* Correo: alu0101541983@ull.edu.es
* Fecha 16 Oct 2024
* Archivo: transition.cc
* Referencias: 
*     Enunciado de la práctica
* Historial de revisiones
*     16 Oct 2024 - Creación (primera versión) del código
*/



#include <iostream>
#include "transition.h"

/// @brief Constructor de copia
Transition::Transition(const Transition& transition) {
  symbol_ = transition.getSymbol();
  next_state_ = transition.getNextState();
  actual_state_ = transition.getActualState();
}

/// @brief Constructor con parámetros
Transition::Transition(const Symbol symbol, const unsigned int actual_state, const unsigned int next_state) {
  symbol_ = symbol;
  next_state_ = next_state;
  actual_state_ = actual_state;
}

/// @brief Sobrecarga del operador ==
bool operator==(const Transition& transition1, const Transition& transition2) {
  bool equal = true;
  if (transition1.getActualState() != transition2.getActualState()) equal = false;
  if (transition1.getNextState() != transition2.getNextState()) equal = false;
  if (transition1.getSymbol() != transition2.getSymbol()) equal = false;
  return equal;
}

/// @brief Sobrecarga del operador !=
bool operator!=(const Transition& transition1, const Transition& transition2) {
  return !(transition1 == transition2);
}

/// @brief Sobrecarga del operador <
bool operator<(const Transition& transition1, const Transition& transition2) {
  return transition1.getActualState() < transition2.getActualState();
}

/// @brief Sobrecarga del operador >
bool operator>(const Transition& transition1, const Transition& transition2) {
  return !(transition1 < transition2);
}

/// @brief Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const Transition& transition) {
  out << transition.getActualState();
  out << "(" << transition.getSymbol() << "): ";
  out << transition.getNextState();
  return out;
}
