#include <iostream>
#include <vector>
#include <conio.h>
#include "ordenamiento.cpp"
#include "validaciones.h"

int main() {
    std::vector<int> numeros;

    int opcion;
    do {
        std::cout << "\nMENU:\n";
        std::cout << "1. Ingresar numero\n";
        std::cout << "2. Ordenar numeros\n";
        std::cout << "3. Salir\n";
        std::cout << "Ingrese su opcion: ";
        opcion = ingresar_enteros("");

        switch (opcion) {
            case 1: {
                system("cls");
                int numero = ingresar_enteros("\nIngrese un numero entero: \n");
                numeros.push_back(numero);
                std::cout << "\n Numero ingresado correctamente.\n";
                break;
            }
            case 2: {
                if (numeros.empty()) {
                 std::cout << "No hay numeros para ordenar.\n";
                 } else {
                 std::cout << "Arreglo ingresado: ";
                 for (int num : numeros) {
                 std::cout << num << " ";
                }
                 std::cout << "\n";

        Ordenamiento::ordenamientoPorDistribucion(numeros);

                std::cout << "Arreglo ordenado: ";
                for (int num : numeros) {
                std::cout << num << " ";
                }
                std::cout << "\n";
                }
                break;
}
            case 3: {
                std::cout << "Saliendo del programa...\n";
                break;
            }
            default:
                std::cout << "Opcion no valida. Por favor, ingrese una opcion valida.\n";
                break;
        }
    } while (opcion != 3);

    return 0;
}
