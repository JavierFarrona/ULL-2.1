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
* Archivo: sequence.h
* Referencias: 
*     Enunciado de la práctica
* Historial de revisiones
*     16 Oct 2024 - Creación (primera versión) del código
*/



#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>
#include <vector>

#include "symbol.h"
#include "alphabet.h"


/** 
 *  @brief Esta clase se usa para guardar las secuencias
 *         Guarda los siguientes datos:
 *            - Alfabeto de la secuencia (alphabet_)
 *            - Secuencia de símbolos (sequence_)
 *            - Cadena de la secuencia (string_)
 */

class Sequence {
 private:
  Alphabet alphabet_;
  std::vector<Symbol> sequence_;
  std::string string_;
 public:
  /// Constructor
  Sequence(std::string& string);
  /// Getters
  Alphabet getAlphabet() const { return alphabet_; };
  std::string getSequence() const;
  std::string getString() const { return string_; };
  /// Funciones
  int length();
  std::string reverse();
  // Sequence reverse();
  std::string prefixes();
  std::string suffixes();
  std::string substrings();
  /// Modificación
  bool is_in(Symbol symbol);
  std::string non_used();

  /// Sobrecargas
  friend std::ostream& operator<<(std::ostream& out, const Sequence& sequence);
};

#endif