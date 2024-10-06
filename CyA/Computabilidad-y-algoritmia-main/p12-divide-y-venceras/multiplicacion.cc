/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 12: Divide y vencerás
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 01 Ene 2023
 * @brief Archivo: multiplicacion.cc
 *        Contiene la implementación de la clase Multiplicacion
 * 
 * @details 
 *    01/01/2023 - Creación del fichero
 */

#include "multiplicacion.h"

/** 
 *  @brief Constructor con strings
 *  @param[in] primero Primero número de la multiplicación
 *  @param segundo Segundo número de la multiplicación
 */
Multiplicacion::Multiplicacion(std::string& primero, std::string& segundo) {
  primero_ = primero;
  segundo_ = segundo;
}

/** 
 *  @brief Constructor con BigInt
 *  @param[in] primero Primero número de la multiplicación
 *  @param segundo Segundo número de la multiplicación
 */
Multiplicacion::Multiplicacion(BigInt& primero, BigInt& segundo) {
  primero_ = primero;
  segundo_ = segundo;
}

/** 
 *  @brief Genera dos números aleatorios
 *  @param[in] num Longitud de los números
 *  @return void
 */
void Multiplicacion::randomNum(int num) {

}

/** 
 *  @brief Algoritmo de Karatsuba para enteros normales
 *  @param[in] x Primero número de la multiplicación
 *  @param[in] y Segundo número de la multiplicación
 *  @param[in] n Número de digitos
 *  @return Resultado de la multiplicación
 */
long Karatsuba(int x, int y, short n) { 
  /// Condición de parada
  if (n == 1) return x * y;
  short m = n / 2;
  long ten_m = pow(10, m); // 10^m
  long ten_2m = pow(10, 2 * m); // 10^(2*m)
  int a = x / ten_m, b = x % ten_m;
  int c = y / ten_m, d = y % ten_m;
  long ac = Karatsuba(a, c, m);
  long bd = Karatsuba(b, d, m);
  long a_b_x_c_d = Karatsuba(a - b, c - d, m);
  return ten_2m * ac + ten_m * (ac + bd - a_b_x_c_d) + bd;
}

/** 
 *  @brief Algoritmo Divide y Vencerás de Karatsuba mediante recursividad
 *  @param[out] n Para la recursividad
 *  @return Resultado de la multiplicación
 */
BigInt Karatsuba(const BigInt& num1, const BigInt& num2, long long n) {
  /// Condición de parada
  if (n == 1) return (num1 * num2); 
  long long m = n / 2;
  /// Potencias
  long long ten_m = pow(10, m);
  long long ten_2m = pow(10, 2 * m);
  BigInt ten_m_bi(ten_m); // 10^m
  BigInt ten_2m_bi(ten_2m); // 10^(2*m)
  /// Términos
  BigInt x1 = (num1 / ten_m_bi), x0 = (num1 % ten_m_bi);
  BigInt y1 = (num2 / ten_m_bi), y0 = (num2 % ten_m_bi);
  BigInt z2 = Karatsuba(x1, y1, m);
  BigInt z0 = Karatsuba(x0, y0, m);
  BigInt sum1 = x1 + x0, sum2 = y1 + y0;
  BigInt z1 = Karatsuba(sum1, sum2, m) - z2 - z0;
  return z2 * ten_2m_bi + z1 * ten_m + z0;
}

/** 
 *  @brief Multiplicación usando el operador * de BigInt
 *  @return Resultado de la multiplicación
 */
BigInt Operador(const BigInt& num1, const BigInt& num2) {
  BigInt result = num1 * num2;
  return result;
}

/** 
 *  @brief Cuando el número de dígitos de los valores x e y a multiplicar sean menor
 *         o igual que un valor cota determinado utilice el operador * de la clase BigInt,
 *         supuestamente más eficiente para números pequeños.
 *  @param[out] n Para la recursividad
 *  @return Resultado de la multiplicación
 */
BigInt Hibrido(const BigInt& num1, const BigInt& num2, long long n, const int cota) {
  /// Condición de parada
  if (n <= cota) return (num1 * num2); 
  long long m = n / 2;
  /// Potencias
  long long ten_m = pow(10, m);
  long long ten_2m = pow(10, 2 * m);
  BigInt ten_m_bi(ten_m); // 10^m
  BigInt ten_2m_bi(ten_2m); // 10^(2*m)
  /// Términos
  BigInt x1 = (num1 / ten_m_bi), x0 = (num1 % ten_m_bi);
  BigInt y1 = (num2 / ten_m_bi), y0 = (num2 % ten_m_bi);
  BigInt z2 = Hibrido(x1, y1, m, cota);
  BigInt z0 = Hibrido(x0, y0, m, cota);
  BigInt sum1 = x1 + x0, sum2 = y1 + y0;
  BigInt z1 = Hibrido(sum1, sum2, m, cota) - z2 - z0;
  return z2 * ten_2m_bi + z1 * ten_m + z0;
}