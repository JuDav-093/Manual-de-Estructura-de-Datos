#include "quicksort.cpp"
#include "validaciones.h"

int main() {
    ListaEnlazada lista;
    int elemento;
    int opcion;
    do {
        std::cout << "\n*** Menu***\n";
        std::cout << "1. Insertar elemento\n";
        std::cout << "2. Mostrar lista\n";
        std::cout << "3. Aplicar Quicksort\n";
        std::cout << "0. Salir\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                elemento=ingresar_enteros("Ingrese un numero");
                lista.insertar(elemento);
                break;
            }
            case 2:
                std::cout << "Lista actual: ";
                lista.mostrar();
                break;
            case 3:
                std::cout << "Aplicando Quicksort...\n";
                lista.quicksort();
                std::cout << "Lista ordenada: ";
                lista.mostrar();
                break;
            case 0:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opcion no válida. Inténtelo de nuevo.\n";
                break;
        }

    } while (opcion != 0);

    return 0;
}
