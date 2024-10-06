/// Programa para probar las gramáticas

#include "grammar.cc"
#include "alphabet.cc"
#include "symbol.cc"

int main() {
  Grammar new_grammar;
  std::string alfabeto = "ab";
  Alphabet alphabet = alfabeto;
  // std::cout << alphabet << std::endl;
  std::set<char> symbols;
  symbols.insert('S');
  symbols.insert('A');
  symbols.insert('B');
  char initial = 'S';
  /// Producciones
  std::vector<char> finales;
  std::pair<char, std::vector<char>> produc;
  set_pair productions;
  /// S -> aS
  finales.push_back('a');
  finales.push_back('S');
  produc.first = 'S';
  produc.second = finales;
  finales.clear();
  productions.insert(produc);
  /// S -> bA
  finales.push_back('b');
  finales.push_back('A');
  produc.first = 'S';
  produc.second = finales;
  finales.clear();
  productions.insert(produc);
  /// A -> aB
  finales.push_back('a');
  finales.push_back('B');
  produc.first = 'A';
  produc.second = finales;
  finales.clear();
  productions.insert(produc);
  /// A -> bB
  finales.push_back('b');
  finales.push_back('B');
  produc.first = 'A';
  produc.second = finales;
  finales.clear();
  productions.insert(produc);
  /// A -> &
  finales.push_back('&');
  produc.first = 'A';
  produc.second = finales;
  finales.clear();
  productions.insert(produc);
  /// B -> aB
  finales.push_back('a');
  finales.push_back('B');
  produc.first = 'B';
  produc.second = finales;
  finales.clear();
  productions.insert(produc);
  /// B -> bB
  finales.push_back('b');
  finales.push_back('B');
  produc.first = 'B';
  produc.second = finales;
  finales.clear();
  productions.insert(produc);
  /// Gramática
  new_grammar.setAlphabet(alphabet);
  new_grammar.setInitial(initial);
  new_grammar.setSymbols(symbols);
  new_grammar.setProductions(productions);
  new_grammar.Write();
  return 0;
}