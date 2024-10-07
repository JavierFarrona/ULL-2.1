#include "grafo.h"

int main () {
  Grafo laberinto("M_1.txt");
  laberinto.imprimir_laberinto();

  laberinto.CambiarInicio();
  laberinto.CambiarFin();

  laberinto.imprimir_laberinto();

  return 0;
}