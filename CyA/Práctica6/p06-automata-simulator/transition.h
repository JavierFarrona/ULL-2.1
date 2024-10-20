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
* Archivo: transition.h
* Referencias: 
*     Enunciado de la práctica
* Historial de revisiones
*     16 Oct 2024 - Creación (primera versión) del código
*/

#ifndef TRANSITION_H
#define TRANSITION_H

#include <iostream>
#include "symbol.cc"
#include "state.cc"

/** 
 *  @brief Esta clase se usa para guardar las transiciones
 *         Guarda los siguientes datos:
 *            - Símbolo con el que se transita (symbol_)
 *            - Siguientes estados (next_state_)
 *            - Estado actual (actual_state_)
 */
class Transition {
 private:
  Symbol symbol_;
  unsigned int actual_state_;
  unsigned int next_state_;

 public:
  /// Constructores
  Transition() {};
  Transition(const Transition& transition);
  Transition(const Symbol symbol, const unsigned int actual_state, const unsigned int next_state);

  /// Getters y setters
  void setSymbol(Symbol symbol) { symbol_ = symbol; };
  Symbol getSymbol() const { return symbol_; };
  void setActualState(unsigned int state) { actual_state_ = state; };
  unsigned int getActualState() const { return actual_state_; };
  void setNextState(unsigned int states) { next_state_ = states; };
  unsigned int getNextState() const { return next_state_; };

  /// Sobrecargas
  friend bool operator==(const Transition& transition1, const Transition& transition2);
  friend bool operator!=(const Transition& transition1, const Transition& transition2);
  friend bool operator<(const Transition& transition1, const Transition& transition2);
  friend bool operator>(const Transition& transition1, const Transition& transition2);
  friend std::ostream& operator<<(std::ostream& out, const Transition& transition);
};

#endif