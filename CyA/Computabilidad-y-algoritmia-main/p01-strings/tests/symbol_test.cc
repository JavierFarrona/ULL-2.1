/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 1
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 29 Sep 2022
 * @brief Prueba para la clase simbolo
 * 
 */

#include <iostream>
#include <string>
#include "symbol.cc"

int main() {
  std::string string_test = "Hola";
  std::cout << string_test << std::endl;
  Symbol symbol = string_test;
  std::cout << symbol << std::endl;
  return 0;
}