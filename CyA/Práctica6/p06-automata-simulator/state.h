/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Computabilidad y Algoritmia
* Curso: 2º
* C:\Users\javie\Documents\GitHub\ULL-2.1\CyA\Práctica6\p06-automata-simulator
* Autor: Javier Farrona Cabrera
* Correo: alu0101541983@ull.edu.es
* Fecha 16 Oct 2024
* Archivo: state.h
* Referencias: 
*     Enunciado de la práctica
* Historial de revisiones
*     16 Oct 2024 - Creación (primera versión) del código
*/



#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <set>
#include <string>

/** 
 *  @brief Esta clase se usa para guardar los estados
 *         Guarda los siguientes datos:
 *            - Nombre del estado (name_)
 *            - Identificador del estado (id_)
 *            - Indica si es de aceptación (final_)
 */
class State {
 private:
  std::string name_ = "";
  unsigned int id_;
  bool final_ = false;

 public:
  /// Constructores
  State() {};
  State(const State& state);
  State(std::string name, unsigned int id, bool final);

  /// Getters y setters
  bool getFinal() const { return final_; };
  void setFinal(bool final) { final_ = final; };
  std::string getName() const { return name_; };
  void setName(std::string name) { name_ = name; };
  unsigned int getID() const { return id_; };
  void setID(unsigned int id) { id_= id; };
  
  /// Sobrecargas
  void operator=(const State& state);
  friend bool operator==(const State& state1, const State& state2);
  friend bool operator!=(const State& state1, const State& state2);
  friend bool operator<(const State& state1, const State& state2);
  friend bool operator>(const State& state1, const State& state2);
  friend std::ostream& operator<<(std::ostream& out, const State& state);

};

#endif