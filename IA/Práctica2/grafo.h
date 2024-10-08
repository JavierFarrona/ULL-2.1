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
#include <map>

using namespace std;

typedef pair<int, int> Cooredenadas;

class Grafo {
  private:
    int anchura_;
    int altura_;
    Cooredenadas inicio_;
    Cooredenadas fin_;
    //map<Cooredenadas, Nodo*> nodos_abiertos_;
    //map<Cooredenadas, Nodo*> nodos_cerrados_;
    //vector<Nodo*> camino_;
    //int coste_total_ = 0;
    vector<vector<int>> matriz_;
  public:
    Grafo(string nombre_fichero);
    
    void imprimir_laberinto();

    int get_anchura() const { return anchura_; }
    int get_altura() const { return altura_; }
    Cooredenadas get_inicio() const { return inicio_; }
    Cooredenadas get_fin() const { return fin_; }

    void CambiarInicio();
    void CambiarFin();

    //void BusquedaAEstrella(std::outstream& out);
    void ImprimirFicheroResultados(string nombre_fichero);

};

#endif // GRAFO_H