#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>
#include <vector>
#include "Symbols.h"
#include "Alphabet.h"

class Sequence {
 private:
  Alphabet alphabet_;
  std::vector<Symbol> sequence_;
  std::string string_;
  //Language language_;
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
  //Comparar si una cadena y su reversa son iguales
  bool isPalindrome();
  friend bool operator==(const Sequence& sequence1, const Sequence& sequence2);
};

#endif
