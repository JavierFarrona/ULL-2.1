/// Programa para probar la clase "transition"

#include <iostream>
#include <string>

#include "../transition.cc"

int main() {
  /// Probamos los constructores
  Symbol symbol_0 = '0';
  Symbol symbol_1 = '1';
  std::string q0 = "q0";
  std::string q1 = "q1";
  std::string q2 = "q2";
  /// q0 -> q1 con '1'
  State state0(q0, 0, 0);
  State state1(q1, 1, 0);
  State state2(q2, 2, 1);
  Transition transition0(symbol_1, state0, state1);
  std::cout << transition0 << std::endl;
  return 0;
}