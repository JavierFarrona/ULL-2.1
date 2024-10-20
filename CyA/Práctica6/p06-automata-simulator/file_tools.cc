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
* Archivo: file_tools.cc
* Referencias: 
*     Enunciado de la práctica
* Historial de revisiones
*     16 Oct 2024 - Creación (primera versión) del código
*/



#include <iostream>
#include <string>
#include <fstream>
#include <sstream> // stringstream

#include "NFA.cc"

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
 *  @brief Convierte una línea del fichero en alfabeto
 *  @param[in] line
 *  @return El alfabeto creado
 */
Alphabet line_to_alphabet(std::string& line) {
  Alphabet alphabet;
  for (const auto& elem : line) {
    if (elem != ' ') alphabet.add(elem);
  }
  return alphabet;
}

/** 
 *  @brief Convierte una línea del fichero en transiciones
 *  @param[in] line
 *  @param[out] transitions
 *  @return void
 */
void line_to_transitions(std::string& line, std::vector<Transition>& transitions) {
  std::string elem;
  std::stringstream new_line(line);
  /// Necesitamos el id
  getline(new_line, elem, ' ');
  unsigned int id = stoi(elem);
  /// No necesitamos si es de aceptación o no
  getline(new_line, elem, ' ');
  /// Extraemos el número de transiciones
  getline(new_line, elem, ' ');
  unsigned int num = stoi(elem);
  for (int i = 0; i < int(num); ++i) {
    /// Símbolo 
    getline(new_line, elem, ' ');
    Symbol symbol = elem;
    /// Estado origen 
    getline(new_line, elem, ' ');
    Transition transition(symbol, id, stoi(elem));
    transitions.push_back(transition);
  }
}

/** 
 *  @brief Convierte una línea del fichero en estado
 *  @param[in] line
 *  @return El estado creado
 */
State line_to_state(std::string& line) {
  State state;
  std::string elem;
  std::stringstream new_line(line);
  /// Extraemos el id
  getline(new_line, elem, ' ');
  state.setID(stoi(elem));
  /// Extraemos si es de aceptacion
  getline(new_line, elem, ' ');
  state.setFinal(stoi(elem) == 1);
  return state;
}

/** 
 *  @brief Muestra el mensaje de error de formato
 *  @return void, pero termina el programa
 */
void error_formato() {
  std::cout << "El fichero de especificacion no tiene el formato correcto." << std::endl;
  std::cout << "Use la opcion --help para mas informacion." << std::endl;
  exit(EXIT_SUCCESS);
}

/** 
 *  @brief Pasa de un fichero .fa a NFA
 *  @param[in] file_name
 *  @return El NFA creado
 */
NFA FileToNFA(std::string& file_name) {
  std::ifstream input_file{file_name, std::ios_base::in};
  std::string line;
  /// Comprobamos que tiene al menos las 2 líneas obligatorias 
  int num_lines = count_lines(file_name);
  if (num_lines < 2) error_formato();
  /// Extraemos el alfabeto
  getline(input_file, line);
  Alphabet alphabet(line_to_alphabet(line));
  /// Extraemos el número de estados
  getline(input_file, line);
  int num_states = stoi(line);
  /// Comprobamos que, si tiene al menos un estado, están definidos
  if (num_lines != num_states + 3)  error_formato();
  /// Extraemos el estado inicial
  getline(input_file, line);
  int initial_state = stoi(line);
  State initial;
  /// Extraemos los estados y las transiciones
  std::set<State> states;
  std::set<State> finals;
  std::vector<Transition> transitions;
  while (getline(input_file, line)) {
    State state(line_to_state(line));
    line_to_transitions(line, transitions);
    states.insert(state);
    if (state.getFinal()) finals.insert(state);
    if (int(state.getID()) == initial_state) initial = state;
  }
  /// Creamos el NFA
  NFA nfa;
  nfa.setAlphabet(alphabet);
  nfa.setStates(states);
  nfa.setNum(num_states);
  nfa.setInitial(initial);
  nfa.setFinals(finals);
  nfa.setTransitions(transitions);
  return nfa;
}

/** 
 *  @brief Pasa de un fichero .fa a NFA
 *  @param[in] kStringsFileName Fichero de cadenas
 *  @param[in] nfa
 *  @return void
 */
void CheckStrings(std::string& kStringsFileName, NFA& nfa) {
  std::ifstream input_file{kStringsFileName};
  std::string line;
  
  if (!input_file.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo " << kStringsFileName << std::endl;
    return;
  }

  while (getline(input_file, line)) {
    // Imprimimos la línea para ver qué contiene
    if (!line.empty()) {
      Sequence sequence{line};
      std::cout << sequence << " --- ";
      // Comprobamos si la secuencia es aceptada
      if (nfa.accepted(sequence)) {
        std::cout << "Accepted" << std::endl;
      } else {
        std::cout << "Rejected" << std::endl;
      }
    } else {
      std::cout << "[línea vacía]" << std::endl;
    }
  }
}

