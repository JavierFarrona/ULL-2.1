/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 4
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 22 Oct 2022
 * @brief Archivo: comment.h
 *        Definición de la clase "comment"
 * 
 * @details 
 *    24/10/2022 - Creación del fichero
 *    24/10/2022 - Añadida la clase "comment"
 */

#ifndef COMMENT_H
#define COMMENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/** 
 *  @brief Esta clase se usa para guardar los comentarios
 *         que encontremos mientras analizamos el fichero.
 *         Guarda los siguientes datos:
 *            - String de comentarios (text_)
 *            - Dónde empezaron (start_)
 *            - Dónde terminaron (end_)
 */
class Comment {
 private:
  int start_;
  int end_;
  std::string text_;

 public:
  /// Constructores
  Comment(const int start, const int end, const std::string& text); /// Varias líneas
  Comment(const int line, const std::string& text); /// Una línea
  Comment() {}; /// Por defecto

  /// Funciones
  std::string get_lines() const;
  int get_start() const { return start_; };
  int get_end() const { return end_; };
  std::string get_text() const { return text_; };

  /// Sobrecargas
  friend std::ostream& operator<<(std::ostream& out, const Comment& comment);

};

#endif