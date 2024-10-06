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
 *        Contiene las siguientes funciones:
 *              Usage: Comprueba que el pograma está siendo usado de forma correcta
 *              Option: Se encarga de llamar a las distintas opciones
 * 
 * @details 
 *    29/09/2022 - Creación del fichero
 *    02/10/2022 - Usage y Option
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> /// Exit
#include "sequence.cc"

const std::string kHelpText = "Uso: ./p01_strings filein.txt fileout.txt opcode \n Opcodes válidos: \n\
        1: Longitud \n\
        2: Inversa \n\
        3: Prefijos \n\
        4: Sufijos \n\
        5: Subcadenas";

/// Mensaje de error para cuando no se usan parámetros
void Error() {
  std::cout << "No ha introducido parámetros." << std::endl;
  std::cout << "Pruebe --help para más información." << std::endl;
  exit(EXIT_SUCCESS);
}

/** @brief Muestra el modo de uso correcto del programa
 *         En caso de que el uso no sea el correcto finaliza la ejecución del programa.
 *  @param[in] argc Número de parámetros.
 *  @param[in] argv Vector con los parámetros.
 */
void Usage(int argc, char *argv[]) {
  if (argc > 4) {
    std::cout << argv[0] << ": Ha introducido más de tres parámetros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información." << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parameter{argv[1]};
  if (parameter == "--help") {
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc != 4) {
    std::cout << argv[0] << ": Faltan parámetros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información." << std::endl;
    exit(EXIT_SUCCESS);
  }
  if ((argc == 4) and (std::stoi(argv[3]) > 5 or std::stoi(argv[3]) < 0)) {
    std::cout << "Ha introducido un opcode incorrecto." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información." << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/** 
 *  @brief Realiza la opción marcada en el opcode
 *  @param[in] kInputFileName
 *  @param[in] kOutputFileName
 *  @param[in] kOpcode
 */
void Options(std::string kInputFileName, std::string kOutputFileName, int kOpcode) {
  /// Comprobamos que existe el fichero de entrada
  std::ifstream input_file{kInputFileName, std::ios_base::in};
  if (!input_file) {
    std::cout << "No se ha podido abrir el archivo: " << kInputFileName << std::endl;
    exit(EXIT_SUCCESS);
  }
  /// Leemos el fichero de entrada línea a línea
  std::string line;
  std::ofstream output_file{kOutputFileName};
  std::cout << "Realizando la opción " << kOpcode << " sobre el fichero de entrada." << std::endl;
  while (getline(input_file, line)) {
    /// Modificación
    /// Les realizamos la opción marcada
    Sequence new_sequence = line;
    output_file << "Alfabeto: " << new_sequence.getAlphabet() << std::endl;
    output_file << "Secuencia: " << new_sequence.getString() << std::endl;
    output_file << "No usadas: " << new_sequence.non_used()<< std::endl;
    switch (kOpcode) {
      case 1: /// Longitud
        output_file << new_sequence.length() << std::endl;
        break;
      case 2: /// Inversa         
        output_file << new_sequence.reverse() << std::endl;
        break;
      case 3: /// Prefijos        
        output_file << new_sequence.prefixes() << std::endl;
        break;
      case 4: /// Sufijos        
        output_file << new_sequence.suffixes() << std::endl;
        break;
      case 5: /// Subcadenas        
        output_file << new_sequence.substrings() << std::endl;
        break;
    }
  } 
  std::cout << "Fichero de salida modificado." << std::endl;
}