/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 3
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 9 Oct 2022
 * @brief Archivo: language.cc
 *        Implementación de la clase lenguaje
 * 
 * @details 
 *    09/10/2022 - Creación del fichero
 *    09/10/2022 - Atributos y constructor
 *    09/10/2022 - Funciones
 *    09/10/2022 - Operaciones
 *    10/10/2022 - Sobrecargas
 */

#include <iostream>
#include <set>

#include "language.h"

/** 
 *  @brief Añade un alfabeto al lenguaje
 *  @param[in] alphabet
 */
void Language::addAlphabet(const Alphabet& alphabet) {
  alphabet_ = alphabet;
}

/** 
 *  @brief Añade una cadena al lenguaje
 *  @param[in] sequence
 */
void Language::addSequence(const Sequence& sequence) {
  language_.insert(sequence);
}

/** 
 *  @brief Pasa el lenguaje a string
 *  @return Un string con las cadenas del lenguaje
 */
std::string Language::getLanguageString() const {
  std::string language = "{ ";
  for (const auto& elem : language_) {
    language += elem.getString() + SPACE;
  }
  language += "}";
  return language;
}

/** 
 *  @brief Concatenación de dos lenguajes
 *  @param[in] language1
 *  @param[in] language2
 *  @return language1 concatenado con language2
 */
Language Concatenacion(const Language& language1, const Language& language2) {
  Language new_language;
  /// Primero creamos el alfabeto común a ambos
  new_language.addAlphabet(language1.getAlphabet() + language2.getAlphabet());
  /// Ahora hacemos la concatenación
  for (const auto& elem1 : language1.getLanguage()) {
    for (const auto& elem2 : language2.getLanguage()) {
      Sequence new_sequence = elem1 + elem2;
      new_language.addSequence(new_sequence);
    }
  }
  return new_language;
}

/** 
 *  @brief Unión de dos lenguajes
 *  @param[in] language1
 *  @param[in] language2
 *  @return language1 unido con language2
 */
Language Union(const Language& language1, const Language& language2) {
  Language new_language;
  /// Primero creamos el alfabeto común a ambos
  new_language.addAlphabet(language1.getAlphabet() + language2.getAlphabet());
  /// Ahora hacemos la unión
  for (const auto& elem1 : language1.getLanguage()) { 
    new_language.addSequence(elem1);
  }
  for (const auto& elem2 : language2.getLanguage()) { 
    new_language.addSequence(elem2);
  }
  return new_language;
}

/** 
 *  @brief Busca la secuencia en el lenguage
 *  @param[in] sequence
 *  @return True si la encuentra
 */
bool Language::findSequence(const Sequence& sequence) const {
  bool found = false;
  for (const auto& elem : getLanguage()) {
    if (sequence == elem) found = true;
  }
  return found;
}

/** 
 *  @brief Intersección de dos lenguajes
 *  @param[in] language1
 *  @param[in] language2
 *  @return language1 intersectado con language2
 */
Language Interseccion(const Language& language1, const Language& language2) {
  Language new_language;
  /// Primero creamos el alfabeto común a ambos
  new_language.addAlphabet(language1.getAlphabet() + language2.getAlphabet());
  for (const auto& elem : language1.getLanguage()) {
    if (language2.findSequence(elem)) new_language.addSequence(elem);
  }
  return new_language;
}

/** 
 *  @brief Diferencia de dos lenguajes
 *  @param[in] language1
 *  @param[in] language2
 *  @return language1 - language2
 */
Language Diferencia(const Language& language1, const Language& language2) {
  Language new_language;
  /// Primero, creamos el alfabeto
  new_language.addAlphabet(language1.getAlphabet());
  for (const auto& elem : language1.getLanguage()) {
    if (!language2.findSequence(elem)) { new_language.addSequence(elem); };
  }
  return new_language;
}

/** 
 *  @brief Inversa de un lenguaje
 *  @param[in] language
 *  @return Lenguaje inverso
 */
Language Inversa(const Language& language) {
  Language new_language;
  /// Primero, creamos el alfabeto
  new_language.addAlphabet(language.getAlphabet());
  for (const auto& elem : language.getLanguage()) {
    new_language.addSequence(elem.reverse());
  }
  return new_language;
}

/** 
 *  @brief Potencia de un lenguaje
 *  @param[in] language
 *  @param[in] potencia
 *  @return El lenguaje concatenado consigo mismo
 */
Language Potencia(const Language& language, const int potencia) {
  Language aux_language = language;
  /// Primero, creamos el alfabeto
  aux_language.addAlphabet(language.getAlphabet());
  /// Preparamos el vacío por si es cero
  Sequence empty_sequence;
  empty_sequence.add_symbol('&');
  Language empty_language;
  empty_language.addSequence(empty_sequence);
  empty_language.addAlphabet(language.getAlphabet());
  if (potencia == 0) { return empty_language; };
  for (int i = 1; i < potencia; ++i) {
    aux_language = Concatenacion(language, aux_language);
  }
  /// Añadimos la primera iteración
  aux_language.addSequence(empty_sequence);
  return aux_language;
}

/// Sobrecargas

/// Sobrecarga de salida
std::ostream& operator<<(std::ostream& out, const Language& language) {
  out << language.getAlphabet() << SPACE << language.getLanguageString();
  return out;
}

/// Sobrecarga de la igualdad
bool operator==(const Language& language1, const Language& language2) {
  return language1.getLanguage() == language2.getLanguage();
}

/// Sobrecarga de la suma (concatenación)
Language operator+(const Language& language1, const Language& language2) {
  return Concatenacion(language1, language2);
}

/// Sobrecarga de la resta (diferencia)
Language operator-(const Language& language1, const Language& language2) {
  return Diferencia(language1, language2);
}

/// Sobrecarga de la multiplicación (potencia)
Language operator*(const Language& language1, const int potencia) {
  return Potencia(language1, potencia);
}

/// Sobrecarga del xor binario (intersección)
Language operator^(const Language& language1, const Language& language2) {
  return Interseccion(language1, language2);
}

/// Sobrecarga del or binario (unión)
Language operator|(const Language& language1, const Language& language2) {
  return Union(language1, language2);
}

/// Sobrecarga del not (inversa)
Language operator!(const Language& language1) {
  return Inversa(language1);
}
