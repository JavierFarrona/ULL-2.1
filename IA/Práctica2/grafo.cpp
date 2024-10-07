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
* Archivo: grafo.cpp
* Referencias: 
*     Enunciado de la práctica
* Historial de revisiones
*     07 Oct 2024 - Creación (primera versión) del código
*/

#include "grafo.h"

Grafo::Grafo(string nombre_fichero) {
    ifstream archivo(nombre_fichero);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo: " << nombre_fichero << endl;
        return;
    }

    // Leer la anchura y altura del laberinto
    archivo >> anchura_ >> altura_;

    matriz_.resize(anchura_, vector<int>(altura_));

    // Leer el laberinto y detectar las coordenadas de inicio (3) y fin (4)
    for (int i = 0; i < anchura_; i++) {
        for (int j = 0; j < altura_; j++) {
            archivo >> matriz_[i][j];
            if (matriz_[i][j] == 3) {
                inicio_ = {i, j};  // Detectar la entrada
            } else if (matriz_[i][j] == 4) {
                fin_ = {i, j};     // Detectar la salida
            }
        }
    }

    archivo.close();
}


void Grafo::imprimir_laberinto() {
    for (int i = 0; i < anchura_; i++) {
        for (int j = 0; j < altura_; j++) {
            if (matriz_[i][j] == 1) {
                cout << "🧱";  // Pared
            } else if (matriz_[i][j] == 0) {
                cout << "⬜";  // Camino
            } else if (matriz_[i][j] == 3) {
                cout << "🚪";  // Entrada
            } else if (matriz_[i][j] == 4) {
                cout << "🏁";  // Salida
            } else if (matriz_[i][j] == 2) {
                cout << "🚶";  // Camino recorrido
            } 
        }
        cout << endl;  // Nueva línea al final de cada fila
    }
}

void Grafo::CambiarInicio() {
    int x, y;
    cout << "Introduce las coordenadas x e y del nuevo inicio: ";
    cin >> x >> y;
    if (x < 1 || x > anchura_ || y < 1 || y > altura_) {
        cout << "Coordenadas inválidas." << endl;
        return;
    }
    matriz_[inicio_.first][inicio_.second] = 1;
    inicio_ = {x, y};
    matriz_[x - 1][y - 1] = 3;
}

void Grafo::CambiarFin() {
    int x, y;
    cout << "Introduce las coordenadas x e y de la nueva salida: ";
    cin >> x >> y;
    if (x < 1 || x > anchura_ || y < 1 || y > altura_) {
        cout << "Coordenadas inválidas." << endl;
        return;
    }
    matriz_[fin_.first][fin_.second] = 1;
    fin_ = {x - 1, y - 1};
    matriz_[x - 1][y - 1] = 4;
}  
   