/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 3
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 29 Sep 2022
 * @brief Archivo: main_p03calculator.cc
 *        Contiene la función main del proyecto
 *        Este programa recibe por línea de comandos lo siguiente:
 *        ./p03_calculator filein1.txt
 *        Compilación del programa: make
 * 
 * @details 
 *    29/09/2022 - Creación del fichero
 *    02/10/2022 - Opciones y llamadas
 *    09/10/2022 - Adaptar a la práctica 2
 *    16/10/2022 - Adaptar a la práctica 3
 */

#include <iostream>
#include <string>

#include "./src/main_tools.cc"

int main(int argc, char* argv[]) {
  /// Comprobamos los parámetros
  if (argc == 1) { Error(); }
  Usage(argc, argv);
  /// Preparamos el fichero
  std::string kInputFileName = argv[1];
  FileExist(kInputFileName);
  /// Llamamos al programa
  Operate(kInputFileName);
  return 0;
}