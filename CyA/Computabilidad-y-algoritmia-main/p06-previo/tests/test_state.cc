/// Programa para probar la clase "state"

#include <iostream>
#include <string>

#include "../state.cc"
#include "../symbol.cc"

int main() {
  Symbol symbol_0 = '0';
  Symbol symbol_1 = '1';
  /// Estado q0
  {
    State state0;
    state0.setName("q0");
    state0.setID(0);
    /// Mostramos
    std::cout << state0 << std::endl;
  }
  /// Estado q1
  {
    State state1;
    state1.setName("q1");
    state1.setID(1);
    /// Mostramos
    std::cout << state1 << std::endl;
  }
  return 0;
}