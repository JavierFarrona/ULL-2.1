/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 1
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 29 Sep 2022
 * @brief Prueba para la clase cadena
 * 
 */

#include <iostream>
#include <string>
#include "sequence.cc"

int main() {
  std::string string_test = "a bc abcabc";
  Sequence sequence_test = string_test;
  std::cout << sequence_test.getSequence() << std::endl;
  std::cout << sequence_test.getAlphabet() << std::endl;
  // std::cout << sequence_test.getPrueba() << std::endl;
  // std::cout << "Longitud: " << sequence_test.length() << std::endl;
  // std::cout << "Inversa: " << sequence_test.reverse() << std::endl;
  // std::cout << "Prefijos: " << sequence_test.prefixes() << std::endl;
  // std::cout << "Sufijos: " << sequence_test.suffixes() << std::endl;
  std::cout << "Subcadenas: " << sequence_test.substrings() << std::endl;
  return 0;
}