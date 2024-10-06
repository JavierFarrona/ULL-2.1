/// Programa para probar la clase "loop"

#include <iostream>
#include <string>
#include "../statement.cc"

int main() {
  std::string text = "for (const auto &element: array) {\n \
  std::cout << element << ' ';\n \
  }";
  int line = 3;
  Statement new_loop{line, text};
  // std::cout << new_loop << std::endl;
  std::string other_text = "while (number_of_iterations > 0) {\n \
  std::cout << number_of_iterations << \", \";\n \
  --number_of_iterations;\n \
  }";
  Statement other_loop{line, other_text};
  std::cout << other_loop << std::endl;
  std::string include = "#include <iostream>"; // (No funciona)
  Statement include_st{line, other_text};
  std::cout << include_st << std::endl;
  return 0; 
}