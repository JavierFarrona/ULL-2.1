/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 7
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 29 Sep 2022
 * @brief Archivo: main_p07grammar.cc
 *        Contiene la función main del proyecto
 *        Este programa recibe por línea de comandos lo siguiente:
 *        ./dfa2grammar input.fa output.gra
 *        Compilación del programa: make
 * 
 * @details 
 *    29/09/2022 - Creación del fichero
 *    05/11/2022 - Adaptar a la práctica 6
 *    12/11/2022 - Adaptar a la práctica 7
 */

#include <iostream>
#include <string>

#include "main_tools.cc"
#include "file_tools.cc"

int main(int argc, char* argv[]) {
  /// Comprobamos los parámetros
  if (argc == 1) { Error(argv[0]); }
  Usage(argc, argv);
  /// Preparamos el fichero
  std::string kDFAFileName = argv[1];
  FileExist(kDFAFileName);
  std::string kOutputFileName = argv[2];
  FileExist(kOutputFileName);
  /// Llamamos al programa
  DFA dfa(FileToDFA(kDFAFileName));
  // std::cout << dfa << std::endl;
  Grammar grammar = dfa.BuildGrammar();
  std::cout << grammar;
  grammar.Write(kOutputFileName);
  // grammar.WriteProductions();
  // std::string string = "111";
  // std::cout << grammar.accepted(string) << std::endl;
  return 0;
}