#include <iostream>
#include <string>
#include <set>
#include "language.cc"

int main() {
  Language language1;
  {
    /// Creamos un alfabeto
    std::string string1 = "abc";
    Alphabet alphabet1 = string1;
    /// Se lo añadimos al lenguaje
    language1.addAlphabet(alphabet1);
    /// Creamos cadenas con ese lenguaje
    Sequence sequence1;
    sequence1.add_symbol('a');
    Sequence sequence2;
    sequence2.add_symbol('a');
    sequence2.add_symbol('b');
    sequence2.add_symbol('c');
    Sequence sequence3;
    sequence3.add_symbol('c');
    sequence3.add_symbol('b');
    sequence3.add_symbol('a');
    Sequence sequence4;
    sequence4.add_symbol('b');
    sequence4.add_symbol('b');
    sequence4.add_symbol('c');
    sequence4.add_symbol('c');
    
    language1.addSequence(sequence1);
    language1.addSequence(sequence2);
    language1.addSequence(sequence3);
    language1.addSequence(sequence4);
    /// Mostramos los resultados
    std::cout << "Primer lenguaje: " << language1.getLanguageString() << std::endl;

  }
  Language language2;
  {
    /// Creamos un alfabeto
    std::string string2 = "ad";
    Alphabet alphabet2 = string2;
    /// Se lo añadimos al lenguaje
    language2.addAlphabet(alphabet2);
    /// Creamos cadenas con ese lenguaje
    Sequence sequence5;
    sequence5.add_symbol('a');
    Sequence sequence6;
    sequence6.add_symbol('d');
    sequence6.add_symbol('d');
    Sequence sequence7;
    sequence7.add_symbol('d');
    sequence7.add_symbol('d');
    sequence7.add_symbol('d');
    
    language2.addSequence(sequence5);
    language2.addSequence(sequence6);
    language2.addSequence(sequence7);
    /// Mostramos los resultados
    std::cout << "Segundo lenguaje: " << language2.getLanguageString() << std::endl;
  }
  std::cout << "Inversa: " << std::endl;
  Language inv = Inversa(language1);
  std::cout << inv.getAlphabet() << std::endl;
  std::cout << inv.getLanguageString() << std::endl;
  return 0;
}