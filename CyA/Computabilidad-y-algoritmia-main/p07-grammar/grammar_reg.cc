/// Programa para probar las gramáticas

#include "grammar.cc"
#include "alphabet.cc"
#include "symbol.cc"

typedef std::pair<Symbol, std::vector<Symbol>> pair;
typedef std::set<pair> set_pair;

int main() {
  Grammar new_grammar;
  std::string alfabeto = "01";
  Alphabet alphabet = alfabeto;
  new_grammar.setTerminals(alphabet);
  // std::cout << alphabet << std::endl;
  std::set<Symbol> non_term;
  non_term.insert('S');
  non_term.insert('A');
  new_grammar.setNonTerminals(non_term);
  Symbol initial = 'S';
  new_grammar.setInitial(initial);
  // Producciones
  set_pair produc;
  std::vector<Symbol> vec;
  pair par; 
  // S -> 0A
  vec.push_back('0');
  vec.push_back('A');
  par.first = 'S'; 
  par.second = vec;
  produc.insert(par);
  vec.clear();
  // A -> 10A
  vec.push_back('1');
  vec.push_back('0');
  vec.push_back('A');
  vec.push_back('0');
  par.first = 'A'; 
  par.second = vec;
  produc.insert(par);
  vec.clear();
  // A -> &
  vec.push_back('&');
  par.first = 'A'; 
  par.second = vec;
  produc.insert(par);
  vec.clear();
  new_grammar.setProductions(produc);
  std::cout << new_grammar;
  std::cout << "Regular izquierda: ";
  std::cout << new_grammar.isRegularLeft() << std::endl;
  std::cout << "Regular derecha: ";
  std::cout << new_grammar.isRegularRigth() << std::endl;
  std::cout << "Regular: ";
  std::cout << new_grammar.isRegular() << std::endl;
  return 0;
}