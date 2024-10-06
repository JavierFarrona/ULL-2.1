/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 1
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 29 Sep 2022
 * @brief Archivo: main_p01strings.cc
 *        Contiene la función main del proyecto que usa la clase string
 *        Este programa recibe por línea de comandos lo siguiente:
 *        ./p01_strings filein.txt fileout.txt opcode
 *                      filein.txt: fichero de entrada que tiene en cada línea la especificación de los 
 *                      símbolos que definen el alfabeto (separados por espacios) seguidos de la cadena
 *                      fileout.txt: fichero de salida donde se escribirá el resultado
 *                      opcode: opción que queremos escribir en el fichero de salida
 *        Compilación del programa: make
 * 
 * @details 
 *    29/09/2022 - Creación del fichero
 *    02/10/2022 - Opciones y llamadas
 */

#include <iostream>
#include "main_tools.cc"

int main(int argc, char* argv[]) {
  /// Comprobamos los parámetros
  if (argc == 1) {
    Error();
  }
  Usage(argc, argv);
  /// Preparamos los argumentos
  std::string kInputFileName = argv[1];
  std::string kOutputFileName = argv[2];
  std::string opcode = argv[3];
  /// Pasamos de cadena a número el opcode
  const int kOpcode = std::stoi(opcode);
  /// Pasamos los valores a la función que realiza las opciones
  Options(kInputFileName, kOutputFileName, kOpcode);
  return 0;
}