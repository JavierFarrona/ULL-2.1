/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 4
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 22 Oct 2022
 * @brief Archivo: analyzer.h
 *        Definición de la clase "analyzer"
 * 
 * @details 
 *    22/10/2022 - Creación del fichero
 *    22/10/2022 - Añadida la clase "analyzer"
 *    23/10/2022 - Añadidos los constructores
 *    23/10/2022 - Añadidas las funciones
 */

#ifndef ANALYZER_H
#define ANALYZER_H

#include <fstream>
#include <iostream>
#include <regex>
#include <vector>
#include "comment.cc"
#include "variable.cc"
#include "statement.cc"
#include "counter.cc"

/** 
 *  @brief Esta clase se usa para analizar un fichero
 *         Guarda los siguientes datos:
 *            - Si tiene main (main_)
 *            - La línea donde está el main (main_line_)
 *            - Vector de líneas del fichero (lines_)
 *            - Nombre del fichero (name_of_file_)
 *            - Cabecera de comentarios (description_)
 *            - Vector de variables (variables_)
 *            - Vector de bucles (loops_)
 *            - Vector de comentarios (comments_)
 */
class Analyzer {
 private:
  bool main_;
  int main_line_;
  std::vector<std::string> lines_;
  std::string name_of_file_;
  Comment description_;
  std::vector<Variable> variables_;
  std::vector<Statement> statements_;
  std::vector<Comment> comments_;
  Counter counter_;
  /// Modificación
  std::vector<std::string> asigns_;
  std::vector<int> line_assigns_;

 public:
  /// Constructor (a partir del fichero de entrada)
  Analyzer(std::string& name_of_file);
  /// Auxiliares del constructor
  void CommentAnalyzer(std::ifstream& input_file, std::string& line);
  void StatementAnalyzer(std::ifstream& input_file, std::string& line);
  void MainAnalyzer(std::ifstream& input_file, std::string& line);
  void VariableAnalyzer(std::ifstream& input_file, std::string& line);
  void AsigAnalyzer(std::ifstream& input_file, std::string& line);

  /// Funciones
  std::string get_variables() const;
  std::string get_statements() const;
  std::string get_comments() const;
  void Store(const std::string& name_of_file);
  void See() const;
  
};

#endif
