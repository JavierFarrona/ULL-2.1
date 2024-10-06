/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 7
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 12 Nov 2022
 * @brief Archivo: grammar.h
 *        Definición de la clase gramática
 * 
 * @details 
 *    12/11/2022 - Creación del fichero
 */

#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <utility>
#include <iostream>
#include <fstream>
#include <utility>
#include <sstream>
#include <vector>
#include <set>

#include "alphabet.h"

/// Cambiar a symbol
typedef std::set<std::pair<Symbol, std::vector<Symbol>>> set_pair;

/** 
 *  @brief Esta clase se usa para guardar una gramática regular
 *         Guarda los siguientes datos:
 *            - Alfabeto de la gramática (alphabet_)
 *            - Conjunto de símbolos no terminales (symbols_)
 *            - No terminal inicial (initial_)
 *            - Producciones (productions_)
 */
class Grammar {
 private:
  std::set<Symbol> non_terminals_; /// no term, symbols
  Alphabet terminals_; /// term, alphabet
  Symbol initial_;
  set_pair productions_;

 public:
  /// Constructores
  Grammar() {};
  Grammar(const Grammar& grammar);

  /// Getters y setters
  void setNonTerminals(const std::set<Symbol>& symbols) { non_terminals_ = symbols; };
  void setTerminals(const Alphabet& alphabet) { terminals_ = alphabet; };
  void setInitial(const Symbol initial) { initial_ = initial; };
  void setProductions(const set_pair& productions) { productions_ = productions; };
  std::set<Symbol> getNonTerminals() const { return non_terminals_; };
  Alphabet getTerminals() const { return terminals_; };
  Symbol getInitial() const { return initial_; };
  set_pair getProductions() const { return productions_; };

  /// Funciones
  void Write(const std::string& kFileName);
  void WriteProductions();
  bool isRegular();
  bool isRegularLeft();
  bool isRegularRigth();
  bool accepted(const std::string& sequence);
  friend std::ostream& operator<<(std::ostream& out, const Grammar& grammar);
  /// Modificacion
  void fixDeath();

};

#endif