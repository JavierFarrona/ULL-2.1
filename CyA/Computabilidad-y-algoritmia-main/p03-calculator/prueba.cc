#include <iostream>
#include <string>
#include <vector>

#include "./src/language.h"
#include "./src/calculator_tools.cc"

int main() {
  std::string language_1 = "L1 = {0, 1, 01, 10}";
  std::string language_2 = "L2 = {&, 10, 11}";
  std::string language_3 = "L3 = {&}";
  std::string language_4 = "L4 = {}";
  std::vector<std::pair<std::string, Language>> languages;
  AddLanguage(languages, language_4);
  return 0;
}