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
* Archivo: symbol.h
* Referencias: 
*     Enunciado de la práctica
* Historial de revisiones
*     16 Oct 2024 - Creación (primera versión) del código
*/



#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <string>

//haz cometario de doxygen 
/** 
 *  @brief Esta clase se usa para guardar los símbolos
 *         Guarda los siguientes datos:
 *            - Símbolo (symbol_)
 */

class Symbol {
 private:
  std::string symbol_;

 public:
  /// Constructores
  Symbol() {};
  Symbol(const std::string& symbol) { symbol_ = symbol; };
  Symbol(const char symbol) { symbol_ = symbol; };
  
  /// Getters
  std::string getSymbol() const { return symbol_; };
  int getLength() const { return symbol_.length(); };
  /// Setter
  void setSymbol(std::string& symbol) { symbol_ = symbol; };

  /// Sobrecargas
  friend std::ostream& operator<<(std::ostream& out, const Symbol& symbol);
  friend bool operator==(const Symbol& symbol1, const Symbol& symbol2);
  friend bool operator!=(const Symbol& symbol1, const Symbol& symbol2);
  friend bool operator<(const Symbol& symbol1, const Symbol& symbol2);
};

#endif