/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 2
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 29 Sep 2022
 * @brief Archivo: main_p02languages.cc
 *        Contiene la función main del proyecto que usa la clase string
 *        Este programa recibe por línea de comandos lo siguiente:
 *        ./p02_languages filein1.txt filein2.txt fileout.txt opcode
 *        Compilación del programa: make
 * 
 * @details 
 *    29/09/2022 - Creación del fichero
 *    02/10/2022 - Opciones y llamadas
 *    09/10/2022 - Adaptar a la práctica 2
 */

#include <iostream>
#include <string>
#include "main_tools.cc"

int main(int argc, char* argv[]) {
  /// Comprobamos los parámetros
  if (argc == 1) { Error(); }
  Usage(argc, argv);
  /// Preparamos los argumentos
  std::string kFirstInputFileName = argv[1];
  std::string kSecondInputFileName = argv[2];
  std::string kOutputFileName = argv[3];
  std::string opcode = argv[4];
  /// Pasamos de cadena a número el opcode
  const int kOpcode = std::stoi(opcode);
  /// Pasamos los valores a la función que realiza las opciones
  Options(kFirstInputFileName, kSecondInputFileName, kOutputFileName, kOpcode);
  return 0;
}