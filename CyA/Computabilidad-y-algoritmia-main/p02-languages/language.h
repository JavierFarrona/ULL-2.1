/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 2
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 9 Oct 2022
 * @brief Archivo: language.h
 *        Definición de la clase lenguaje
 * 
 * @details 
 *    09/10/2022 - Creación del fichero
 *    09/10/2022 - Atributos y constructor
 *    09/10/2022 - Funciones
 *    09/10/2022 - Operaciones
 */

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <iostream>
#include <set>

#include "sequence.cc"

class Language {
 private:
  std::set<Sequence> language_;
  Alphabet alphabet_;

 public:
  /// Constructor
  Language() {};

  /// Getters
  std::string getLanguageString() const;
  std::set<Sequence> getLanguage() const { return language_; };
  Alphabet getAlphabet() const { return alphabet_; };
  int length() const { return language_.size(); };

  /// Funciones
  void addAlphabet(const Alphabet& alphabet);
  void addSequence(const Sequence& sequence);
  void setSequences(std::set<Sequence> sequences) { language_ = sequences; };
  bool findSequence(const Sequence& sequence) const;

};

/// Operaciones
Language Concatenacion(const Language& language1, const Language& language2); /// *
Language Union(const Language& language1, const Language& language2); /// +
Language Interseccion(const Language& language1, const Language& language2);
Language Diferencia(const Language& language1, const Language& language2); /// -
Language Inversa(const Language& language);
Language Potencia(const Language& language, const int potencia);

/// Sobrecargas
std::ostream& operator<<(std::ostream& out, const Language& language); /// Salida
Language operator+(const Language& language1, const Language& language2); /// Unión
Language operator-(const Language& language1, const Language& language2); /// Diferencia
Language operator*(const Language& language1, const Language& language2); /// Concatenación

#endif