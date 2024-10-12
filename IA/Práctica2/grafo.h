/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Computabilidad y Algoritmia
* Curso: 2º
* C:\Users\Usuario\Documents\GitHub\ULL-2.1\IA\Práctica2
* Autor: Javier Farrona Cabrera
* Correo: alu0101541983@ull.edu.es
* Fecha 07 Oct 2024
* Archivo: grafo.h
* Referencias: 
*     Enunciado de la práctica
* Historial de revisiones
*     07 Oct 2024 - Creación (primera versión) del código
*/

#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> Coordenadas;

struct Nodo {
    int x, y;
    double g, h;
    Nodo* padre;  // Para rastrear el camino

    // Constructor
    Nodo(int x, int y, double g, double h, Nodo* padre = nullptr) 
        : x(x), y(y), g(g), h(h), padre(padre) {}

    bool operator<(const Nodo& otro) const {
        return (g + h) > (otro.g + otro.h);  // Comparador para priority_queue
    }
};


class Grafo {
  private:
    float costeTotal_;
    int anchura_;
    int altura_;
    Coordenadas inicio_;
    Coordenadas fin_;
    vector<vector<int>> matriz_;
    std::vector<std::pair<int, int>> nodosGenerados; // Para nodos generados
    std::vector<std::pair<int, int>> nodosInspeccionados; // Para nodos inspeccionados

  public:

    Grafo(int anchura, int altura, Coordenadas inicio, Coordenadas fin, float costeTotal) 
        : anchura_(anchura), altura_(altura), inicio_(inicio), fin_(fin), costeTotal_(costeTotal) {
      matriz_.resize(anchura_, vector<int>(altura_));
    }

    void loadGrafo(string nombre_fichero);
    
    void imprimir_laberinto();

    int get_anchura() const { return anchura_; }
    int get_altura() const { return altura_; }
    Coordenadas get_inicio() const { return inicio_; }
    Coordenadas get_fin() const { return fin_; }

    void CambiarInicio();
    void CambiarFin();
    vector<pair<int, int>> obtenerVecinos(int x, int y);

    void aStar(Coordenadas inicio, Coordenadas objetivo, const std::string& nombreArchivo);
    void aStarModificado(Coordenadas inicio, Coordenadas objetivo, const std::string& nombreArchivo);
    void ImprimirFicheroResultados(string nombre_fichero);
    void guardarGrafo(const Grafo& grafo, const std::string& nombreArchivo);
    void marcarCamino(Nodo* nodo, Grafo& grafo);
    void guardarNodos(const std::string& nombreArchivo);

    double heuristica(int x1, int y1, int x2, int y2) {
      return (abs(x1 - x2) + abs(y1 - y2)) * 3;  // W = 3
    }

    double heuristicaModificada(int x1, int y1, int x2, int y2) {
      return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) * 3;  // W = 3
    }

};

#endif // GRAFO_H