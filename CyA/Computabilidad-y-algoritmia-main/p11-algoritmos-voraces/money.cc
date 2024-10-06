/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 11: Algoritmos Voraces
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 16 Dic 2022
 * @brief Archivo: money.cc
 *        Implementación de la clase dinero
 * 
 * @details 
 *    16/12/2022 - Creación del fichero
 *    17/12/2022 - Implementación de las funciones
 *    18/12/2022 - Revisión de errores
 */

#include <iostream>
#include "money.h"

/** @brief Constructor de la clase money
 *  @param[in] money Dinero introducido (por defecto cero)
 *  @param[in] bills Si se quieren usar billetes o no (por defecto no)
 */
Money::Money(double money = 0.0, bool bills = false) {
  money_ = money * 100;
  if (bills) {
    std::vector<int> coins = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    coins_ = coins;
  } else {
    std::vector<int> coins = {200, 100, 50, 20, 10, 5, 2, 1};
    coins_ = coins;
  }
  for (const auto& elem : coins_) {
    map_change_[elem] = 0;
  }
}

// 31.38

/** @brief Cuenta la cantidad de monedas pequeñas
 *         Monedas de 5, 2 y 1 céntimos
 *  @return Número de monedas pequeñas
 */
int Money::monedas_centimos() {
  return (map_change_[5] + map_change_[2] + map_change_[1]);
}

/** @brief Muestra la solución básica
 *  @return void
 */
void Money::cambio_basico() {
  std::string solucion = "Solución: ";
  for (const auto& elem : get_change()) {
    if (elem / 100 == 0) {
      solucion += std::to_string(elem) + "c, "; 
    } else {
      solucion += std::to_string(elem / 100) + "€, "; 
    }
  }
  solucion.pop_back(); solucion.pop_back();
  std::cout << solucion << std::endl;
  std::cout << "Total monedas/billetes: " << get_change().size() << std::endl;
  std::cout << "Total centimos: " << monedas_centimos() << std::endl;
}

/** @brief Muestra la solución más elaborada
 *  @return void
 */
void Money::cambio_alternativo() {
  std::cout << "Solución: ";
  std::string solucion;
  for (const auto& elem : get_map()) {
    if (elem.second != 0) {
      if (elem.first / 100 == 0) {
        std::string x = "x", c = "c, ";
        solucion = (elem.second == 1 ? "" : std::to_string(elem.second) + x) + std::to_string(elem.first) + c + solucion; 
      } else {
        std::string x = "x", eur = "€, ";
        solucion = (elem.second == 1 ? "" : std::to_string(elem.second) + x) + std::to_string(elem.first / 100) + eur + solucion; 
      }
    }
  }
  solucion.pop_back(); solucion.pop_back();
  std::cout << solucion << std::endl;
  std::cout << "Total monedas/billetes: " << get_change().size() << std::endl;;
  std::cout << "Total centimos: " << monedas_centimos() << std::endl;
}

/** @brief Algoritmo para el cambio de monedas
 *  @return void
 */
void Money::devolver_cambio() {
  /// M = Nuestro atributo "coins_"
  std::vector<int> M = get_coins();
  /// S = Nuestro atributo "change_"
  std::vector<int> S;
  int suma = 0;
  int size = get_coins().size();
  int i = 0; /// Iterador para ir recorriendo las monedas
  /// mientras suma ≠ n hacer
  while (suma != get_money()) {
    if (i > size) {
      /// Si nos salimos del vector de monedas
      std::cout << "No hay solucion." << std::endl;
      break;
    } else if (suma + M[i] <= get_money()) {
      /// Sumamos y añadimos una moneda
      suma = suma + M[i];
      S.push_back(M[i]);
      map_change_[M[i]] = map_change_[M[i]] + 1;
    } else {
      /// Miramos la siguiente moneda
      ++i;
    }
  }
  set_change(S);
}

/** @brief Algoritmo alternativo para el cambio de monedas
 *  @return void
 */
void Money::devolver_cambio_alternativo() {
  /// M = Nuestro atributo "coins_"
  std::vector<int> M = get_coins();
  /// S = Nuestro atributo "change_"
  std::vector<int> S;
  int suma = 0;
  /// para v ∈ M (de mayor a menor valor)
  for (const auto& elem : M) {
    int cociente = (get_money() - suma) / elem;
    if (cociente > 0) {
      for (int i = 0; i < cociente; i++) S.push_back(elem);
      map_change_[elem] = cociente;
      suma = suma + (elem * cociente);
    }
  }
  set_change(S);
}

/// @brief Sobrecarga del operador de salida
/// NOTA: Usado para depurar
std::ostream& operator<<(std::ostream& out, const Money& money) {
  out << "Solución: ";
  for (const auto& elem : money.get_change()) {
    if (elem / 100 == 0) {
      out << elem << "c "; 
    } else {
      out << elem / 100 << "€ "; 
    }
  }
  out << std::endl;
  return out;
}