/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 11: Algoritmos Voraces
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 16 Dic 2022
 * @brief Archivo: money.h
 *        Definición de la clase dinero
 * 
 * @details 
 *    16/12/2022 - Creación del fichero
 */

#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <vector>
#include <list>
#include <map>

/** 
 *  @brief Esta clase se usa para guardar y trabajar con el dinero
 *         Guarda los siguientes datos:
 *            - Vector con las monedas/billetes que podemos usar para el cambio.
 *            - Una cantidad de dinero.
 *            - El cambio a devolver (en vector y en mapa).
 */
class Money {
 private:
  std::vector<int> coins_;
  std::vector<int> change_;
  std::map<int, int> map_change_;
  int money_;

 public:
  /// Constructor
  Money(double money, bool bills);

  /// Getters y setters
  inline double get_money() const { return money_; };
  inline std::vector<int> get_coins() const { return coins_; };
  inline std::vector<int> get_change() const { return change_; };
  inline std::map<int, int> get_map() const { return map_change_; };
  inline void set_money(double money) { money_ = money; };
  inline void set_coins(const std::vector<int>& coins) { coins_ = coins; };
  inline void set_change(const std::vector<int>& change) { change_ = change; };

  /// Funciones que calculan el cambio
  void devolver_cambio();
  void devolver_cambio_alternativo();
  /// Funciones que muestran el cambio
  void cambio_basico();
  void cambio_alternativo();
  /// Modificación
  int monedas_centimos();

  /// Sobrecargas
  friend std::ostream& operator<<(std::ostream& out, const Money& money);
};

#endif