/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 12: Divide y vencerás
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 01 Ene 2023
 * @brief Archivo: tiempos.h
 *        Contiene la definición de la clase tiempos
 * 
 * @details 
 *    01/01/2023 - Creación del fichero
 */

#include <iostream>

#ifndef TIEMPOS_H
#define TIEMPOS_H

class Tiempos {
 private:
  double peor_;
  double medio_;
  double mejor_;

 public:
  /// Constructor
  Tiempos();

  /// Funciones
  void generar(int n, int m);
  double getPeor() { return peor_; };
  double getMedio() { return medio_; };
  double getMejor() { return mejor_; };
};

#endif
