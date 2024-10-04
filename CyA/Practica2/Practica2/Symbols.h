#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <string>

class Symbol {
 private:
  std::string symbol_;

 public:
  /// Constructores
  Symbol() {};
  Symbol(std::string& symbol) { symbol_ = symbol; };
  Symbol(char symbol) { symbol_ = symbol; };
  /// Getter
  std::string getSymbol() const { return symbol_; };
  /// Setter (NO usada)
  void setSymbol(std::string symbol) { symbol_ = symbol; };
  /// Sobrecarga del operador de salida (NO usada)
   friend std::ostream& operator<<(std::ostream& out, const Symbol& symbol);
   /// Sobrecarga del operador de comparación
   bool operator<(const Symbol& symbol) const { return symbol_ < symbol.getSymbol(); };
};

#endif
