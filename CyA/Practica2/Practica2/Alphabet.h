#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "Symbols.h"

class Alphabet {
 public:
  /// Constructores
  Alphabet() {};
  Alphabet(std::string& alphabet);
  /// Getters
  std::set<Symbol> getAlphabet() const { return alphabet_; };
  int getSize() const { return size_; };
  /// Funciones
  bool find(Symbol symbol);
  void add(Symbol symbol);
  /// Sobrecarga del operador de salida
  friend std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet);
  /// Modif
 private:
  std::set<Symbol> alphabet_;
  int size_ = 0;
};

#endif




