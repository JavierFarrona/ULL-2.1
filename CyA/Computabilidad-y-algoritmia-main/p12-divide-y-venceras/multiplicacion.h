/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 12: Divide y vencerás
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 01 Ene 2023
 * @brief Archivo: multiplicacion.h
 *        Contiene la definición de la clase Multiplicacion
 * 
 * @details 
 *    01/01/2023 - Creación del fichero
 */

#include <iostream>
#include <string>
#include "BigInt.h"

#ifndef MULT_H
#define MULT_H

class Multiplicacion {
 private:
  BigInt primero_;
  BigInt segundo_;

 public:
  /// Constructor
  Multiplicacion() {};
  Multiplicacion(std::string& primero, std::string& segundo);
  Multiplicacion(BigInt& primero, BigInt& segundo);

  /// Getter y setters
  void setPrimero(const BigInt& primero) { primero_ = primero; };
  void setSegundo(const BigInt& segundo) { segundo_ = segundo; };
  BigInt getPrimero() { return primero_; };
  BigInt getSegundo() { return segundo_; };

  /// Funciones
  void aleatorios(int digitos);
  void randomNum(int num);

};

/// Funciones
BigInt Karatsuba(const BigInt& num1, const BigInt& num2, long long n);
BigInt Operador(const BigInt& num1, const BigInt& num2);
BigInt Hibrido(const BigInt& num1, const BigInt& num2, long long n, const int cota);

#endif
