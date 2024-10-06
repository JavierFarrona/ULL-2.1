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

#include "BigInt.h"

long acumulador = 0;

/** 
 *  @brief Algoritmo Divide y Vencerás de Karatsuba mediante recursividad
 *  @param[out] n Para la recursividad
 *  @return Resultado de la multiplicación
 */
BigInt Karatsuba(const BigInt& num1, const BigInt& num2, long long n) {
  /// Condición de parada
  if (n == 1) {
    ++acumulador;
    return (num1 * num2); 
  }
  long long m = n / 2; BigInt m_bg = m; BigInt m2_bg = 2 * m;
  long long ten = 10; BigInt ten_bg = ten;
  /// Potencias
  BigInt ten_m = ten_bg; ten_m ^= m_bg; // 10^m
  BigInt ten_2m = ten_bg; ten_2m ^= m2_bg; // 10^(2*m)
  /// Términos
  BigInt x1 = (num1 / ten_m), x0 = (num1 % ten_m);
  BigInt y1 = (num2 / ten_m), y0 = (num2 % ten_m);
  BigInt z2 = Karatsuba(x1, y1, m);
  BigInt z0 = Karatsuba(x0, y0, m);
  BigInt sum1 = x1 + x0, sum2 = y1 + y0;
  BigInt z1 = Karatsuba(sum1, sum2, m) - (z2 + z0);
  /// z2 B^2m + z1^Bm + z0 
  return z2 * ten_2m + z1 * ten_m + z0;
}

/** 
 *  @brief Multiplicación usando el operador * de BigInt
 *  @return Resultado de la multiplicación
 */
BigInt Operador(const BigInt& num1, const BigInt& num2) {
  BigInt result = num1 * num2;
  acumulador = Length(num1) * Length(num2);
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
  if (n <= cota) {
    acumulador += cota * cota;
    return (num1 * num2); 
  }
  /// Potencias
  long long m = n / 2; BigInt m_bg = m; BigInt m2_bg = 2 * m;
  long long ten = 10; BigInt ten_bg = ten;
  /// Potencias
  BigInt ten_m = ten_bg; ten_m ^= m_bg; // 10^m
  BigInt ten_2m = ten_bg; ten_2m ^= m2_bg; // 10^(2*m)
  /// Términos
  BigInt x1 = (num1 / ten_m), x0 = (num1 % ten_m);
  BigInt y1 = (num2 / ten_m), y0 = (num2 % ten_m);
  BigInt z2 = Hibrido(x1, y1, m, cota);
  BigInt z0 = Hibrido(x0, y0, m, cota);
  BigInt sum1 = x1 + x0, sum2 = y1 + y0;
  BigInt z1 = Hibrido(sum1, sum2, m, cota) - (z2 + z0);
  return z2 * ten_2m + z1 * ten_m + z0;
}

/** 
 *  @brief Algoritmo Divide y Vencerás del Campesino
 *  @see: 
 *  @param[in] num1 
 *  @param[in] num2 
 *  @return Resultado de la multiplicación
 */
BigInt Campesino(const BigInt& num1, const BigInt& num2) {
  long long zero = 0, aux_two = 2;
  BigInt result = zero;
  BigInt a = num1, b = num2, two = aux_two;
  while(!Null(b)) {
    /// Si "b" es impar
    if (!Null(b % two)) {
      /// Añadimos "a" al resultado
      result += a;
    }
    /// Duplicamos "a"
    a *= two;
    /// Dividimos "b"
    b /= two;
  }
  return result;
}