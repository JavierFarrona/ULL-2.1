/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 8
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 29 Sep 2022
 * @brief Archivo: main_tools.cc
 *        Funciones para facilitar el programa principal
 * 
 * @details 
 *    29/09/2022 - Creación del fichero
 *    05/11/2022 - Adaptar a la práctica 6
 *    12/11/2022 - Adaptar a la práctica 7
 *    12/11/2022 - Adaptar a la práctica 8
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> /// Exit

const std::string kHelpText = "Modo de empleo: ./Grammar2CNF input.gra output.gra \n\
Pruebe 'Grammar2CNF --help' para mas informacion. \n\
      (input.gra) \n\
          Fichero de especificacion de una gramatica: \n\
              1: Simbolos terminales (alfabeto). \n\
              2: Simbolos no terminales. \n\
              3: Simbolo de arranque. \n\
              4: Producciones. \n";

/// Mensaje de error para cuando no se usan parámetros
void Error(std::string argv0) {
  std::cout << "No se han introducido parametros." << std::endl;
  std::cout << "Pruebe " << argv0 << " --help para mas informacion." << std::endl;
  exit(EXIT_SUCCESS);
}

/** @brief Muestra el modo de uso correcto del programa
 *         En caso de que el uso no sea el correcto finaliza la ejecución del programa.
 *  @param[in] argc Número de parámetros.
 *  @param[in] argv Vector con los parámetros.
 */
void Usage(int argc, char *argv[]) {
  if (argc > 3) {
    std::cout << argv[0] << ": Ha introducido mas de 2 parametros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parameter{argv[1]};
  if (parameter == "--help") {
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc != 3) {
    std::cout << argv[0] << ": Faltan parametros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
}

