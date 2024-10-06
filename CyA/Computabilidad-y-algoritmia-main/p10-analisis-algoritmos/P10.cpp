#include <iostream>

using namespace std;

// poner aqui los ejemplos como funciones con el siguiente formato,
// donde 'X' es el numero de ejemplo
int ejemploX(const int n) { 
  int suma = 0;
  // codigo fuente de cada bloque
  return suma;
}

/// @brief Bucle simple for de 1 a n
/// @param n : final del bucle
/// @return suma 
int ejemplo2(const int n) {
  int suma = 0;
  for (int i = 1; i <= n; i++)  // Θ(n)
    suma++;
  return suma;
}

/// @brief Dos bucles anidados for de 1 a n independientes
/// @param n : final de los bucles
/// @return suma 
int ejemplo3(const int n) {
  int suma = 0;  // Θ(1)
  for (int i = 1; i <= n; i++)  // Θ(n)
    for (int j = 1; j <= n; j++)  // Θ(n)
      suma++;  // Θ(1)
  return suma;
}

/// @brief Dos bucles anidados for dependientes
/// @param n : final de los bucles
/// @return suma 
int ejemplo4(const int n) {
  int suma = 0;  // Θ(1)
  for (int i = 1; i <= n; i++)  // Θ(n)
    for (int j = 1; j <= i; j++)  // Θ(i)
      suma++;  // Θ(1)
  return suma;
}

/// @brief Dos bucles anidados for con incremento de potencias
/// @param n : final de los bucles
/// @return suma 
int ejemplo5(const int n) {
  int suma = 0;  // Θ(1)
  for (int i = 1; i <= n; i *= 2)  // Θ(log n)
    for (int j = 1; j <= n; j++)  // Θ(n)
      suma++;  // Θ(1)
  return suma;
}

/// @brief Dos bucles anidados for dependendientes con incremento de potencias
/// @param n : final de los bucles
/// @return suma 
int ejemplo6(const int n) {
  int suma = 0;  // (1)
  for (int i = 1; i <= n; i *= 2)  // Θ(log n)
    for (int j = 1; j <= i; j++)  // Θ(i)
      suma++;  // (1)
  return suma;
}

/// @brief Ejercicio 1
/// @param n : final de los bucles
/// @return suma 
int ejercicio1(const int n) {
  int suma = 0; // O(1)
  for (int i = 1; i <= n; i++) // Θ(n)
    for (int j = 1; j <= n; j *= 2) // Θ(log n)
      for (int k = 1; k <= n; k++) // Θ(n)
        suma++; // O(1)
  return suma;
}

/// @brief Ejercicio 2
/// @param n : final de los bucles
/// @return suma 
int ejercicio2(const int n) {
  int suma = 0; // O(1)
  for (int i = 1; i <= n - 1; i++) // O(n)
    for (int j = i + 1; j <= n; j++) // O(n)
      suma++; // O(1)
  return suma;
}

/// @brief Ejercicio 3
/// @param n : final de los bucles
/// @return suma 
int ejercicio3(const int n) {
  int suma = 0; // O(1)

  return suma;
}

/// @brief Ejercicio 4
/// @param n : final de los bucles
/// @return suma 
int ejercicio4(const int n) {
  int suma = 0; // O(1)

  return suma;
}

int main() { 
  // pedir el valor de n
  int n;
  cout << "Introducir n: ";
  cin >> n;
  // invocar a cada ejemplo
  // cout << "Ejemplo X: " << ejemploX(n) << endl;
  // cout << "Ejemplo 2: " << ejemplo2(n) << endl;
  // cout << "Ejemplo 3: " << ejemplo3(n) << endl;
  // cout << "Ejemplo 4: " << ejemplo4(n) << endl;
  // cout << "Ejemplo 5: " << ejemplo5(n) << endl;
  // cout << "Ejemplo 6: " << ejemplo6(n) << endl;
  // cout << "Ejercicio 1: " << ejercicio1(n) << endl;
  // cout << "Ejercicio 2: " << ejercicio2(n) << endl;
  cout << "Ejercicio 3: " << ejercicio3(n) << endl;
  cout << "Ejercicio 4: " << ejercicio4(n) << endl;
  return 0;
}