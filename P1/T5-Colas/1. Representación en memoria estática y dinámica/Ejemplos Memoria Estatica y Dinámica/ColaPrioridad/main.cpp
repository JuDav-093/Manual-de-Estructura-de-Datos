#include "ColaPrioridad.cpp"
#include "Nodo.cpp"
#include "Validaciones.h" // Incluir el archivo de Validaciones
#include <iostream>
#include <cstdlib>

int main() {
    ColaPrioridad miCola;
    int valor, prioridad, opcion;

    do {
        std::cout << "\n1. Encolar elemento";
        std::cout << "\n2. Desencolar elemento";
        std::cout << "\n3. Imprimir cola";
        std::cout << "\n4. Salir";
        std::cout << "\nIngrese la opcion deseada: ";
        opcion = ingresar_enteros(""); // Usar la función ingresar_enteros para validar la opción

        switch(opcion) {
            case 1:
                system("cls");
                std::cout << "Ingrese el valor a encolar: ";
                valor = ingresar_enteros(""); // Validar el valor a encolar
                std::cout << "Ingrese la prioridad: ";
                prioridad = ingresar_enteros(""); // Validar la prioridad
                miCola.encolar(valor, prioridad);
                break;
            case 2:
                system("cls");
                miCola.desencolar();
                break;
            case 3:
                system("cls");
                miCola.imprimir();
                break;
        }
    } while(opcion != 4);

    return 0;
}
