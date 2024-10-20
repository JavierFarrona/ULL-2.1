/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Computabilidad y Algoritmia
* Curso: 2º
* C:\Users\javie\Documents\GitHub\ULL-2.1\CyA\Práctica6\p06-automata-simulator
* Autor: Javier Farrona Cabrera
* Correo: alu0101541983@ull.edu.es
* Fecha 16 Oct 2024
* Archivo: main_p06automatasimulator.cc
* Referencias: 
*     Enunciado de la práctica
* Historial de revisiones
*     16 Oct 2024 - Creación (primera versión) del código
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
  std::string kNFAFileName = argv[1];
  FileExist(kNFAFileName);
  std::string kStringsFileName = argv[2];
  FileExist(kStringsFileName);
  /// Llamamos al programa
  NFA nfa(FileToNFA(kNFAFileName));
  std::cout << nfa << std::endl;
  CheckStrings(kStringsFileName, nfa);
  return 0;
}