#include <iostream>
#include <string>
#include "sequence.cc"

int main() {
  Sequence sequence;
  sequence.add_symbol('a');
  sequence.add_symbol('b');
  sequence.add_symbol('c');
  std::cout << sequence << std::endl;
  std::cout << sequence.reverse() << std::endl;
  return 0;
}