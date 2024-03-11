#include <iostream>
#include <vector>
#include "Validacion.h"

// Función para encontrar el máximo elemento en una matriz
int encontrarMaximo(const std::vector<int>& arr) {
    int maxElemento = arr.at(0);
    for (int i = 1; i < arr.size(); ++i) {
        if (arr.at(i) > maxElemento) {
            maxElemento = arr.at(i);
        }
    }
    return maxElemento;
}

int main() {
    std::vector<int> numeros;
    int maximoElemento;
    do {
        system("cls");
        std::cout << "Aritmetica de la notacion O";
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
                maximoElemento = encontrarMaximo(numeros);
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
