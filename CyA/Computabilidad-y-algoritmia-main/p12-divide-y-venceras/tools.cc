/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 12: Divide y vencerás
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 01 Ene 2023
 * @brief Archivo: tools.cc
 *        Funciones para facilitar el programa principal
 * 
 * @details 
 *    01/01/2023 - Creación del fichero
 */

#include <iostream>
#include <sys/time.h>
#include <string>
#include <cstdlib> /// Exit

#include "BigInt.h"
#include "multiplicacion.cc"

const std::string kHelpText = "Este programa calcula el producto de dos numeros enteros grandes \n\
Modo de empleo 1: cat n1.dat n2.dat | ./multbigint | diff - n1_x_n2.dat \n\
Modo de empleo 2: cat n3.dat n4.dat | ./multbigint | diff - n3_x_n4.dat \n\
Pruebe 'multbigint --help' para mas informacion. \n\
      Opciones: \n\
        -k Usa el algoritmo de Karatsuba. \n\
        -m Usa el operador * de BigInt. \n\
        -n [cota] Implementacion hibrida. \n\
        -r [digitos] Generacion aleatoria de numeros. \n\
        NOTA: Las opciones -k, -m y -n solo son compatibles con -r \n\
        USO: [opcion] -r [digitos] \n\
        USO CON -n: -n [cota] -r [digitos] \n";

/** 
 *  @brief Muestra el modo de uso correcto del programa
 *         En caso de que el uso no sea el correcto finaliza la ejecución del programa.
 *  @param[in] argc Número de parámetros.
 *  @param[in] argv Vector con los parámetros.
 */
void Usage(int argc, char *argv[]) {
  if (argc > 6) {
    std::cout << argv[0] << ": Ha introducido demasiados parametros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para mas informacion." << std::endl;
    exit(EXIT_FAILURE);
  } else if (argc == 2) {
    std::string parameter{argv[1]};
    if (parameter == "--help") {
      std::cout << kHelpText << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
}

/** 
 *  @brief Pone la misma cantidad de dígitos en ambos números
 *  @return void
 */
void arreglar(std::string& primero, std::string& segundo) {
  if (primero.size() < segundo.size()) {
    for (int i = primero.size(); i < segundo.size(); i++) {
      primero = '0' + primero;
    }
  } else {
    for (int i = segundo.size(); i < primero.size(); i++) {
      segundo = '0' + segundo;
    }
  }
}

/** 
 *  @brief Muestra el resultado del programa cuando se ejecuta sin ninguna opción
 *  @return Void
 */
void sin_opcion() {
  std::string first_str, second_str;
  std::cout << "Primero: "; std::cin >> first_str;
  std::cout << "Segundo: "; std::cin >> second_str;
  arreglar(first_str, second_str);
  BigInt first(first_str);
  BigInt second(second_str);
  /// Por defecto Karatsuba
  std::cout << "Resultado con Karatsuba: ";
  struct timeval tiempo_inicial, tiempo_final; /// Hora de inicio y hora de fin                                                         
  double tiempo; /// Tiempo transcurrido  
  gettimeofday(&tiempo_inicial, NULL); /// Toma la hora antes del algoritmo  
  BigInt Karat;
  Karat = Karatsuba(first, second, first.Size());
  std::cout << Karat << std::endl;
  gettimeofday(&tiempo_final, NULL);  /// Toma la hora después del algoritmo   
  tiempo = (tiempo_final.tv_sec - tiempo_inicial.tv_sec) * 1000 + (tiempo_final.tv_usec - tiempo_inicial.tv_usec) / 1000.0; 
  std::cout << "Tiempo transcurrido: " << tiempo << std::endl;
}

/** 
 *  @brief Muestra el resultado del programa cuando se ejecuta con -m
 *  @return void
 */
void opcion_m() {
  BigInt first, second;
  std::cin >> first;
  std::cin >> second;
  /// Por defecto Karatsuba
  Multiplicacion mult(first, second);
  std::cout << "Resultado con el operador de BigInt: ";
  struct timeval tiempo_inicial, tiempo_final; /// Hora de inicio y hora de fin                                                         
  double tiempo; /// Tiempo transcurrido  
  gettimeofday(&tiempo_inicial, NULL); /// Toma la hora antes del algoritmo  
  std::cout << Operador(mult.getPrimero(), mult.getSegundo()) << std::endl;
  gettimeofday(&tiempo_final, NULL);  /// Toma la hora después del algoritmo   
  tiempo = (tiempo_final.tv_sec - tiempo_inicial.tv_sec) * 1000 + (tiempo_final.tv_usec - tiempo_inicial.tv_usec) / 1000.0; 
  std::cout << "Tiempo transcurrido: " << tiempo << std::endl;
}

/** 
 *  @brief Muestra el resultado del programa cuando se ejecuta con -n
 *  @param[in] cota
 *  @return Void
 */
void opcion_n(int cota) {
std::string first_str, second_str;
  std::cout << "Primero: "; std::cin >> first_str;
  std::cout << "Segundo: "; std::cin >> second_str;
  arreglar(first_str, second_str);
  BigInt first(first_str);
  BigInt second(second_str);
  std::cout << "Resultado con el hibrido: ";
  struct timeval tiempo_inicial, tiempo_final; /// Hora de inicio y hora de fin                                                         
  double tiempo; /// Tiempo transcurrido  
  gettimeofday(&tiempo_inicial, NULL); /// Toma la hora antes del algoritmo  
  std::cout << Hibrido(first, second, first.Size(), cota) << std::endl;
  gettimeofday(&tiempo_final, NULL);  /// Toma la hora después del algoritmo   
  tiempo = (tiempo_final.tv_sec - tiempo_inicial.tv_sec) * 1000 + (tiempo_final.tv_usec - tiempo_inicial.tv_usec) / 1000.0; 
  std::cout << "Tiempo transcurrido: " << tiempo << std::endl;
}