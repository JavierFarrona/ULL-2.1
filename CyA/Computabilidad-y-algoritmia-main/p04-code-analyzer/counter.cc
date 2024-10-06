/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 4
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 23 Oct 2022
 * @brief Archivo: counter.cc
 *        Implementación de la clase "counter"
 * 
 * @details 
 *    23/10/2022 - Creación del fichero
 *    23/10/2022 - Añadido el constructor
 */

#include "counter.h"


/** 
 *  @brief Constructor para el contador
 *         Pone todas las variables que vamos a contar
 */
Counter::Counter() {
  for_loops_ = 0;
  while_loops_ = 0;
  multi_comments_ = 0;
  normal_comments_ = 0;
  int_variables_ = 0;
  double_variables_ = 0;
}