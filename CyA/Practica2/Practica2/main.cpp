#include "Alphabet.h"
#include "Alphabet.cpp"
#include "Chain.h"
#include "Chain.cpp"
#include "Symbols.h"
#include <iostream>
#include <fstream>
#include <sstream>

const std::string HelpText = "Uso: ./p01_strings filein.txt fileout.txt opcode \n Opcodes válidos: \n\
        1: Longitud \n\
        2: Inversa \n\
        3: Prefijos \n\
        4: Sufijos \n\
        5: Subcadenas";

void Error() {
  std::cout << "No ha introducido parámetros." << std::endl;
  std::cout << "Pruebe --help para más información." << std::endl;
  exit(1);
}

/** @brief Muestra el modo de uso correcto del programa
 *         En caso de que el uso no sea el correcto finaliza la ejecución del programa.
 *  @param[in] argc Número de parámetros.
 *  @param[in] argv Vector con los parámetros.
 */
void Usage(int argc, char* argv[]) {
  if (argc > 4) {
    std::cout << argv[0] << ": Ha introducido más de tres parámetros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información." << std::endl;
    exit(1);
  }
  std::string parameter{argv[1]};
  if (parameter == "--help") {
    std::cout << HelpText << std::endl;
    exit(1);
  }
  if (argc != 4) {
    std::cout << argv[0] << ": Faltan parámetros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información." << std::endl;
    exit(1);
  }
  if ((argc == 4) & ((std::stoi(argv[3]) > 5) | (std::stoi(argv[3]) < 0))) {
    std::cout << "Ha introducido un opcode incorrecto." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información." << std::endl;
    exit(1);
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
    exit(1);
  }
  /// Leemos el fichero de entrada línea a línea
  std::string line;
  std::ofstream output_file{kOutputFileName};
  std::cout << "Realizando la opción " << kOpcode << " sobre el fichero de entrada." << std::endl;
  while (getline(input_file, line)) {
    Sequence new_sequence = line;
    
    switch (kOpcode) {
      case 1: /// Alfabeto
        output_file << new_sequence.getAlphabet() << std::endl;
        break;
      case 2: /// Longitud         
        output_file << new_sequence.length() << std::endl;
        break;
      case 3: /// Inversa        
        output_file << new_sequence.reverse() << std::endl;
        break;
      case 4: /// Prefijos        
        output_file << new_sequence.prefixes() << std::endl;
        break;
      case 5: /// Sufijos        
        output_file << new_sequence.suffixes() << std::endl;
        break;
      default:
        break;
    }
  } 
  std::cout << "Fichero de salida modificado." << std::endl;
}

int main(int argc, char* argv[]) {
  /// Comprobamos los parámetros
  if (argc == 1) {
    Error();
  }
  Usage(argc, argv);
  /// Preparamos los argumentos
  std::string kInputFileName = argv[1]; //lectura archivo entrada
  std::string kOutputFileName = argv[2]; //lectura archivo de salida
  std::string opcode = argv[3]; //lectura de funcion a realizar
  /// Pasamos de cadena a número el opcode
  const int kOpcode = std::stoi(opcode);
  /// Pasamos los valores a la función que realiza las opciones
  Options(kInputFileName, kOutputFileName, kOpcode);
  return 0;
}

