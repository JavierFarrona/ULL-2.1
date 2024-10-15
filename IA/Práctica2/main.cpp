#include "grafo.h"

int main() {

    Grafo grafo(0, 0, {0, 0}, {0, 0}, 0);  // Crear un objeto de tipo Grafo

    // Cargar el laberinto desde un archivo
    std::string nombre_fichero;
    std::cout << "Introduce el nombre del fichero: ";
    std::cin >> nombre_fichero;

    grafo.loadGrafo(nombre_fichero);  // Llamada a loadGrafo

    grafo.imprimir_laberinto();  // Llamada a imprimir_laberinto

    int opcion;
    std::cout << "¿Que desea hacer? \n 1 = Cambiar entrada\n 2 = Cambiar salida\n 3 = Heuristica Propuesta\n 4 = Heuristica Modificada\n 5 = Salir\n Opcion:";
    std::cin >> opcion;

    while (opcion != 5) {

        switch (opcion) {
            case 1:
                system("clear");
                grafo.CambiarInicio();
                std::cout << "Presione Enter para continuar...";
                break;
            case 2:
                system("clear");
                grafo.CambiarFin();
                std::cout << "Presione Enter para continuar...";
                break;
            case 3:
                system("clear");
                grafo.aStar(grafo.get_inicio(), grafo.get_fin(), "result.txt");  // Llamada a aStar
                grafo.imprimir_laberinto();  // Llamada a imprimir_laberinto
                grafo.loadGrafo(nombre_fichero);  // Llamada a loadGrafos
                std::cout << grafo.get_nodosGenerados() << " " << grafo.get_nodosInspeccionados() << std::endl;
                std::cout << "Presione Enter para continuar... (se avisa que se va a reiniciar el laberinto al laberinto original)" << std::endl;
                break;
            case 4:
                system("clear");
                grafo.aStarModificado(grafo.get_inicio(), grafo.get_fin(), "resultModi.txt");  // Llamada a aStarModificado
                grafo.imprimir_laberinto();  // Llamada a imprimir_laberinto
                grafo.loadGrafo(nombre_fichero);  // Llamada a loadGrafos
                std::cout << grafo.get_nodosGenerados() << " " << grafo.get_nodosInspeccionados() << std::endl;
                std::cout << "Presione Enter para continuar... (se avisa que se va a reiniciar el laberinto al laberinto original)" << std::endl;
                break;
            default:
                system("clear");
                std::cout << "Opción no válida." << std::endl;
                break;
        }

        std::cin.ignore();  // Ignora la nueva línea que queda después de std::cin
        std::cin.get();     // Espera hasta que se presione cualquier tecla


        system("clear");
        grafo.imprimir_laberinto();  // Llamada a imprimir_laberinto

        std::cout << "¿Que desea hacer? \n 1 = Cambiar entrada\n 2 = Cambiar salida\n 3 = Heuristica Propuesta\n 4 = Heuristica Modificada\n 5 = Salir\n Opcion: ";

        std::cin >> opcion;

    }

    return 0;
}
