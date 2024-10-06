#include "grafo.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

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
* @param startVertex Nodo de inicio (indexado desde 0)
* @param endVertex Nodo de destino (indexado desde 0)
*/

void Grafo::BFS(int startVertex, int endVertex, ostream &out) {
    vector<bool> visited(nodos_, false);  // Para rastrear nodos visitados
    vector<int> parent(nodos_, -1);       // Para reconstruir el camino
    vector<int> toExplore;                // Nodos por explorar
    vector<int> inspected;                // Nodos inspeccionados
    int numEdges = 0;                     // Contador de aristas

    // Imprimir el número de nodos y aristas del grafo
    for (int i = 0; i < nodos_; ++i) {
        for (int j = 0; j < nodos_; ++j) {
            if (matriz_[i][j] != INF) {
                numEdges++;
            }
        }
    }
    numEdges /= 2;  // Porque las aristas son bidireccionales y se cuentan doble
    out << "Número de nodos del grafo: " << nodos_ << endl;
    out << "Número de aristas del grafo: " << numEdges << endl;
    out << "Vértice origen: " << startVertex + 1 << endl;
    out << "Vértice destino: " << endVertex + 1 << endl;

    toExplore.push_back(startVertex); // Agregar el nodo de inicio a la lista de exploración
    visited[startVertex] = true; // Marcar el nodo de inicio como visitado
    int currentIndex = 0;
    bool found = false;
    int iteration = 1;
    vector<int> newGenerated;  // Para almacenar los nuevos nodos generados en esta iteración

    out << "--------------------------------" << endl;
    out << "Iteración " << iteration << endl;
    out << "Nodos generados: " << startVertex + 1 << endl;
    out << "Nodos inspeccionados: -" << endl;

    // Bucle principal de BFS
    while (currentIndex < toExplore.size()) {
        int current = toExplore[currentIndex];
        inspected.push_back(current); // Agregar el nodo actual a la lista de inspeccionados
        out << "--------------------------------" << endl;
        out << "Iteración " << iteration++ << endl;
        out << "Nodos generados: ";

        // Explorar nodos adyacentes
        for (int i = 0; i < nodos_; ++i) {
            if (matriz_[current][i] != INF && !visited[i]) {
                visited[i] = true; // Marcar el nodo como visitado
                parent[i] = current; // Establecer el nodo actual como padre
                toExplore.push_back(i); // Agregar el nodo a la lista de exploración
                newGenerated.push_back(i + 1);  // Convertir a 1-based index
                if (i == endVertex) {
                    found = true; // Si encontramos el nodo de destino, marcar como encontrado
                }
            }
        }

        // Imprimir los nodos generados y luego los nodos inspeccionados
        for (size_t i = 0; i < newGenerated.size(); ++i) {
            out << newGenerated[i];
            if (i != newGenerated.size() - 1) out << ", ";
        }
        out << endl;
        out << "Nodos inspeccionados: ";
        for (size_t i = 0; i < inspected.size(); ++i) {
            out << inspected[i] + 1;
            if (i != inspected.size() - 1) out << ", ";
        }
        out << endl;

        currentIndex++;
        if (found) break;  // Si encontramos el vértice de destino, salimos del bucle
    }

    // Reconstruir el camino y calcular el costo total
    if (found) {
        vector<int> path;
        double totalCost = 0.0;  // Variable para almacenar el coste total del camino
        for (int v = endVertex; v != -1; v = parent[v]) {
            path.push_back(v + 1);  // Convertimos a 1-based index
            if (parent[v] != -1) {
                totalCost += matriz_[parent[v]][v];  // Sumar el coste de la arista entre parent[v] y v
            }
        }
        reverse(path.begin(), path.end()); // Invertir el camino para obtener el orden correcto

        // Imprimir el camino y el coste total
        out << "--------------------------------" << endl;
        out << "Camino: ";
        for (size_t i = 0; i < path.size(); ++i) {
            out << path[i];
            if (i != path.size() - 1) out << " - ";
        }
        out << endl;
        out << "Costo: " << totalCost << endl;
    } else {
        out << "No se encontró un camino desde " << startVertex + 1 << " hasta " << endVertex + 1 << endl;
    }
}


/**
* @brief Método para realizar una búsqueda en profundidad (DFS) en un grafo
* @param startVertex Nodo de inicio (indexado desde 0)
* @param endVertex Nodo de destino (indexado desde 0)
*/

void Grafo::DFS(int startVertex, int endVertex, ostream &out) {
    vector<bool> visited(nodos_, false);  // Para rastrear nodos visitados
    vector<int> parent(nodos_, -1);       // Para reconstruir el camino
    vector<int> toExplore;                // Nodos por explorar (no stack, sólo vector)
    vector<int> inspected;                // Nodos inspeccionados
    int numEdges = 0;                     // Contador de aristas

    // Imprimir el número de nodos y aristas del grafo
    for (int i = 0; i < nodos_; ++i) {
        for (int j = 0; j < nodos_; ++j) {
            if (matriz_[i][j] != INF) {
                numEdges++;
            }
        }
    }
    numEdges /= 2;  // Porque las aristas son bidireccionales y se cuentan doble
    out << "Número de nodos del grafo: " << nodos_ << endl;
    out << "Número de aristas del grafo: " << numEdges << endl;
    out << "Vértice origen: " << startVertex + 1 << endl;
    out << "Vértice destino: " << endVertex + 1 << endl;

    toExplore.push_back(startVertex); // Agregar el nodo de inicio a la lista de exploración
    visited[startVertex] = true; // Marcar el nodo de inicio como visitado
    int currentIndex = 0;
    bool found = false;
    int iteration = 1;
    vector<int> newGenerated;  // Para almacenar los nuevos nodos generados en esta iteración

    out << "--------------------------------" << endl;
    out << "Iteración 0" << endl;
    out << "Nodos generados: " << startVertex + 1 << endl;
    out << "Nodos inspeccionados: -" << endl;

    // Bucle principal de DFS (iterativo utilizando vector)
    while (currentIndex >= 0) {
        int current = toExplore.back();
        inspected.push_back(current); // Agregar el nodo actual a la lista de inspeccionados
        toExplore.pop_back();  // Lo eliminamos del vector para simular el backtracking
        out << "--------------------------------" << endl;
        out << "Iteración " << iteration++ << endl;
        out << "Nodos generados: ";
        


        // Explorar nodos adyacentes
        for (int i = 0; i < nodos_; ++i) {
            if (matriz_[current][i] != INF && !visited[i]) {
                visited[i] = true; // Marcar el nodo como visitado
                parent[i] = current; // Establecer el nodo actual como padre
                toExplore.push_back(i);  // DFS es LIFO, entonces agregamos al final para continuar profundizando
                newGenerated.push_back(i + 1);  // Convertir a 1-based index
                if (i == endVertex) {
                    found = true; // Si encontramos el nodo de destino, marcar como encontrado
                    break;
                }
            }
        }

        // Imprimir los nodos generados y luego los nodos inspeccionados
        for (size_t i = 0; i < newGenerated.size(); ++i) {
            out << newGenerated[i];
            if (i != newGenerated.size() - 1) out << ", ";
        }
        out << endl;
        out << "Nodos inspeccionados: ";
        for (size_t i = 0; i < inspected.size(); ++i) {
            out << inspected[i] + 1;
            if (i != inspected.size() - 1) out << ", ";
        }
        out << endl;

        if (found) break;  // Si encontramos el vértice de destino, salimos del bucle
    }

    // Reconstruir el camino y calcular el costo total
    if (found) {
        vector<int> path;
        double totalCost = 0.0;  // Variable para almacenar el coste total del camino
        for (int v = endVertex; v != -1; v = parent[v]) {
            path.push_back(v + 1);  // Convertimos a 1-based index
            if (parent[v] != -1) {
                totalCost += matriz_[parent[v]][v];  // Sumar el coste de la arista entre parent[v] y v
            }
        }
        reverse(path.begin(), path.end()); // Invertir el camino para obtener el orden correcto

        // Imprimir el camino y el coste total
        out << "--------------------------------" << endl;
        out << "Camino: ";
        for (size_t i = 0; i < path.size(); ++i) {
            out << path[i];
            if (i != path.size() - 1) out << " - ";
        }
        out << endl;
        out << "Costo: " << totalCost << endl;
    } else {
        out << "No se encontró un camino desde " << startVertex + 1 << " hasta " << endVertex + 1 << endl;
    }
}


/*
void Grafo::DFS_MenorCoste(int startVertex, int endVertex, ostream &out) {
    vector<bool> visited(nodos_, false);
    vector<int> parent(nodos_, -1);  
    vector<int> path; 
    double totalCost = 0.0;
    
    // Usamos un vector de pares (costo, nodo)
    vector<pair<double, int>> toExplore;
    toExplore.push_back({0.0, startVertex});  // Empezamos con el nodo inicial
    
    bool found = false;
    
    while (!toExplore.empty()) {
        // Ordenamos la lista de nodos a explorar por coste
        sort(toExplore.begin(), toExplore.end());
        int current = toExplore.front().second;  // Tomamos el nodo de menor coste
        double currentCost = toExplore.front().first;
        toExplore.erase(toExplore.begin());  // Eliminar de la lista

        if (visited[current]) continue;  // Si ya fue visitado, saltar

        visited[current] = true;
        path.push_back(current + 1);  // Convertimos a índice basado en 1

        if (current == endVertex) {  // Si llegamos al nodo destino
            found = true;
            totalCost = currentCost;  // Guardamos el coste total
            break;
        }

        // Revisamos los vecinos del nodo actual
        for (int i = 0; i < nodos_; ++i) {
            if (matriz_[current][i] != -1 && !visited[i]) {
                toExplore.push_back({currentCost + matriz_[current][i], i});
                parent[i] = current;  // Guardamos el nodo padre
            }
        }
    }
    
    if (found) {
        // Reconstruir el camino
        vector<int> finalPath;
        for (int v = endVertex; v != -1; v = parent[v]) {
            finalPath.push_back(v + 1);  // Convertir a índice basado en 1
        }
        reverse(finalPath.begin(), finalPath.end());

        // Imprimir el camino y el coste total
        out << "Camino encontrado: ";
        for (size_t i = 0; i < finalPath.size(); ++i) {
            out << finalPath[i];
            if (i != finalPath.size() - 1) out << " - ";
        }
        out << "\nCosto total: " << totalCost << endl;
    } else {
        out << "No se encontró un camino desde " << startVertex + 1 << " hasta " << endVertex + 1 << endl;
    }
}
*/