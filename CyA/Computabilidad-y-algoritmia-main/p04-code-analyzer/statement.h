/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 4
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 22 Oct 2022
 * @brief Archivo: loop.h
 *        Definición de la clase "statement"
 * 
 * @details 
 *    22/10/2022 - Creación del fichero
 *    22/10/2022 - Añadida la clase "statement"
 */

#ifndef LOOP_H
#define LOOP_H

#include <iostream>
#include <string>
#include <regex>

/** 
 *  @brief Esta clase se usa para guardar los bucles (for y while)
 *         que encontremos mientras analizamos el fichero.
 *         Guarda los siguientes datos:
 *            - Tipo de bucle (type_)
 *            - Dónde se encontró (line_)
 */
class Statement {
 private:
  std::string type_;
  int line_;
 
 public:
  /// Constructores
  Statement(const int line, const std::string& text);
  Statement() {};

  /// Funciones
  int get_line() const { return line_; };
  std::string get_statement() const;

  /// Sobrecargas
  friend std::ostream& operator<<(std::ostream& out, const Statement& statement);
};

#endif