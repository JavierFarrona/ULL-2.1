/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 11: Algoritmos Voraces
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 16 Dic 2022
 * @brief Archivo: main.cc
 *        Contiene la función main del proyecto
 * 
 * @details 
 *    16/12/2022 - Creación del fichero
 */


#include <iostream>
#include <string>

#include "tools.cc"
#include "money.cc"

int main(int argc, char* argv[]) {
  /// Comprobamos los parámetros
  if (argc == 1) { Error(argv[0]); }
  Usage(argc, argv);
  /// Preparamos los argumentos
  Money money;
  if (argc == 4) {
    /// Dos opciones
    std::string option_1 = argv[1], option_2 = argv[2], number = argv[3];
    Option(option_1);
    Option(option_2);
    Money new_money(stod(number), true);
    new_money.devolver_cambio_alternativo();
    money = new_money;
  } else if (argc == 3) {
    /// Una opción
    std::string option = argv[1], number = argv[2];
    Option(option);
    if (option == "-b") {
      Money new_money(stod(number), true);
      new_money.devolver_cambio();
      money = new_money;
    } else {
      Money new_money(stod(number), false);
      new_money.devolver_cambio_alternativo();
      money = new_money;
    }
  } else {
    /// Ninguna opción
    std::string number = argv[1];
    Money new_money(stod(number), false);
    new_money.devolver_cambio();
    money = new_money;
  }
  /// Mostramos el resultado
  // money.cambio_basico();
  money.cambio_alternativo();
  
  return 0;
}