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
* Archivo: state.cc
* Referencias: 
*     Enunciado de la práctica
* Historial de revisiones
*     16 Oct 2024 - Creación (primera versión) del código
*/



#include <iostream>
#include "state.h"

/// @brief Constructor de copia
State::State(const State& state) {
  name_ = state.getName();
  id_ = state.getID();
  final_ = state.getFinal();
}

/// @brief Constructor con parámetros
State::State(std::string name, unsigned int id, bool final) {
  name_ = name;
  id_ = id;
  final_ = final;
}

/// @brief Sobrecarga del operador =
void State::operator=(const State& state) {
  name_ = state.getName();
  id_ = state.getID();
  final_ = state.getFinal();
}

/// @brief Sobrecarga del operador ==
bool operator==(const State& state1, const State& state2) {
  bool equal = true;
  if (state1.getID() != state2.getID()) equal = false;
  return equal;
}

/// @brief Sobrecarga del operador !=
bool operator!=(const State& state1, const State& state2) {
  return !(state1 == state2);
}

/// @brief Sobrecarga del operador <
bool operator<(const State& state1, const State& state2) {
  return (state1.getID() < state2.getID());
}

/// @brief Sobrecarga del operador >
bool operator>(const State& state1, const State& state2) {
  return !(state1 < state2);
}

/// @brief Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const State& state) {
  out << state.getName() << "(" << state.getID() << ")";
  out << "(" << state.getFinal() << ")";
  return out;
}
