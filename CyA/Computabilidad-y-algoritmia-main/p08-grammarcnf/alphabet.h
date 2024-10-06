/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 8
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
 *    08/10/2022 - Cambios estéticos
 */

#ifndef ALPHABET_H
#define ALPHABET_H

/// Para comprobaciones
const std::vector<char> kAlphabet = {'S', 'A', 'B', 'C', 'D', 'E', 'F' , 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'K', 'R', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
std::vector<bool> Used = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "symbol.h"

const char SPACE = ' ';

class Alphabet {
 private:
  std::set<Symbol> alphabet_;

 public:
  /// Constructores
  Alphabet() {};
  Alphabet(std::string& string);

  /// Getters
  std::set<Symbol> getAlphabet() const { return alphabet_; };
  int getSize() const { return alphabet_.size(); };

  /// Funciones
  bool find(Symbol symbol) const;
  void add(Symbol symbol);

  /// Sobrecargas
  friend std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet);
  friend Alphabet operator+(const Alphabet& alphabet1, const Alphabet& alphabet2);
};

#endif