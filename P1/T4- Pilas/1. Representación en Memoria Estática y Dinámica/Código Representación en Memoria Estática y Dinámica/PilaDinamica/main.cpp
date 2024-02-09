#include "PilaDinamica.cpp"
#include "Validaciones.h" // Incluir el archivo de Validaciones
#include <cstdlib>
#include <iostream>

int main() {
    PilaDinamica miPila;
    int valor, opcion;

    do {
        std::cout << "\n1. Insertar elemento en la pila";
        std::cout << "\n2. Eliminar elemento de la pila";
        std::cout << "\n3. Imprimir pila";
        std::cout << "\n4. Salir";
        std::cout << "\nIngrese una opcion: ";
        opcion = ingresar_enteros(""); // Usar la función ingresar_enteros para validar la opción

        switch(opcion) {
            case 1:
                system("cls");
                std::cout << "Ingrese el valor a insertar: \n";
                valor = ingresar_enteros(""); // Validar el valor a insertar
                miPila.push(valor);
                break;
                
            case 2:
                system("cls");
                miPila.pop();
                break;
                
            case 3:
                system("cls");
                miPila.imprimir();
                break;
                
        }
    } while(opcion != 4);

    return 0;
}
