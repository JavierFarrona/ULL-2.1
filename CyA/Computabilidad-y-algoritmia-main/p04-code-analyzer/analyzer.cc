/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 4
 *
 * @author Javier Farrona Cabrera (alu0101541983@ull.edu.es)
 * @date 22 Oct 2022
 * @brief Archivo: analyzer.cc
 *        Implementación de la clase "analyzer"
 * 
 * @details 
 *    22/10/2022 - Creación del fichero
 *    23/10/2022 - Añadido el constructor
 *    23/10/2022 - Añadidos los analizadores
 *    23/10/2022 - Añadida la función See()
 *    23/10/2022 - Añadida la sobrecarga <<
 */

#include "analyzer.h"

const std::regex kComment("//.*");
const std::regex kLongCommentStart("/\\*.*");
const std::regex kLongCommentEnd(".*\\*/");
const std::regex kMain("int main");
const std::regex kStatement("(for|while)\\s*?(.+)");
// const std::regex kStatement("(for|while|if|return|switch)\\s*?(.+)");
const std::regex kVariable("\\s+?(int|double).*");
// const std::regex kVariable("\\s+?(int|double|float|auto|string).*");
const std::regex kAsignacion("\\s+?[^(){}\\s][a-zA-Z0-9_-]+\\s=\\s.*");

/// @brief Modificación
/// @param input_file 
/// @param line 
void Analyzer::AsigAnalyzer(std::ifstream& input_file, std::string& line) {
  if (regex_search(line, kAsignacion)) {
    std::string aux_string = line;
    int found = aux_string.find_first_not_of(" ");
    aux_string = aux_string.substr(found);
    if(!regex_search(line, kVariable)) {
      asigns_.push_back(aux_string);
      line_assigns_.push_back(lines_.size());
    }
  }
}

/** 
 *  @brief Auxiliar para el constructor (busca comentarios)
 *  @param[in] input_file
 *  @param[out] line
 */
void Analyzer::CommentAnalyzer(std::ifstream& input_file, std::string& line) {
  lines_.push_back(line);
  /// Buscamos comentarios de una línea
  if (regex_search(line, kComment)) {
    counter_.add_normal_comment();
    int found = line.find_first_of("//");
    Comment comment(lines_.size(), line.substr(found));
    comments_.push_back(comment);
  /// Buscamos comentarios de varias líneas
  } else if (regex_search(line, kLongCommentStart)) {
    counter_.add_multi_comment();
    std::string aux_string; /// Para ir guardando
    int start = lines_.size();
    /// Buscamos el final de los comentarios
    while (!regex_search(line, kLongCommentEnd)) {
      aux_string += "\n" + line;
      getline(input_file, line);
      lines_.push_back(line);
    }
    aux_string += "\n" + line; /// Añadimos la última
    int found = aux_string.find("/*");
    aux_string = aux_string.substr(found);
    found = line.find("*/");
    Comment comment(start, lines_.size(), aux_string);
    comments_.push_back(comment);
    if (start == 1) description_ = comment;
  }
}

/** 
 *  @brief Auxiliar para el constructor (busca bucles)
 *  @param[in] input_file
 *  @param[out] line
 */
void Analyzer::StatementAnalyzer(std::ifstream& input_file, std::string& line) {
  if (regex_search(line, kStatement)) {
    if (regex_search(line, kDouble)) counter_.add_double();
    if (regex_search(line, kFor)) counter_.add_for();
    Statement statement(lines_.size(), line);
    statements_.push_back(statement);
  }
}

/** 
 *  @brief Auxiliar para el constructor (busca el main)
 *  @param[in] input_file
 *  @param[out] line
 */
void Analyzer::MainAnalyzer(std::ifstream& input_file, std::string& line) {
  if (regex_search(line, kMain)) {
    main_ = true;
    main_line_ = lines_.size();
  }
}

/** 
 *  @brief Auxiliar para el constructor (busca variables)
 *  @param[in] input_file
 *  @param[out] line
 */
void Analyzer::VariableAnalyzer(std::ifstream& input_file, std::string& line) {
  if (regex_search(line, kVariable)) {
    if (regex_search(line, kInt)) counter_.add_int();
    if (regex_search(line, kDouble)) counter_.add_double();
    Variable variable(lines_.size(), line);
    variables_.push_back(variable);
  }
}

/** 
 *  @brief Constructor del analizador
 *  @param[in] text
 */
Analyzer::Analyzer(std::string& name_of_file) {
  /// Abrimos el archivo
  std::ifstream input_file{name_of_file, std::ios_base::in};
  name_of_file_ = name_of_file;
  std::string line;
  /// Preparamos valores por defecto
  main_ = false;
  description_ = Comment(0, "Not found.");
  /// Empezamos a recorrer el documentos
  while (getline(input_file, line)) {
    CommentAnalyzer(input_file, line);
    StatementAnalyzer(input_file, line);
    MainAnalyzer(input_file, line);
    VariableAnalyzer(input_file, line);
    AsigAnalyzer(input_file, line);
  }
}

/** 
 *  @brief Auxiliar para depurar (y para guardar)
 *         Muestra los resultados de la siguiente forma:
 * 
 *         PROGRAM: name
 *         DESCRIPTION: description comment
 * 
 *         VARIABLES:
 *         [Line x] INT: value
 *         [Line x] DOUBLE: value
 * 
 *         STATEMENTS:
 *         [Line x] LOOP: type
 *         [Line x] LOOP: type
 *        
 *         MAIN:
 *         true/false
 * 
 *         COMMENTS:
 *         [Line x] DESCRIPTION
 *         [Line x] comment
 */
void Analyzer::See() const {
  std::cout << "PROGRAM: " << name_of_file_ << "\n";
  std::cout << "DESCRIPTION: " << "\n" << description_.get_text() << std::endl;
  std::cout << std::endl;

  std::cout << "VARIABLES: " << std::endl;
  for (const auto& elem : variables_) std::cout << elem << std::endl;
  std::cout << std::endl;

  std::cout << "STATEMENTS: " << std::endl;
  for (const auto& elem : statements_) std::cout << elem << std::endl;
  std::cout << std::endl;

  std::cout << "MAIN: ";
  if (main_) std::cout << "true" << std::endl;
  else std::cout << "false" << std::endl;
  std::cout << "Line: " << main_line_ << std::endl;
  std::cout << std::endl;

  std::cout << "COMMENTS: " << std::endl;
  for (const auto& elem : comments_) {
    if (elem.get_text() == description_.get_text()) {
      std::cout << description_.get_lines() << " DESCRIPTION" << std::endl;
    } else {
      std::cout << elem << std::endl;
    }
  }

  std::cout << std::endl;
  std::cout << "COUNTER: " << std::endl;
  std::cout << "while: " << counter_.get_while_count() << std::endl;
  std::cout << "for: " << counter_.get_for_count() << std::endl;
  std::cout << "int: " << counter_.get_int_count() << std::endl;
  std::cout << "double: " << counter_.get_double_count() << std::endl;

}

/** 
 *  @brief Guarda el análisis realizado
 *         Usa el mismo formato que See()
 *  @param[in] name_of_file
 */
void Analyzer::Store(const std::string& name_of_file) {
  std::ofstream output_file{name_of_file};
  output_file << "PROGRAM: " << name_of_file_ << "\n";
  output_file << "DESCRIPTION: " << "\n" << description_.get_text() << std::endl;
  output_file << std::endl;

  output_file << "VARIABLES: " << std::endl;
  for (const auto& elem : variables_) output_file << elem << std::endl;
  output_file << std::endl;

  /// Modificación
  output_file << "ASIGNACIONES: " << std::endl;
  for (int i = 0; i < int(asigns_.size()); ++i) {
    output_file << "[LINE " << line_assigns_[i] << " ] ";
    output_file << asigns_[i] << std::endl;
  }
  output_file << std::endl;

  output_file << "STATEMENTS: " << std::endl;
  for (const auto& elem : statements_) output_file << elem << std::endl;
  output_file << std::endl;

  output_file << "MAIN: ";
  if (main_) output_file << "true" << std::endl;
  else output_file << "false" << std::endl;
  output_file << "Line: " << main_line_ << std::endl;
  output_file << std::endl;

  output_file << "COMMENTS: " << std::endl;
  for (const auto& elem : comments_) {
    if (elem.get_text() == description_.get_text()) {
      output_file << description_.get_lines() << " DESCRIPTION" << std::endl;
    } else {
      output_file << elem << std::endl;
    }
  } 

  output_file << std::endl;
  output_file << "COUNTER: " << std::endl;
  output_file << "while: " << counter_.get_while_count() << std::endl;
  output_file << "for: " << counter_.get_for_count() << std::endl;
  output_file << "int: " << counter_.get_int_count() << std::endl;
  output_file << "double: " << counter_.get_double_count() << std::endl;

  std::cout << "Fichero de salida modificado." << std::endl;
}