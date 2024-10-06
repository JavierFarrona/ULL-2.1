/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 12: Divide y vencerás
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 01 Ene 2023
 * @brief Archivo: main.cc
 *        Contiene la función main del proyecto
 * 
 * @details 
 *    01/01/2023 - Creación del fichero
 *    02/01/2023 - Pruebas del correcto funcionamiento de las opciones
 */


#include <iostream>
#include <string>

#include "tools.cc"
#include "BigInt.cc"

int main(int argc, char* argv[]) {
  /// Comprobamos los parámetros
  Usage(argc, argv);
  /// Preparamos los argumentos
  std::string option_n = "-n", option_m = "-m", option_k = "-k", option_r = "-r", option_c = "-c";
  if (argc == 5) {
    /// -n combinado con -r
    int cota = std::stoi(argv[4]);
    int digitos = std::stoi(argv[2]);
    random_n(cota, digitos);
  } else if (argc == 4) {
    /// Opciones combinadas (-k, -c o -m con el -r)
    std::string algoritmo = argv[1];
    int digitos = std::stoi(argv[3]);
    if (algoritmo == "-k") {
      random_k(digitos);
    } else if (algoritmo == "-m") {
      random_m(digitos);
    } else if (algoritmo == "-c") {
      random_c(digitos);
    } else {
      std::cout << "Opcion " << algoritmo << " desconocida." << std::endl;
      return EXIT_FAILURE;
    }
  } else if (argc == 3) {
    /// Opciones -n y -r
    std::string option = argv[1];
    if (option == option_n) {
      /// -n [cota] Implementación hibrida.
      int cota = std::stoi(argv[2]);
      opcion_n(cota);
    } else if (option == option_r) {
      /// -r [digitos] Generacion aleatoria de numeros.
      int digitos = std::stoi(argv[2]);
      random_k(digitos);
    } else {
      std::cout << "Opcion '" << option << "' desconocida." << std::endl;
      return EXIT_FAILURE;
    }
  } else if (argc == 2) {
    /// Opciones -k, -m y -c
    std::string option = argv[1];
    if (option == option_k) {
      /// Por defecto usa el -k
      sin_opcion();
    } else if (option == option_c) {
      /// Opción de usar el del campesino
      opcion_c();
    } else if (option == option_m) {
      /// Opción de usar el operador de BigInt
      opcion_m();
    } else {
      /// O la opción es desconocida o falta información
      if (option == option_n) {
        std::cout << "Opcion '" << option << "' necesita una cota." << std::endl;
        return EXIT_FAILURE; 
      } else if (option == option_r) {
        std::cout << "Opcion '" << option << "' necesita el numero de digitos." << std::endl;
        return EXIT_FAILURE; 
      } else {
        std::cout << "Opcion '" << option << "' desconocida." << std::endl;
        return EXIT_FAILURE;
      } 
    }
  } else {
    /// Ninguna opción (-k por defecto)
    sin_opcion();
  }
  return EXIT_SUCCESS;
}