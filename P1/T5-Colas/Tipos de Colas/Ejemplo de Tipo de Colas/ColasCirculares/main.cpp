#include <iostream>
#include "ColasCirculares.cpp"
#include "Validaciones.h"

int main() {
    int elemento;
    int tamano = ingresar_enteros("Ingrese el tamaño de la cola circular:");
    CircularQueue colaCircular(tamano);

    int opcion;
    do {
        std::cout << "\n*** Menu de Operaciones ***\n";
        std::cout << "1. Encolar\n";
        std::cout << "2. Desencolar\n";
        std::cout << "3. Mostrar Contenido\n";
        std::cout << "0. Salir\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                elemento = ingresar_enteros("Ingrese numero de la cola:");
                printf("\n");
                colaCircular.encolar(elemento);
                break;

            case 2:
                colaCircular.desencolar();
                break;

            case 3:
                colaCircular.mostrarContenido();
                break;

            case 0:
                std::cout << "Saliendo del programa.\n";
                break;

            default:
                std::cout << "Opcion no valida. Intentelo de nuevo.\n";
                break;
        }

    } while (opcion != 0);

    return 0;
}
