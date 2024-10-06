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
 *        Funciones para facilitar la lectura y el tratamiento de archivos
 * 
 * @details 
 *    29/09/2022 - Creación del fichero
 *    02/10/2022 - Usage y Option
 *    09/10/2022 - Adaptar a la nueva práctica
 *    10/10/2022 - Añadidas las llamadas
 *    11/10/2022 - Añadidos los casos especiales
 */

#include <iostream>
#include <string>
#include <cstdlib> /// Exit
#include <fstream>
#include <set>
#include <utility> /// Pair

#include "language.cc"

typedef std::pair<Language, Language> pair_languages;
const std::string EMPTY_SEQUENCE = "&";

/** 
 *  @brief Comprueba el formato de las líneas del fichero
 *  @param[in] file 
 */
void formato(const std::string& file) {
  std::ifstream input_file{file, std::ios_base::in};
  std::string line;
  while (getline(input_file, line)) {
    int open = 0;
    int close = 0;
    /// Buscamos los corchetes
    for (const auto& elem : line) {
      if (elem == '{') ++open;
      if (elem == '}') ++close;
    }
    /// Si no hemos encontrado dos de cada, el formato no es correcto
    if (open != 2 or close != 2) {
      std::cout << "El formato del archivo de entrada no es correcto." << std::endl;
      std::cout << "El formato adecuado es el siguiente: " << std::endl;
      std::cout << "{ alfabeto } { cadenas }" << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
}

/** 
 *  @brief Extrae el alfabeto de una línea
 *  @param[in] line
 *  @return Alfabeto ya formado 
 */
Alphabet ExtractAlphabet(const std::string& line) {
  int first_space = line.find_first_of(SPACE);
  int first_close = line.find_first_of('}');
  std::string auxiliar;
  Alphabet alphabet;
  for (int i = first_space + 1; i < first_close; ++i) {
    if (line[i] ==  SPACE) {
      alphabet.add(auxiliar);
      auxiliar.clear();
    } else {
      auxiliar += line[i];
    }
  }
  return alphabet;
}

/** 
 *  @brief Convierte a secuencia una string (usando un alfabeto)
 *  @param[in] string
 *  @param[in] alphabet
 *  @return Secuencia (aunque termina el programa si la secuecia no se forma con el alfabeto) 
 */
Sequence StringToSequence(const std::string& string, const Alphabet alphabet) {
  Sequence sequence;
  /// Primero comprobamos si es la vacía
  if (string == EMPTY_SEQUENCE) {
    sequence.add_symbol(EMPTY_SEQUENCE);
    return sequence;
  }
  /// Si no, ya vamos separando y añadiendo 
  std::string aux_string;
  for (const auto& elem : string) {
    aux_string += elem;
    if (alphabet.find(aux_string)) {
      sequence.add_symbol(aux_string);
      aux_string.erase();
    }
  }
  /// Comprobamos que la secuencia se ha formado con el alfabeto
  if (aux_string != "") {
    std::cout << "Cadena incorrecta. Revise el fichero de entrada." << std::endl;
    exit(EXIT_SUCCESS); 
  }
  return sequence;
}

/** 
 *  @brief Extrae las secuencias de una línea 
 *  @param[in] line
 *  @return Set de secuencias 
 */
std::set<Sequence> ExtractSecuences(const std::string& line, const Alphabet alphabet) {
  std::set<Sequence> sequences;
  int last_close = line.find_last_of('}');
  int last_open = line.find_last_of('{');
  /// Extraemos primero el string
  std::string sequence_str;
  for (int i = last_open + 2; i < last_close; ++i) {
    if (line[i] == SPACE) {
      sequences.insert(StringToSequence(sequence_str, alphabet));
      sequence_str.erase();
    } else {
      sequence_str += line[i];
    } 
  }
  return sequences;
}

/** 
 *  @brief Extrae los lenguajes de dos líneas
 *  @param[in] first_line
 *  @param[in] second_line
 *  @return Pair de lenguajes
 */
pair_languages ExtractLanguages(std::string& first_line, std::string& second_line) {
  pair_languages languages;
  Alphabet first_alphabet = ExtractAlphabet(first_line);
  Alphabet second_alphabet = ExtractAlphabet(second_line);
  /// Extraemos el primer lenguaje
  Language first_language;
  first_language.addAlphabet(first_alphabet);
  first_language.setSequences(ExtractSecuences(first_line, first_alphabet));
  /// Extraemos el segundo lenguaje
  Language second_language;
  second_language.addAlphabet(second_alphabet);
  second_language.setSequences(ExtractSecuences(second_line, second_alphabet));
  languages.first = first_language;
  languages.second = second_language;
  return languages;
}

/**
 *  @brief Llama a "Concatenación" de forma adecuada.
 *  @param[in] first_line 
 *  @param[in] second_line 
 *  @return Lenguaje con el resultado
 */
Language ConcatenacionCall(std::string& first_line, std::string& second_line) {
  pair_languages languages = ExtractLanguages(first_line, second_line);
  /// Calculamos el resultado de la operación
  Language result = Concatenacion(languages.first, languages.second);
  /// Lo escribimos en el fichero de salida
  return result;
}

/**
 *  @brief Llama a "Union" de forma adecuada.
 *  @param[in] first_line 
 *  @param[in] second_line 
 *  @return Lenguaje con el resultado
 */
Language UnionCall(std::string& first_line, std::string& second_line) {
  pair_languages languages = ExtractLanguages(first_line, second_line);
  /// Calculamos el resultado de la operación
  Language result = Union(languages.first, languages.second);
  /// Lo escribimos en el fichero de salida
  return result;
}

/**
 *  @brief Llama a "Interseccion" de forma adecuada.
 *  @param[in] first_line 
 *  @param[in] second_line 
 *  @return Lenguaje con el resultado
 */
Language InterseccionCall(std::string& first_line, std::string& second_line) { 
  pair_languages languages = ExtractLanguages(first_line, second_line);
  /// Calculamos el resultado de la operación
  Language result = Interseccion(languages.first, languages.second);
  /// Lo escribimos en el fichero de salida
  return result;
}

/**
 *  @brief Llama a "Diferencia" de forma adecuada.
 *  @param[in] first_line 
 *  @param[in] second_line 
 *  @return Lenguaje con el resultado
 */
Language DiferenciaCall(std::string& first_line, std::string& second_line) {
  pair_languages languages = ExtractLanguages(first_line, second_line);
  /// Calculamos el resultado de la operación
  Language result = Diferencia(languages.first, languages.second);
  /// Lo escribimos en el fichero de salida
  return result;
}

/**
 *  @brief Llama a "Inversa" de forma adecuada.
 *  @param[in] first_line 
 *  @return Lenguaje con el resultado
 */
Language InversaCall(std::string& first_line) {
  pair_languages languages = ExtractLanguages(first_line, first_line);
  /// Calculamos el resultado de la operación
  Language result = Inversa(languages.first);
  /// Lo escribimos en el fichero de salida
  return result;
}

/**
 *  @brief Llama a "Potencia" de forma adecuada.
 *  @param[in] first_line 
 *  @return Lenguaje con el resultado
 */
Language PotenciaCall(std::string& first_line, int potencia) {
  pair_languages languages = ExtractLanguages(first_line, first_line);
  /// Calculamos el resultado de la operación
  Language result = Potencia(languages.first, potencia);
  /// Lo escribimos en el fichero de salida
  return result;
}