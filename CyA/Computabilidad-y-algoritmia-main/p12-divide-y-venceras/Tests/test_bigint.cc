/// Programa para probar la clase BigInt

#include <iostream>
#include <string>
#include "../BigInt.cc"

int main() {
  BigInt prueba;
  std::cout << "Introduce un num: ";
  std::cin >> prueba;
  std::cout << "Prueba: " << prueba << std::endl;
  BigInt first("12345");
  std::cout << "The number of digits in first big integer = " << Length(first) << '\n';
  BigInt second(12345);
  if (first == second) std::cout << "first and second are equal!\n";
  else std::cout << "Not equal!\n";
  BigInt third("10000");
  BigInt fourth("100000");
  if (third < fourth) std::cout << "third is smaller than fourth!\n";
  BigInt fifth("10000000");
  if (fifth > fourth) std::cout << "fifth is larger than fourth!\n"; 
  
  /// Printing all the numbers
  std::cout << "first = " << first << '\n';
  std::cout << "second = " << second << '\n';
  std::cout << "third = " << third << '\n';
  std::cout << "fourth = " << fourth<< '\n';
  std::cout << "fifth = " << fifth<< '\n';

  /// Incrementing the value of first
  first++;
  std::cout << "After incrementing the value of first is : " << first << '\n';
  
  BigInt sum;
  sum = (fourth + fifth);
  std::cout << "Sum of fourth and fifth = " << sum << '\n';
  BigInt product;
  product = second * third;
  std::cout << "Product of second and third = " << product << '\n';
 
  return EXIT_SUCCESS;
}