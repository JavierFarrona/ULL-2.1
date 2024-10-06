/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 4
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 22 Oct 2022
 * @brief Archivo: variable.h
 *        Definición de la clase "variable"
 * 
 * @details 
 *    22/10/2022 - Creación del fichero
 *    22/10/2022 - Añadida la clase "variable"
 */

#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <regex>


/** 
 *  @brief Esta clase se usa para guardar las variables
 *         que encontremos mientras analizamos el fichero.
 *         Guarda los siguientes datos:
 *            - Dónde se encontró (line_)
 *            - Tipo de variable (type_)
 *            - Nombre de la variable (name_)
 *            - Si se inicializó (has_value_)
 *            - Valor con el que se inicializó (value_)
 */
class Variable {
 private:
  int line_;
  std::string type_;
  std::string name_;
  bool has_value_;
  std::string value_;

 public:
  /// Constructores
  Variable(int line, std::string& text);
  Variable() {};

  /// Funciones
  std::string get_value() const;
  std::string get_line() const;
  std::string get_type() const { return type_; };
  std::string get_name() const { return name_; };
  std::string get_variable() const;

  /// Sobrecargas
  friend std::ostream& operator<<(std::ostream& out, const Variable& variable);
};

#endif