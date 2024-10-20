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
* Archivo: main_tools.cc
* Referencias: 
*     Enunciado de la práctica
* Historial de revisiones
*     16 Oct 2024 - Creación (primera versión) del código
*/



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> /// Exit

const std::string kHelpText = "Modo de empleo: ./p06_automata_simulator input.fa input.txt \n\
  Pruebe 'p06_automata_simulator --help' para mas informacion. \n\
      (input.fa) \n\
          Automata finito definido de la siguiente forma: \n\
              Linea 1: Simbolos del alfabeto separados por espacios. \n\
              Linea 2: Numero total de estados del automata. \n\
              Linea 3: Estado de arranque. \n\
              El resto de lineas contendran los detalles de cada estado. \n\
      (input.txt) \n\
          Cadenas para probar en el automata.";

/**
 * @brief Muestra un mensaje de error en caso de que no se introduzcan parámetros.
 * @param[in] argv0 Nombre del programa.
 */
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