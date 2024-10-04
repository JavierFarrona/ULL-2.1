#include <iostream>
#include "Alphabet.h"

const char SPACE = ' ';
const char COMA = ',';

/// Constructor

Alphabet::Alphabet(std::string& alphabet) {
  for (const auto& elem : alphabet) {
    Symbol symbol = elem;
    add(symbol);
  }
}

/// Sobrecarga del operador <<

std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet) {
  out << "{ ";
  for (const auto& symbol : alphabet.getAlphabet()) {
    out << symbol.getSymbol() << COMA << SPACE;
  }
  out << "}";
  return out;
}

/// Comprueba si un símbolo pertenece a un alfabeto

bool Alphabet::find(Symbol symbol) {
  bool found = false;
  for (const auto& elem : getAlphabet()) {
    if (symbol.getSymbol() == elem.getSymbol()) found = true;
  }
  return found;
}

/// Añade un símbolo a un alfabeto (si no lo contiene ya)

void Alphabet::add(Symbol symbol) {
  if (!find(symbol)) {
    alphabet_.insert(symbol);
    ++size_;
  } 
}
