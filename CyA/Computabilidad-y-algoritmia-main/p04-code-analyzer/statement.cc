/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 4
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 22 Oct 2022
 * @brief Archivo: statement.cc
 *        Implementación de la clase "statement"
 * 
 * @details 
 *    22/10/2022 - Creación del fichero
 *    22/10/2022 - Añadido el constructor
 *    22/10/2022 - Añadido el getter
 *    22/10/2022 - Añadida la sobrecarga <<
 */

#include "statement.h"

const std::regex kFor("for\\s*?(.+)");
const std::regex kWhile("while\\s*?(.+)");
const std::regex kIf("if\\s*?(.+)"); /// (No se pide)
const std::regex kReturn("return\\s*?(.+)"); /// (No se pide)
const std::regex kSwitch("switch\\s*?(.+)"); /// (No se pide)
const std::regex kInclude("#include\\s*?(.+)"); /// (No se pide)

/** 
 *  @brief Constructor con parámetros
 *  @param[in] line
 *  @param[in] text
 */
Statement::Statement(const int line, const std::string& text) {
  line_ = line;
  if (regex_search(text, kFor)) { type_ = "for"; }
  else if (regex_search(text, kWhile)) { type_ = "while"; }
  else if (regex_search(text, kIf)) { type_ = "if"; }
  else if (regex_search(text, kReturn)) { type_ = "return"; }
  else if (regex_search(text, kSwitch)) { type_ = "switch"; }
  else if (regex_search(text, kInclude)) { type_ = "include"; }
  else { type_ = "undefined"; }
}

/** 
 *  @brief Getter del bucle
 *  @return String en formato: "[Line x] LOOP: type"
 */
std::string Statement::get_statement() const {
  if (type_ == "if") return "[Line " + std::to_string(line_) + "] IF";
  if (type_ == "return") return "[Line " + std::to_string(line_) + "] RETURN";
  if (type_ == "switch") return "[Line " + std::to_string(line_) + "] SWITCH";
  if (type_ == "include") return "[Line " + std::to_string(line_) + "] INCLUDE";
  return "[Line " + std::to_string(line_) + "] LOOP: " + type_;
}

/** 
 *  @brief Sobrecarga del operador de salida
 *  @param[out] out
 *  @param[in] statement
 */
std::ostream& operator<<(std::ostream& out, const Statement& statement) {
  out << statement.get_statement();
  return out;
}
