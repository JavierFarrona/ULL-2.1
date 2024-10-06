/// Programa para probar la clase "comment"

#include <iostream>
#include <string>

#include "../analyzer.cc"

int main() {
  std::string file_name("file2.cc");
  Analyzer analyzer{file_name};
  analyzer.See();
  return 0;
}