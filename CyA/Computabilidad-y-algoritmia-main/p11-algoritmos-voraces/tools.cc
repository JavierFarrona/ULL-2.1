/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 11: Algoritmos Voraces
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 16 Dic 2022
 * @brief Archivo: tools.cc
 *        Funciones para facilitar el programa principal
 * 
 * @details 
 *    16/12/2022 - Creación del fichero
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> /// Exit

const std::string kHelpText = "Modo de empleo: ./cambio [opcion] [numero] \n\
Pruebe 'cambio --help' para mas informacion. \n\
      Opciones: \n\
        -b Considerar tanto monedas como billetes. \n\
        -o Algoritmo mas eficiente. \n";

/// Mensaje de error para cuando no se usan parámetros
void Error(std::string argv0) {
  std::cout << "No se han introducido parametros." << std::endl;
  std::cout << "Pruebe " << argv0 << " --help para mas informacion." << std::endl;
  exit(EXIT_FAILURE);
}

/** @brief Muestra el modo de uso correcto del programa
 *         En caso de que el uso no sea el correcto finaliza la ejecución del programa.
 *  @param[in] argc Número de parámetros.
 *  @param[in] argv Vector con los parámetros.
 */
void Usage(int argc, char *argv[]) {
  if (argc > 4) {
    std::cout << argv[0] << ": Ha introducido mas de 3 parametros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para mas informacion." << std::endl;
    exit(EXIT_FAILURE);
  }
  std::string parameter{argv[1]};
  if (parameter == "--help") {
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/** @brief Muestra el modo de uso correcto del programa
 *         En caso de que el uso no sea el correcto finaliza la ejecución del programa.
 *  @param[in] argc Número de parámetros.
 *  @param[in] argv Vector con los parámetros.
 */
void Option(std::string& option) {
  std::string option_b = "-b";
  std::string option_o = "-o";
  if (option != option_b and option != option_o) {
    std::cout << "Opcion '" << option << "' desconocida." << std::endl;
    exit(EXIT_FAILURE);
  }
}

