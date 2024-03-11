#include <iostream>
#include <vector>
#include "Validacion.h"

// Función para encontrar el máximo elemento en una matriz
int encontrarMaximo(const std::vector<int>& arr, int izquierda, int derecha) {
    if (izquierda == derecha) {
        return arr.at(izquierda);
    }
    else {
        int mitad = (izquierda + derecha) / 2;
        int maxIzquierda = encontrarMaximo(arr, izquierda, mitad);
        int maxDerecha = encontrarMaximo(arr, mitad + 1, derecha);
        return std::max(maxIzquierda, maxDerecha);
    }
}

int main() {
    std::vector<int> numeros;
    int maximoElemento;
    do {
        system("cls");
        std::cout << "\n1. Agregar un numero";
        std::cout << "\n2. Encontrar el numero maximo";
        std::cout << "\n3. Salir";
        int opcion = ingresoNumeroEntero((char*) "\nIngrese una opcion:  ");
        switch (opcion) {
        case 1:
            numeros.push_back(ingresoNumeroEntero((char*)"\nIngrese un numero:  "));
            break;
        case 2:
            if(numeros.size() != 0){
                maximoElemento = encontrarMaximo(numeros, 0, numeros.size() - 1);
                std::cout << "\nEl maximo numero es: " << maximoElemento << std::endl;
            }
            else {
                std::cout << "\nNo hay numeros\n";
            }
            system("pause");
            break;
        case 3:
            return 0;
        default:
            break;
        }
    } while (true);
}
