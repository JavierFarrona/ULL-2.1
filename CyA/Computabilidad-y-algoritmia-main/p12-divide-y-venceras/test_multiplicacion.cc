/// Programa para probar la clase multiplicacion

#include <iostream>
#include <string>
#include "multiplicacion.cc"

int main() {
  BigInt first("12");
  BigInt third("10000");
  std::cout << "first = " << first << '\n';
  std::cout << "third = " << third << '\n';
  BigInt product;
  product = first * third;
  std::cout << "Product of first and third = " << product << '\n';
  
  Multiplicacion mult(first, third);
  BigInt Karat;
  Karat = Karatsuba(first, third, first.Size());
  std::cout << "Product of first and third (K) = " << Karat << '\n';

  return EXIT_SUCCESS;
}