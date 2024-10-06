/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 2
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
#include <cstdlib> /// Exit

#include "file_tools.cc"

const std::string kHelpText = "Uso: ./ p02_languages filein1 . txt filein2 . txt fileout . txt opcode \n\
        Opcodes validos: \n\
          1: Concatenacion \n\
          2: Union \n\
          3: Interseccion \n\
          4: Diferencia \n\
          5: Inversa \n\
          6: Potencia";

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
  if (argc > 5) {
    std::cout << argv[0] << ": Ha introducido mas de tres parametros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parameter{argv[1]};
  if (parameter == "--help") {
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc != 5) {
    std::cout << argv[0] << ": Faltan parametros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
  if ((argc == 5) and (std::stoi(argv[4]) > 6 or std::stoi(argv[4]) < 0)) {
    std::cout << "Ha introducido un opcode incorrecto." << std::endl;
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
 *  @brief Cuenta las líneas de un fichero
 *  @param[in] file
 *  @return Número de líneas del fichero
 */
int count_lines(std::string& file) {
  std::ifstream input_file{file, std::ios_base::in};
  std::string line;
  int num_lines = 0;
  while (getline(input_file, line)) {
    ++num_lines;
  }
  return num_lines;
}

/** 
 *  @brief Comprueba si dos ficheros tienen el mismo número de líneas
 *  @param[in] kFirstInputFileName
 *  @param[in] kSecondInputFileName
 *  @return (void) Pero termina el programa si lo tienen
 */
void same_length(std::string& kFirstInputFileName, std::string& kSecondInputFileName) {
  if (count_lines(kFirstInputFileName) != count_lines(kSecondInputFileName)) {
    std::cout << "No se puede realizar la opcion marcada." << std::endl;
    std::cout << "ERROR: Los archivos no tienen el mismo numero de lineas." << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/** 
 *  @brief Realiza la opción marcada en el opcode
 *  @param[in] kFirstInputFileName
 *  @param[in] kSecondInputFileName
 *  @param[in] kOutputFileName
 *  @param[in] kOpcode
 */
void Options(std::string& kFirstInputFileName, std::string& kSecondInputFileName, std::string& kOutputFileName, int kOpcode) {
  /// Comprobamos que existen los ficheros de entrada
  FileExist(kFirstInputFileName);
  FileExist(kSecondInputFileName);
  /// Comprobamos su formato
  formato(kFirstInputFileName); 
  formato(kSecondInputFileName);
  /// Abrimos los ficheros
  std::ifstream first_input_file{kFirstInputFileName, std::ios_base::in};
  std::ifstream second_input_file{kSecondInputFileName, std::ios_base::in};
  std::ofstream output_file{kOutputFileName};
  std::string first_line, second_line;
  Language result;
  /// Valor de la potencia
  int potencia;
  if (kOpcode == 6) {
    std::cout << "Potencia: ";
    std::cin >> potencia;
  }
  /// Elegimos la opción seleccionada
  while (getline(first_input_file, first_line) and getline(second_input_file, second_line)) {
    switch (kOpcode) {
      case 1: /// Concatenación
        /// Comprobamos que tienen el mismo número de líneas
        same_length(kFirstInputFileName, kSecondInputFileName);
        result = ConcatenacionCall(first_line, second_line);  
        break;
      case 2: /// Unión 
        /// Comprobamos que tienen el mismo número de líneas
        same_length(kFirstInputFileName, kSecondInputFileName);       
        result = UnionCall(first_line, second_line);
        break;
      case 3: /// Intersección 
        /// Comprobamos que tienen el mismo número de líneas
        same_length(kFirstInputFileName, kSecondInputFileName);
        result = InterseccionCall(first_line, second_line);
        break;
      case 4: /// Diferencia  
        /// Comprobamos que tienen el mismo número de líneas
        same_length(kFirstInputFileName, kSecondInputFileName); 
        result = DiferenciaCall(first_line, second_line);
        break;
      case 5: /// Inversa        
        result = InversaCall(first_line);
        break;
      case 6: /// Potencia       
        result = PotenciaCall(first_line, potencia);
        break;
    } 
    output_file << result.getAlphabet() << SPACE;
    output_file << result.getLanguageString() << "\n";     
  }
  std::cout << "Fichero de salida modificado." << std::endl;
}
