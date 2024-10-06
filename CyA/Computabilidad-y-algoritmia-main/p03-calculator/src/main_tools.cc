/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 3
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 29 Sep 2022
 * @brief Archivo: main_tools.cc
 *        Funciones para facilitar el programa principal
 * 
 * @details 
 *    29/09/2022 - Creación del fichero
 *    02/10/2022 - Usage y Option
 *    09/10/2022 - Adaptar a la nueva práctica
 *    10/10/2022 - Añadidas las llamadas
 *    11/10/2022 - Añadidos los casos especiales
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> /// Exit

#include "calculator_tools.cc"
#include "language.h"

const std::string kHelpText = "Uso: ./ p03_calculator filein.txt \n\
          Operaciones permitidas: \n\
              +: Concatenacion \n\
              |: Union \n\
              ^: Interseccion \n\
              -: Diferencia \n\
              !: Inversa \n\
              *: Potencia";

/// Mensaje de error para cuando no se usan parámetros
void Error() {
  std::cout << "No se han introducido parametros." << std::endl;
  std::cout << "Pruebe --help para mas informacion." << std::endl;
  exit(EXIT_SUCCESS);
}

/** @brief Muestra el modo de uso correcto del programa
 *         En caso de que el uso no sea el correcto finaliza la ejecución del programa.
 *  @param[in] argc Número de parámetros.
 *  @param[in] argv Vector con los parámetros.
 */
void Usage(int argc, char *argv[]) {
  if (argc > 2) {
    std::cout << argv[0] << ": Ha introducido mas de 1 parametro." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parameter{argv[1]};
  if (parameter == "--help") {
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc != 2) {
    std::cout << argv[0] << ": Faltan parametros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/** 
 *  @brief Comprueba si un fichero existe
 *  @param[in] name_of_file
 *  @return (void) Pero termina el programa si no existe
 */
void FileExist(std::string& name_of_file) {
  std::ifstream input_file{name_of_file, std::ios_base::in};
  if (!input_file) {
    std::cout << "No se ha podido abrir el archivo: " << name_of_file << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/** 
 *  @brief Comprueba si el formato de la línea es correcto
 *  @param[in] language_line
 *  @return (void) Pero termina el programa si el formato es incorrecto
 */
void CheckFormat(std::string& language_line) {
  int open = 0, close = 0, empty = 0;
  /// Comprobamos los corchetes
  for (const auto& elem : language_line) {
    if (elem == '{') ++open;
    if (elem == '}') ++close;
    if (elem == '&') ++empty;
  }
  if (open != 1 or close != 1) {
    std::cout << "El formato del archivo de entrada no es correcto." << std::endl;
    std::cout << "El formato adecuado es el siguiente: " << std::endl;
    std::cout << "L1 = {cadena, cadena, cadena}" << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (empty > 1) {
    std::cout << "El formato del archivo de entrada no es correcto." << std::endl;
    std::cout << "Se ha encontrado mas de un '&'." << std::endl;
    exit(EXIT_SUCCESS);
  }
  /// Comprobamos que no hay comas seguidas
  if (language_line.find(",,") != std::string::npos) {
    std::cout << "El formato del archivo de entrada no es correcto." << std::endl;
    std::cout << "Se ha encontrado un símbolo ',' no permitido." << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/** 
 *  @brief Realiza las acciones necesarias a cada línea del fichero
 *  @param[in] kFileName
 *  @return (void) Pero termina el programa si encuentra algún error
 */
void Operate(const std::string& kFileName) {
  std::ifstream input_file{kFileName, std::ios_base::in};
  std::string line;
  std::vector<std::pair<std::string, Language>> languages;
  while (getline(input_file, line)) {
    if (line.find("=") != std::string::npos) {
      CheckFormat(line);
      AddLanguage(languages, line);
    } else {
      Calculator(languages, line);
    }
  }
  /// Modificación
  std::string answer = "Y";
  while (answer == "Y") {
    std::string operation;
    std::cout << "Introduzca la operación que desea realizar: ";
    getline(std::cin, operation);
    Calculator(languages, operation);
    std::cout << "¿Desea introducir otra (Y/N)? : ";
    std::cin >> answer;
  }
}
