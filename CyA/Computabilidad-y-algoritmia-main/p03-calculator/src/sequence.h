/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 3
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 29 Sep 2022
 * @brief Archivo: sequence.h
 *        Definición de la clase cadena
 * 
 * @details 
 *    01/10/2022 - Creación del fichero
 *    01/10/2022 - Atributos y constructor
 *    01/10/2022 - Getters y funciones
 *    08/10/2022 - Arreglos en el constructor
 *    09/10/2022 - Cambios estéticos 
 *    10/10/2022 - Añadidas funciones para la práctica 2
 */

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>
#include <vector>

#include "symbol.h"
#include "alphabet.h"

class Sequence {
 private:
  Alphabet alphabet_;
  std::vector<Symbol> sequence_;
  std::string string_;

 public:
  /// Constructor
  Sequence() {};

  /// Getters
  Alphabet getAlphabet() const { return alphabet_; };
  std::vector<Symbol> getSequence() const { return sequence_; };
  std::string getString() const { return string_; };

  /// Funciones
  void add_symbol(Symbol symbol);
  void add_alphabet(Alphabet alphabet);
  int length();
  Sequence reverse() const;
  
  /// Sobrecargas
  friend std::ostream& operator<<(std::ostream& out, const Sequence& sequence);
  friend bool operator==(const Sequence& sequence1, const Sequence& sequence2);
  friend bool operator<(const Sequence& sequence1, const Sequence& sequence2);
  friend Sequence operator+(const Sequence& sequence1, const Sequence& sequence2);
  void check();
};

#endif