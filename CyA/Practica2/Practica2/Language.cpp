#include "Language.h"
const char SPACE = ' ';

Language::Language(const Alphabet& alphabet, const std::string& chain)
  : alphabet_(alphabet), chain_(chain) {}

Alphabet Language::getAlphabet() const {
  return alphabet_;
}

std::string Language::getChain() const {
  return chain_;
}

void Language::addSymbolToAlphabet(Symbol symbol) {
  alphabet_.add(symbol);
}

void Language::addChain(const std::string& chain) {
  chain_ += chain;
}

std::ostream& operator<<(std::ostream& out, const Language& language) {
  out << language.getAlphabet() << SPACE << language.getChain();
  return out;
}