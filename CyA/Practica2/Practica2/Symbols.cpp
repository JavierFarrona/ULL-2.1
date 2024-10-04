#include <iostream>
#include "Symbols.h"

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
 *  @brief Sobrecarga del operador de comparación
 *  @param[in] symbol
 */

bool Symbol::operator<(const Symbol& symbol) const {
  return symbol_ < symbol.getSymbol();
}