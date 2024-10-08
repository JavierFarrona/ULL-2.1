
#include "grafo.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>

const int INF = -1; // Representación de la no existencia de una arista

using namespace std;


/**
* @brief Constructor de la clase Grafo
* @param filename Nombre del archivo que contiene la matriz de adyacencia
*/

void Grafo::loadGraphFromFile(const string& filename) {
    ifstream file(filename); // Abrir el archivo
    if (!file.is_open()) { // Verificar si el archivo se abrió correctamente
        cout << "Error: ¡No se pudo abrir el archivo!" << endl;
        return;
    }

    file >> nodos_; // Leer el número de nodos
    int num = nodos_;
    matriz_.resize(num, vector<double>(num, -1.00)); // Redimensionar la matriz de adyacencia

    // Leer la matriz de adyacencia del archivo
    for (int i = 0; i < num; ++i) {
        for (int j = i+1; j < num; ++j) {
            if (i == j) {
                matriz_[i][j] = -1.00; // No hay arista entre un nodo y sí mismo
            } else {
                file >> matriz_[i][j]; // Leer el peso de la arista
                matriz_[j][i] = matriz_[i][j]; // La matriz es simétrica
            }
        }
    }

    file.close(); // Cerrar el archivo
}


/**
* @brief Método para realizar una búsqueda en anchura (BFS) en un grafo
* Selecciona aleatoriamente entre el mejor o peor nodo de la frontera basado en el coste acumulado.
* @param startVertex Nodo de inicio (indexado desde 0)
* @param endVertex Nodo de destino (indexado desde 0)
*/
void Grafo::BFS(int startVertex, int endVertex, ostream &out) {
    vector<bool> visited(nodos_, false);  // Vector para marcar nodos visitados
    vector<double> cost(nodos_, INF);     // Vector para almacenar costos acumulados
    vector<int> parent(nodos_, -1);       // Vector para almacenar los predecesores de los nodos

    // Inicializar la cola con el nodo inicial
    vector<int> frontier = {startVertex};
    visited[startVertex] = true;
    cost[startVertex] = 0; // Costo inicial es 0

    random_device rd; // Generador de números aleatorios
    mt19937 gen(rd());

    while (!frontier.empty()) {
        // Encontrar el nodo con el menor o mayor costo en la frontera
        int selectedNode;
        if (frontier.size() == 1) {
            selectedNode = frontier[0]; // Si solo hay un nodo, lo seleccionamos directamente
        } else {
            uniform_int_distribution<> dist(0, 1); // Seleccionar aleatoriamente 0 (mejor) o 1 (peor)
            int choice = dist(gen);
            if (choice == 0) {
                // Seleccionar el nodo con menor costo acumulado (mejor)
                selectedNode = *min_element(frontier.begin(), frontier.end(), [&cost](int a, int b) {
                    return cost[a] < cost[b];
                });
            } else {
                // Seleccionar el nodo con mayor costo acumulado (peor)
                selectedNode = *max_element(frontier.begin(), frontier.end(), [&cost](int a, int b) {
                    return cost[a] < cost[b];
                });
            }
        }

        // Eliminar el nodo seleccionado de la frontera
        frontier.erase(remove(frontier.begin(), frontier.end(), selectedNode), frontier.end());

        // Si hemos llegado al nodo de destino, terminamos la búsqueda
        if (selectedNode == endVertex) {
            out << "Nodo destino alcanzado: " << endVertex << " con costo acumulado: " << cost[endVertex] << endl;
            return;
        }

        // Explorar los vecinos del nodo seleccionado
        for (int neighbor = 0; neighbor < nodos_; ++neighbor) {
            double edgeCost = matriz_[selectedNode][neighbor];
            if (edgeCost != -1 && !visited[neighbor]) { // Si existe una arista y no ha sido visitado
                visited[neighbor] = true;
                cost[neighbor] = cost[selectedNode] + edgeCost; // Actualizar el costo acumulado
                parent[neighbor] = selectedNode; // Registrar el predecesor
                frontier.push_back(neighbor); // Añadir el vecino a la frontera
            }
        }
    }

    out << "No se encontró un camino al nodo destino." << endl;
}
