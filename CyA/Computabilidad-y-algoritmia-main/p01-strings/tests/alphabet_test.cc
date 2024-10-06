/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 1
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 29 Sep 2022
 * @brief Prueba para la clase alfabeto
 * 
 */

#include <iostream>
#include <string>
#include "alphabet.cc"

int main() {
  // std::string string_test = "Hola";
  // std::cout << string_test << std::endl;
  // /// Probamos el constructor
  // Symbol symbol = string_test;
  // Alphabet alphabet = symbol;
  // /// Probamos la sobrecarga de la salida
  // std::cout << alphabet << std::endl;
  // /// Probamos a añadir elementos
  // std::string string_test_two = "Adios";
  // std::string string_test_three = "Buenas";
  // symbol = string_test_two;
  // alphabet.add(symbol);
  // symbol = string_test_three;
  // alphabet.add(symbol);
  // std::cout << alphabet << std::endl;
  // /// Probamos a buscar un elemento
  // if (alphabet.find(string_test_two)) {
  //   std::cout << "Encontrado" << std::endl;
  // }
  // /// Probamos el constructor por defecto
  // Alphabet alphabet_2;
  // alphabet_2.add(symbol);
  // std::cout << alphabet_2 << std::endl;
  std::string string_test = "Hola";
  Alphabet alphabet_test = string_test;
  std::cout << alphabet_test << std::endl;
  return 0;
}