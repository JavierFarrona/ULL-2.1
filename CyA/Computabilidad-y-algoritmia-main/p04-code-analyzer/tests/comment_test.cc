/// Programa para probar la clase "comment"

#include <iostream>
#include <string>
#include "../comment.cc"

int main() {
  std::string text = "/**\n \
  * Universidad de La Laguna\n \
  * Escuela Superior de Ingeniería y Tecnología\n \
  * Grado en Ingeniería Informática\n \
  * Computabilidad y Algoritmia\n \
  * Práctica 3\n \
  * \n \
  * @author Esther M. Quintero (alu0101434780@ull.edu.es)\n \
  * @date 29 Sep 2022\n \
  * @brief Archivo: symbol.cc\n \
  *        Implementación de la clase símbolo\n \
  * \n \
  * @details\n \
  *    29/09/2022 - Creación del fichero\n \
  *    30/09/2022 - Implementación de la sobrecarga de salida\n \
  *    08/10/2022 - Revisiones\n \
  *    09/10/2022 - Añadidas sobrecargas\n \
  */";
  // std::cout << text << std::endl;
  int start = 0, end = 17;
  Comment new_comment{start, end, text};
  std::cout << new_comment << std::endl;
  // std::cout << new_comment.get_lines() << std::endl;
  std::string one_line = "/// Blablabla bla bla";
  int line = 5;
  Comment other_comment{line, one_line};
  // std::cout << other_comment << std::endl;
  // std::cout << other_comment.get_lines() << std::endl;
  return 0;
}