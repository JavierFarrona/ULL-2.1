/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 12: Divide y vencerás
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 01 Ene 2023
 * @brief Archivo: tiempos.cc
 *        Contiene la implementación de la clase tiempos
 * 
 * @details 
 *    01/01/2023 - Creación del fichero
 */

#include <iostream>
#include <sys/time.h>
#include "tiempos.h"

// #include "Programa.hpp"
// #include "GeneradorCasos.hpp"

/// Número de pruebas que se realizan para obtener el tiempo medio
const int kPruebasPromedio = 10; 

/// @brief Constructor
Tiempos::Tiempos() {
  peor_ = 0;
  medio_ = 0;
  mejor_ = 0;
}

/// @brief Media de los tiempos
/// @param tiempos Array de tiempos
/// @return 
double media(const double tiempos[]) {
  double suma = 0;
  int size = kPruebasPromedio; 
  for (int i = 0; i < size; i++) suma += tiempos[i];
  return suma / size; 
}

/// @brief Devuelve la media de cuánto tarda en hacer los casos medios
/// @param[in] n : Tamaño del primer número
/// @param[in] m : Tamaño del segundo número
/// @return Media de los tiempos
double caso_medio(int n, int m) {
  double tiempos[kPruebasPromedio];
  struct timeval tiempo_inicial, tiempo_final; /// Hora de inicio y hora de fin                                                         
  double tiempo; /// Tiempo transcurrido                                                                
  for (int i = 0; i < kPruebasPromedio; i++) {
    /// NOTA: Preparar los casos falta                                                        
    gettimeofday(&tiempo_inicial, NULL); /// Toma la hora antes del algoritmo  
    /// NOTA: Llamar al algoritmo falta                                            
    gettimeofday(&tiempo_final, NULL);  /// Toma la hora después del algoritmo
    /// Calculamos el tiempo transcurrido                                                   
    tiempo = (tiempo_final.tv_sec - tiempo_inicial.tv_sec) * 1000 + (tiempo_final.tv_usec - tiempo_inicial.tv_usec) / 1000.0; 
    tiempos[i] = tiempo; /// Guarda el tiempo que ha tardado el caso i                                                         
  }
  return media(tiempos);
}

/// @brief Devuelve la media de cuánto tarda en hacer mejores casos
/// @param[in] n : Tamaño del primer número
/// @param[in] m : Tamaño del segundo número
/// @return Media de los tiempos
double caso_mejor(int n, int m) {
  struct timeval tiempo_inicial, tiempo_final; /// Hora de inicio y hora de fin                                                         
  double tiempo; /// Tiempo transcurrido  
  /// NOTA: Preparar el caso falta                                                                                                                     
  gettimeofday(&tiempo_inicial, NULL); /// Toma la hora antes del algoritmo  
  /// NOTA: Llamar al algoritmo falta                                            
  gettimeofday(&tiempo_final, NULL);  /// Toma la hora después del algoritmo   
  /// Calculamos el tiempo transcurrido                                                
  tiempo = (tiempo_final.tv_sec - tiempo_inicial.tv_sec) * 1000 + (tiempo_final.tv_usec - tiempo_inicial.tv_usec) / 1000.0; 
  return tiempo;
}

/// @brief Devuelve la media de cuánto tarda en hacer mejores casos
/// @param[in] n : Tamaño del primer número
/// @param[in] m : Tamaño del segundo número
/// @return Media de los tiempos
double caso_peor(int n, int m) {
  struct timeval tiempo_inicial, tiempo_final; /// Hora de inicio y hora de fin                                                         
  double tiempo; /// Tiempo transcurrido  
  /// NOTA: Preparar el caso falta                                                                                                                     
  gettimeofday(&tiempo_inicial, NULL); /// Toma la hora antes del algoritmo  
  /// NOTA: Llamar al algoritmo falta                                            
  gettimeofday(&tiempo_final, NULL);  /// Toma la hora después del algoritmo   
  /// Calculamos el tiempo transcurrido                                                
  tiempo = (tiempo_final.tv_sec - tiempo_inicial.tv_sec) * 1000 + (tiempo_final.tv_usec - tiempo_inicial.tv_usec) / 1000.0; 
  return tiempo;
}

/// @brief Genera los tiempos de los casos
/// @param[in] n : Tamaño del primer número
/// @param[in] m : Tamaño del segundo número
void Tiempos::generar(int n, int m) {
  mejor_ = caso_mejor(n, m);
  peor_ = caso_peor(n, m);
  medio_ = caso_medio(n, m);
}