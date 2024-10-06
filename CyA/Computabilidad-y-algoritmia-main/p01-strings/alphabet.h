/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 1
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 29 Sep 2022
 * @brief Archivo: alphabet.h
 *        Definición de la clase alfabeto
 * 
 * @details 
 *    29/09/2022 - Creación del fichero
 *    30/09/2022 - Atributos y constructores
 *    01/10/2022 - Getters y funciones
 */

#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <vector>
#include <string>
#include "symbol.h"

class Alphabet {
 private:
  std::vector<Symbol> alphabet_;
  int size_ = 0;

 public:
  /// Constructores
  Alphabet() {};
  Alphabet(std::string& string);
  /// Getters
  std::vector<Symbol> getAlphabet() const { return alphabet_; };
  int getSize() const { return size_; };
  /// Funciones
  bool find(Symbol symbol);
  void add(Symbol symbol);
  /// Sobrecarga del operador de salida
  friend std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet);
  /// Modif
};

#endif