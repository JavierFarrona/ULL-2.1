/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 4
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 23 Oct 2022
 * @brief Archivo: main_p04codeanalyzer.cc
 *        Contiene la función main del proyecto
 *        Este programa recibe por línea de comandos lo siguiente:
 *        ./ p04_code_analyzer filein.cc fileout.txt
 *        Compilación del programa: make
 * 
 * @details 
 *    23/10/2022 - Creación del fichero
 */

#include <iostream>
#include <string>

#include "main_tools.cc"
#include "analyzer.cc"

int main(int argc, char* argv[]) {
  /// Comprobamos los parámetros
  if (argc == 1) { Error(); }
  Usage(argc, argv);
  /// Preparamos el fichero
  std::string kInputFileName = argv[1];
  std::string kOutputFileName = argv[2];
  FileExist(kInputFileName);
  FileExist(kOutputFileName);
  /// Llamamos al programa
  Analyzer analyzed_program(kInputFileName);
  /// Guardamos el análisis
  analyzed_program.Store(kOutputFileName);
  return 0;
}