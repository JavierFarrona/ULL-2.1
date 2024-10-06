/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 1
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 29 Sep 2022
 * @brief Archivo: symbol.h
 *        Definición de la clase simbolo
 * 
 * @details 
 *    29/09/2022 - Creación del fichero
 *    30/09/2022 - Atributo y constructores
 *    01/10/2022 - Getter y setter
 */

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
};

#endif