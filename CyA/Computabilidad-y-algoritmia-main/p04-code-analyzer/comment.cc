/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 4
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 22 Oct 2022
 * @brief Archivo: comment.cc
 *        Implementación de la clase "comment"
 * 
 * @details 
 *    22/10/2022 - Creación del fichero
 *    22/10/2022 - Añadidos los contructores
 *    22/10/2022 - Añadidos el getter de líneas
 *    22/10/2022 - Añadida la sobrecarga <<
 */

#include "comment.h"

/** 
 *  @brief Constructor para el de varias líneas
 *  @param[in] start
 *  @param[in] end
 *  @param[in] text
 */
Comment::Comment(const int start, const int end, const std::string& text) {
  start_ = start;
  end_ = end;
  text_ = text;
}

/** 
 *  @brief Constructor para el de una línea
 *  @param[in] line
 *  @param[in] text
 */
Comment::Comment(const int line, const std::string& text) {
  start_ = line;
  end_ = line;
  text_ = text;
}

/** 
 *  @brief Getter de las líneas
 *  @return String en formato: [Line x]
 */
std::string Comment::get_lines() const {
  std::string lines = "[Line";
  if (start_ == end_) { lines += "s " + std::to_string(end_) + "]"; }
  else { lines += " " + std::to_string(start_) + "-" + std::to_string(end_) + "]"; }
  return lines;
}

/** 
 *  @brief Sobrecarga del operador de salida
 *  @param[out] out
 *  @param[in] comment
 */
std::ostream& operator<<(std::ostream& out, const Comment& comment) {
  /// Si es un comentario de una línea
  if (comment.start_ == comment.end_) { out << "[Line " << comment.start_ << "] " << comment.text_; }
  /// Si es un comentario de varias líneas
  else { out << "[Lines " << comment.start_ << "-" << comment.end_  << "]: " << comment.text_; }
  return out;
}