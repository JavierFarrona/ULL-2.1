#include <iostream>
#include <string>
#include <set>
#include "language.cc"

int main() {
  Language language1;
  {
    /// Creamos un alfabeto
    std::string string1 = "01";
    Alphabet alphabet1 = string1;
    /// Se lo añadimos al lenguaje
    language1.addAlphabet(alphabet1);
    /// Creamos cadenas con ese lenguaje
    Sequence sequence1;
    sequence1.add_symbol('0');
    Sequence sequence2;
    sequence2.add_symbol('1');
    language1.addSequence(sequence1);
    language1.addSequence(sequence2);
    /// Mostramos los resultados
    std::cout << "Primer lenguaje: " << language1.getLanguageString() << std::endl;

  }
  std::cout << "Potencia 0: ";
  Language pot = Potencia(language1, 0);
  std::cout << pot.getAlphabet() << " ";
  std::cout << pot.getLanguageString() << std::endl;

  std::cout << "Potencia 1: ";
  pot = Potencia(language1, 1);
  std::cout << pot.getAlphabet() << " ";
  std::cout << pot.getLanguageString() << std::endl;

  std::cout << "Potencia 2: ";
  pot = Potencia(language1, 2);
  std::cout << pot.getAlphabet() << " ";
  std::cout << pot.getLanguageString() << std::endl;
  return 0;
}