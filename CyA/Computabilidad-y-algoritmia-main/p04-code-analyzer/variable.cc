/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 4
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 22 Oct 2022
 * @brief Archivo: variable.cc
 *        Implementación de la clase "variable"
 * 
 * @details 
 *    22/10/2022 - Creación del fichero
 *    22/10/2022 - Añadido el constructor
 *    22/10/2022 - Añadidos los getter
 *    22/10/2022 - Añadida la sobrecarga <<
 */

#include "variable.h"

const std::regex kInt("\\s*int.*");
const std::regex kDouble("\\s*double.*");
const std::regex kFloat("\\s*float.*"); /// (No se pide)
const std::regex kAuto("\\s*auto.*"); /// (No se pide)
const std::regex kString("\\s*(std::)?string.*"); /// (No se pide)
const std::regex kName("[*a-zA-Z0-9_-]+");
const std::regex kValue("-?[0-9.]+");
const std::string kSpace(" ");

/** 
 *  @brief Constructor con parámetros
 *  @param[in] line
 *  @param[in] text
 */
Variable::Variable(int line, std::string& text) {
  line_ = line;
  std::string aux_string = text;
  int found;
  /// Primero guardamos el tipo de la variable
  if (regex_search(text, kInt)) {
    type_ = "INT";
    /// Guardamos la posición en la que lo encontramos
    found = aux_string.find("int"); 
    aux_string = aux_string.substr(found);
  } else if (regex_search(text, kDouble)) {
    type_ = "DOUBLE";
    /// Guardamos la posición en la que lo encontramos
    found = aux_string.find("double");
    aux_string = aux_string.substr(found);
  } else if (regex_search(text, kFloat)) {
    type_ = "FLOAT";
    /// Guardamos la posición en la que lo encontramos
    found = aux_string.find("float");
    aux_string = aux_string.substr(found);
  } else if (regex_search(text, kAuto)) {
    type_ = "AUTO";
    /// Guardamos la posición en la que lo encontramos
    found = aux_string.find("auto");
    aux_string = aux_string.substr(found);
  } else if (regex_search(text, kString)) {
    type_ = "STRING";
    /// Guardamos la posición en la que lo encontramos
    found = aux_string.find("string");
    aux_string = aux_string.substr(found);
  }
  /// Ahora guardamos el nombre
  std::smatch match;
  found = aux_string.find_first_of(" ");
  aux_string = aux_string.substr(found + 1);
  if (regex_search(aux_string, match, kName)) { name_ = match.str(0); }
  /// Ahora guardamos el valor (si tiene)
  found = aux_string.find_first_of("({=;");
  aux_string = aux_string.substr(found);
  has_value_ = false;
  if (regex_search(aux_string, match, kValue)) {
    value_ = match.str(0);
    has_value_ = true;
  }
}

/** 
 *  @brief Getter del valor
 *  @return String con el valor"
 */
std::string Variable::get_value() const {
  std::string value;
  if (!has_value_) { value = "undefined"; }
  else { value = value_; }
  return value;
}

/** 
 *  @brief Getter de la línea
 *  @return String con formato [Line x]
 */
std::string Variable::get_line() const {
  return "[Line " + std::to_string(line_) + "]";
}

/** 
 *  @brief Getter de la línea
 *  @return String con formato [Line x] Type: name = value
 */
std::string Variable::get_variable() const {
  std::string aux_string = get_line() + kSpace;
  aux_string += get_type() + ":" + kSpace + get_name() + kSpace;
  if(has_value_) { aux_string += "=" + kSpace + value_; }
  return aux_string;
}

/** 
 *  @brief Sobrecarga del operador de salida
 *  @param[out] out
 *  @param[in] variable
 */
std::ostream& operator<<(std::ostream& out, const Variable& variable) {
  out << variable.get_variable();
  return out;
}