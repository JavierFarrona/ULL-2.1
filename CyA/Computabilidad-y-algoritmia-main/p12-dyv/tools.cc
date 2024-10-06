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
Pruebe 'multbigint --help' para mas informacion. \n\
      Opciones: \n\
        -k Usa el algoritmo de Karatsuba. \n\
        -m Usa el operador * de BigInt. \n\
        -n [cota] Implementacion hibrida. \n\
        -r [digitos] Generacion aleatoria de numeros. \n\
        -c Usa el algoritmo del Campesino. \n\
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
 *  @brief Genera dos números aleatorios
 *  @param[in] num Longitud de los números
 *  @return void
 */
BigInt randomNum(int num) {
  std::string number_str;
  for (int i = 0; i < num; i++) {
    int digit = 0 + rand()%(10);
    number_str += std::to_string(digit);
  }
  BigInt number(number_str);
  return number;
}

/** 
 *  @brief Muestra el resultado del programa cuando se ejecuta sin ninguna opción
 *  @return Void
 */
void sin_opcion() {
  BigInt first, second;
  std::cin >> first;
  std::cin >> second;
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
  std::cout << "Acumulador: " << acumulador << std::endl;
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
  std::cout << "Resultado con el operador de BigInt: ";
  struct timeval tiempo_inicial, tiempo_final; /// Hora de inicio y hora de fin                                                         
  double tiempo; /// Tiempo transcurrido  
  gettimeofday(&tiempo_inicial, NULL); /// Toma la hora antes del algoritmo  
  std::cout << Operador(first, second) << std::endl;
  gettimeofday(&tiempo_final, NULL);  /// Toma la hora después del algoritmo   
  tiempo = (tiempo_final.tv_sec - tiempo_inicial.tv_sec) * 1000 + (tiempo_final.tv_usec - tiempo_inicial.tv_usec) / 1000.0; 
  std::cout << "Tiempo transcurrido: " << tiempo << std::endl;
  std::cout << "Acumulador: " << acumulador << std::endl;
}

/** 
 *  @brief Muestra el resultado del programa cuando se ejecuta con -c
 *  @return void
 */
void opcion_c() {
  BigInt first, second;
  std::cin >> first;
  std::cin >> second;
  std::cout << "Resultado con el Capesino: ";
  struct timeval tiempo_inicial, tiempo_final; /// Hora de inicio y hora de fin                                                         
  double tiempo; /// Tiempo transcurrido  
  gettimeofday(&tiempo_inicial, NULL); /// Toma la hora antes del algoritmo  
  std::cout << Campesino(first, second) << std::endl;
  gettimeofday(&tiempo_final, NULL);  /// Toma la hora después del algoritmo   
  tiempo = (tiempo_final.tv_sec - tiempo_inicial.tv_sec) * 1000 + (tiempo_final.tv_usec - tiempo_inicial.tv_usec) / 1000.0; 
  std::cout << "Tiempo transcurrido: " << tiempo << std::endl;
  std::cout << "Acumulador: " << acumulador << std::endl;
}

/** 
 *  @brief Muestra el resultado del programa cuando se ejecuta con -n
 *  @param[in] cota
 *  @return void
 */
void opcion_n(int cota) {
  BigInt first, second;
  std::cin >> first;
  std::cin >> second;
  std::cout << "Resultado con el hibrido: ";
  struct timeval tiempo_inicial, tiempo_final; /// Hora de inicio y hora de fin                                                         
  double tiempo; /// Tiempo transcurrido  
  gettimeofday(&tiempo_inicial, NULL); /// Toma la hora antes del algoritmo  
  std::cout << Hibrido(first, second, first.Size(), cota) << std::endl;
  gettimeofday(&tiempo_final, NULL);  /// Toma la hora después del algoritmo   
  tiempo = (tiempo_final.tv_sec - tiempo_inicial.tv_sec) * 1000 + (tiempo_final.tv_usec - tiempo_inicial.tv_usec) / 1000.0; 
  std::cout << "Tiempo transcurrido: " << tiempo << std::endl;
  std::cout << "Acumulador: " << acumulador << std::endl;
}

/** 
 *  @brief Muestra el resultado del programa cuando se ejecuta con -c y -r
 *  @param[in] digitos : Número de dígitos
 *  @return void
 */
void random_c(int digitos) {
  srand(time(NULL));
  BigInt first = randomNum(digitos);
  BigInt second = randomNum(digitos);
  std::cout << "Primer numero: " << first << std::endl;
  std::cout << "Segundo numero: " << second << std::endl;
  std::cout << "Resultado con el Campesino: ";
  struct timeval tiempo_inicial, tiempo_final; /// Hora de inicio y hora de fin                                                         
  double tiempo; /// Tiempo transcurrido  
  gettimeofday(&tiempo_inicial, NULL); /// Toma la hora antes del algoritmo  
  std::cout << Campesino(first, second) << std::endl;
  gettimeofday(&tiempo_final, NULL);  /// Toma la hora después del algoritmo   
  tiempo = (tiempo_final.tv_sec - tiempo_inicial.tv_sec) * 1000 + (tiempo_final.tv_usec - tiempo_inicial.tv_usec) / 1000.0; 
  std::cout << "Tiempo transcurrido: " << tiempo << std::endl;
  std::cout << "Acumulador: " << acumulador << std::endl;
}

/** 
 *  @brief Muestra el resultado del programa cuando se ejecuta con -k y -r
 *  @param[in] digitos : Número de dígitos
 *  @return void
 */
void random_k(int digitos) {
  srand(time(NULL));
  BigInt first = randomNum(digitos);
  BigInt second = randomNum(digitos);
  std::cout << "Primer numero: " << first << std::endl;
  std::cout << "Segundo numero: " << second << std::endl;
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
  std::cout << "Acumulador: " << acumulador << std::endl;
}

/** 
 *  @brief Muestra el resultado del programa cuando se ejecuta con -m y -r
 *  @param[in] digitos : Número de dígitos
 *  @return void
 */
void random_m(int digitos) {
  srand(time(NULL));
  BigInt first = randomNum(digitos);
  BigInt second = randomNum(digitos);
  std::cout << "Primer numero: " << first << std::endl;
  std::cout << "Segundo numero: " << second << std::endl;
  std::cout << "Resultado con el operador de BigInt: ";
  struct timeval tiempo_inicial, tiempo_final; /// Hora de inicio y hora de fin                                                         
  double tiempo; /// Tiempo transcurrido  
  gettimeofday(&tiempo_inicial, NULL); /// Toma la hora antes del algoritmo  
  std::cout << Operador(first, second) << std::endl;
  gettimeofday(&tiempo_final, NULL);  /// Toma la hora después del algoritmo   
  tiempo = (tiempo_final.tv_sec - tiempo_inicial.tv_sec) * 1000 + (tiempo_final.tv_usec - tiempo_inicial.tv_usec) / 1000.0; 
  std::cout << "Tiempo transcurrido: " << tiempo << std::endl;
  std::cout << "Acumulador: " << acumulador << std::endl;
}

/** 
 *  @brief Muestra el resultado del programa cuando se ejecuta con -m y -r
 *  @param[in] digitos : Número de dígitos
 *  @param[in] cota : Cota para -n
 *  @return void
 */
void random_n(int cota, int digitos) {
  srand(time(NULL));
  BigInt first = randomNum(digitos);
  BigInt second = randomNum(digitos);
  std::cout << "Primer numero: " << first << std::endl;
  std::cout << "Segundo numero: " << second << std::endl;
  std::cout << "Resultado con el hibrido: ";
  struct timeval tiempo_inicial, tiempo_final; /// Hora de inicio y hora de fin                                                         
  double tiempo; /// Tiempo transcurrido  
  gettimeofday(&tiempo_inicial, NULL); /// Toma la hora antes del algoritmo  
  std::cout << Hibrido(first, second, first.Size(), cota) << std::endl;
  gettimeofday(&tiempo_final, NULL);  /// Toma la hora después del algoritmo   
  tiempo = (tiempo_final.tv_sec - tiempo_inicial.tv_sec) * 1000 + (tiempo_final.tv_usec - tiempo_inicial.tv_usec) / 1000.0; 
  std::cout << "Tiempo transcurrido: " << tiempo << std::endl;
  std::cout << "Acumulador: " << acumulador << std::endl;
}