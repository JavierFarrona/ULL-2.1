/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 3
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 29 Sep 2022
 * @brief Archivo: calculator_tools.cc
 *        Funciones para facilitar al main_tools
 *        Se encarga de extraer los lenguajes y de operar
 * 
 * @details 
 *    29/09/2022 - Creación del fichero
 *    02/10/2022 - Usage y Option
 *    09/10/2022 - Adaptar a la práctica 2
 *    10/10/2022 - Añadidas las llamadas
 *    11/10/2022 - Añadidos los casos especiales
 *    16/10/2022 - Adaptar a la práctica 3
 *    16/10/2022 - Añadido el lector de formato
 *    16/10/2022 - Función que opera
 */


#include <iostream>
#include <string>
#include <utility> /// Pair
#include <cstdlib> /// Exit
#include <stack>

#include "language.cc"

/** 
 *  @brief Pasa de string a secuencia
 *  @param[in] str_sequence
 *  @return Secuencia
 */
Sequence StringToSequence(std::string& str_sequence) {
  Sequence sequence;
  for (const auto& elem : str_sequence) {
    sequence.add_symbol(elem);
  }
  return sequence;
}

/** 
 *  @brief Añade un nuevo lenguage al diccionario
 *  @param[out] languages
 *  @param[in] language_line
 *  @return (void)
 */
void AddLanguage(std::vector<std::pair<std::string, Language>>& languages, std::string& language_line) {
  /// Extraemos el nombre (key)
  std::string language_name;
  for (const auto& elem : language_line) {
    if (elem == SPACE) { break; }
    else language_name += elem;
  }
  /// Extraemos las secuencias y el alfabeto (value)
  std::string str_sequence;
  Alphabet alphabet;
  Language language;
  for (int i = language_line.find_first_of("{") + 1; i <= int(language_line.find_first_of("}")); ++i) {
    if (language_line[i] == ',' or language_line[i] == '}') {
      Sequence sequence = StringToSequence(str_sequence);
      if (str_sequence != "") language.addSequence(sequence);
      str_sequence.clear();
      ++i; /// Nos saltamos el espacio
    } else {
      str_sequence += language_line[i];
      if (language_line[i] != '&') alphabet.add(language_line[i]);
    }
  }
  language.addAlphabet(alphabet);
  /// Añadimos el nuevo elemento al diccionario
  std::pair<std::string, Language> new_elem;
  new_elem.first = language_name;
  new_elem.second = language;
  languages.push_back(new_elem);
}

/** 
 *  @brief Comprueba si es una de las operaciones
 *  @param[in] elem
 *  @return True si lo es, false si no
 */
bool is_operation(const char elem) {
  return (elem == '+' || elem == '|' || elem == '^' || elem == '-' || elem == '!');
}

/** 
 *  @brief Busca el lenguaje con ese nombre
 *  @param[in] languages
 *  @param[in] language_name
 *  @return Lenguaje con ese nombre
 */
Language extract_language(std::vector<std::pair<std::string, Language>>& languages, std::string& language_name) {
  for (const auto& elem : languages) {
    if (elem.first == language_name) return elem.second;
  }
  std::cout << "No se ha encontrado ese lenguaje para operar." << std::endl;
  exit(EXIT_SUCCESS);
  return Language();
}

/** 
 *  @brief Busca el nombre de ese lenguaje
 *  @param[in] languages
 *  @param[in] language
 *  @return String del nombre
 */
std::string extract_name(std::vector<std::pair<std::string, Language>>& languages, Language& language) {
  for (const auto& elem : languages) {
    if (elem.second == language) return elem.first;
  }
  return std::string();
}

/// Esta función es para hacer pruebas (se puede ignorar)
void Test(std::vector<std::pair<std::string, Language>>& languages) {
  std::cout << "Esto es para debuguear" << std::endl;
  for (const auto& elem : languages) {
    std::cout << elem.first << SPACE << elem.second << std::endl;
  }
}

/** 
 *  @brief Comprueba si una string es un número
 *  @param[in] string
 *  @return True si es número, false si no
 */
bool is_number(const std::string& string) {
  std::string::const_iterator it = string.begin();
  while (it != string.end() && std::isdigit(*it)) ++it;
  return !string.empty() && it == string.end();
}

/** 
 *  @brief Realiza las operaciones (mostrando resultados)
 *  @param[in] languages
 *  @param[in] operation_line
 *  @return (void)
 */
void Calculator(std::vector<std::pair<std::string, Language>>& languages, std::string& operation_line) {
  // Test(languages);
  std::stack<Language> stack;
  std::string aux_string;
  for (const auto& elem : operation_line) {
    /// Si encontramos un operador, operamos 
    if (is_operation(elem)) {
      std::cout << "Realizando operacion ";
      Language second_language = stack.top();
      stack.pop();
      Language first_language;
      switch(elem) {
        case '+':
          first_language = stack.top();
          stack.pop();
          std::cout << "concatenacion: ";
          std::cout << first_language.getLanguageString() << " + " << second_language.getLanguageString() << std::endl;
          std::cout << "Metiendo en la pila " << (second_language + first_language) << std::endl;
          stack.push(second_language + first_language);
          break;
        case '|':
          first_language = stack.top();
          stack.pop();
          std::cout << "union: ";
          std::cout << first_language.getLanguageString() << " | " << second_language.getLanguageString() << std::endl;
          std::cout << "Metiendo en la pila " << (second_language | first_language) << std::endl;
          stack.push(second_language | first_language);
          break;
        case '^':
          first_language = stack.top();
          stack.pop();        
          std::cout << "interseccion: ";
          std::cout << first_language.getLanguageString() << " ^ " << second_language.getLanguageString() << std::endl;
          std::cout << "Metiendo en la pila " << (second_language ^ first_language) << std::endl;
          stack.push(second_language ^ first_language);
          break;
        case '-':
          first_language = stack.top();
          stack.pop();
          std::cout << "diferencia: ";
          std::cout << first_language.getLanguageString() << " - " << second_language.getLanguageString() << std::endl;
          std::cout << "Metiendo en la pila " << (second_language - first_language) << std::endl;
          stack.push(second_language - first_language);
          break;
        case '!':
          std::cout << "inversa: ";
          std::cout << "!" << second_language.getLanguageString() << std::endl;
          std::cout << "Metiendo en la pila " << (!second_language) << std::endl;
          stack.push(!second_language);
          break;
      }
    /// El caso de la potencia lo hacemos por separado
    } else if (is_number(aux_string)) {
      int potencia = std::stoi(aux_string);
      aux_string.clear();
      Language language = stack.top();
      stack.pop();
      std::cout << "Realizando operacion potencia: ";
      std::cout << language.getLanguageString() << " * " << potencia << std::endl;
      std::cout << "Metiendo en la pila " << (language * potencia) << std::endl;
      stack.push(language * potencia);
    /// Si no, estamos ante un lenguaje
    } else {
      if (elem == SPACE) {
        /// Tenemos que añadir un nuevo elemento a la pila
        if (aux_string != "" and aux_string != "*") { 
          std::cout << "Metiendo en la pila " << aux_string << std::endl;
          stack.push(extract_language(languages, aux_string)); 
          aux_string.clear();
          }
      } else {
        aux_string += elem;
      }
    }
  }
  std::cout << "====== Resultado: " << stack.top() << std::endl << std::endl;
}