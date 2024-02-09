#include "OperacionesArboles.cpp"
#include <iostream>
#include "Validaciones.h"

int main() {
    ArbolBinario arbol;
    int opcion, valor;


    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Insertar elemento\n";
        std::cout << "2. Eliminar elemento\n";
        std::cout << "3. Recorrido Inorden\n";
        std::cout << "4. Recorrido Postorden\n";
        std::cout << "5. Recorrido Preorden\n";
        std::cout << "6. Imprimir Arbol\n";
        std::cout << "7. Salir\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                system("cls");
                valor=ingresar_enteros("Ingrese el numero a Ingresar");
                arbol.insertar(valor);
                break;
            case 2:
                system("cls");
                valor=ingresar_enteros("Ingrese el numero a Eliminar");
                arbol.eliminar(valor);
                break;
            case 3:
                system("cls");
                std::cout << "Recorrido Inorden: ";
                arbol.recorridoInorden();
                break;
            case 4:
                system("cls");
                std::cout << "Recorrido PostOrden: ";
                arbol.recorridoPostorden();
                break;
            case 5:
                system("cls");
                std::cout << "Recorrido PreOrden: ";
                arbol.recorridoPreorden();
                break;
            case 6:
                system("cls");
                std::cout << "Imprimir: ";
                arbol.imprimirArbol();
                break;
            case 7:
                std::cout << "Saliendo del programa...\n";
                break;

            default:
                std::cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 8);

    return 0;
}
