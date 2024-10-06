/// Programa para hacer pruebas con la clase money

#include <iostream>
#include "money.cc"

int main() {
  Money new_money(7.43, false);
  // std::cout << new_money.get_money() << std::endl;
  new_money.devolver_cambio();
  new_money.devolver_cambio_alternativo();
  new_money.cambio_basico();
  new_money.cambio_alternativo();
  return 0;
}