/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Computabilidad y Algoritmia
* Curso: 2º
* C:\Users\javie\Documents\GitHub\ULL-2.1\CyA\Práctica6\p06-automata-simulator
* Autor: Javier Farrona Cabrera
* Correo: alu0101541983@ull.edu.es
* Fecha 16 Oct 2024
* Archivo: symbol.cc
* Referencias: 
*     Enunciado de la práctica
* Historial de revisiones
*     16 Oct 2024 - Creación (primera versión) del código
*/

#include "symbol.h"

/** 
 *  @brief Sobrecarga del operador <<
 *  @param[out] out
 *  @param[in] symbol
 */
std::ostream& operator<<(std::ostream& out, const Symbol& symbol) {
  out << symbol.getSymbol();
  return out;
}

/** 
 *  @brief Sobrecarga del operador ==
 *  @param[in] symbol1
 *  @param[in] symbol2
 */
bool operator==(const Symbol& symbol1, const Symbol& symbol2) {
  return symbol1.getSymbol() == symbol2.getSymbol();
}

/** 
 *  @brief Sobrecarga del operador !=
 *  @param[in] symbol1
 *  @param[in] symbol2
 */
bool operator!=(const Symbol& symbol1, const Symbol& symbol2) {
  return symbol1.getSymbol() != symbol2.getSymbol();
}

/** 
 *  @brief Sobrecarga del operador <
 *  @param[in] symbol1
 *  @param[in] symbol2
 */
bool operator<(const Symbol& symbol1, const Symbol& symbol2) {
  return symbol1.getSymbol() < symbol2.getSymbol();
}