/// Para probar la clase gramática

#include <iostream>
#include "grammar.cc"

int main() {
  Grammar grammar("./inputs/in2.gra");
  std::cout << grammar;
  grammar.check();
  Grammar CNF = grammar.ConvertToCNF();
  std::cout << CNF;
  return 0;
}