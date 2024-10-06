/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 3
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 29 Sep 2022
 * @brief Archivo: sequence.cc
 *        Implementación de la clase cadena
 * 
 * @details 
 *    01/10/2022 - Creación del fichero
 *    01/10/2022 - Constructor
 *    02/10/2022 - Constructor
 *    02/10/2022 - Funciones
 *    08/10/2022 - Cambiado el constructor
 *    09/10/2022 - Añadida la función para comprobar
 *    10/10/2022 - Añadidas funciones para la práctica 2
 */

#include <iostream>
#include <string>
#include <cstdlib> /// Exit
#include "sequence.h"
#include "alphabet.cc"

const std::string MARKS = "'";

/** 
 *  @brief Comprueba que la cadena pertenece al alfabeto 
 */
void Sequence::check() {
  for (const auto& elem : sequence_) {
    if (!alphabet_.find(elem)) {
      std::cout << "Cadena incorrecta. Revise el fichero de entrada." << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
}

/** 
 *  @brief Añade un símbolo a la cadena
 *  @param[in] symbol 
 */
void Sequence::add_symbol(Symbol symbol) {
  sequence_.push_back(symbol);
  if (!alphabet_.find(symbol)) alphabet_.add(symbol);
  string_ += symbol.getSymbol();
  check(); /// Comprobamos
}

/** 
 *  @brief Añade un alfabeto a la cadena
 *  @param[in] alphabet 
 */
void Sequence::add_alphabet(Alphabet alphabet) {
  alphabet_ = alphabet;
  check(); /// Comprobamos
}

/** 
 *  @brief Calcula cuantos símbolos tiene una cadena
 *  @return Número de símbolos
 */
int Sequence::length() { 
  return sequence_.size();
}

/** 
 *  @brief Calcula la cadena al revés
 *  @return String con la cadena al revés
 */
Sequence Sequence::reverse() const {
  Sequence reverse;
  reverse.add_alphabet(getAlphabet());
  for (int i = sequence_.size() - 1; i >= 0; --i) {
    reverse.add_symbol(sequence_[i]);
  }
  return reverse;
}

/** 
 *  @brief Comprueba si un string pertenece al vector
 *  @return True si pertenece
 */
bool find(std::vector<std::string> vector, std::string string) {
  bool found = false;
  for (const auto& elem : vector) {
    if (elem == string) found = true;
  }
  return found;
}

/** 
 *  @brief Pasa de vector de string a una sola string
 *  @return Vector en string
 */
std::string vector_to_string(std::vector<std::string> vector) {
  std::string string_vector;
  for (const auto& elem : vector) string_vector += elem + SPACE;
  return string_vector;
}

/** 
 *  @brief Sobrecarga del operador <<
 *  @param[out] out
 *  @param[in] sequence
 */
std::ostream& operator<<(std::ostream& out, const Sequence& sequence) {
  out << sequence.getString();
  return out;
}

/** 
 *  @brief Sobrecarga del operador ==
 *  @param[in] sequence1
 *  @param[in] sequence2
 */
bool operator==(const Sequence& sequence1, const Sequence& sequence2) {
  return sequence1.getString() == sequence2.getString();
}

/** 
 *  @brief Sobrecarga del operador <
 *  @param[in] sequence1
 *  @param[in] sequence2
 */
bool operator<(const Sequence& sequence1, const Sequence& sequence2) {
  return sequence1.getString() < sequence2.getString();
}

/** 
 *  @brief Sobrecarga del operador +
 *  @param[in] sequence1
 *  @param[in] sequence2
 */
Sequence operator+(const Sequence& sequence1, const Sequence& sequence2) {
  Sequence EMPTY_SEC; 
  EMPTY_SEC.add_symbol('&');
  if (sequence1 == EMPTY_SEC) { return sequence2; };
  if (sequence2 == EMPTY_SEC) { return sequence1; };
  Sequence sequence_sum = sequence1;
  for (const auto& elem : sequence2.getSequence()) {
    sequence_sum.add_symbol(elem);
  }
  return sequence_sum;
}