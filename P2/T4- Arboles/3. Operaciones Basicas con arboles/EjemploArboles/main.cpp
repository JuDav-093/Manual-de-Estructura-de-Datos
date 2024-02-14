#include "arbolBinario.h"
#include <iostream>
#include "Validaciones.h"

int main() {
    ArbolBinario arbol;
    int opcion, valor;

    do {
        system("cls");
        std::cout << "\nMenu:\n";
        std::cout << "1. Insertar elemento\n";
        std::cout << "2. Eliminar elemento\n";
        std::cout << "3. Recorrido Inorden\n";
        std::cout << "4. Recorrido Postorden\n";
        std::cout << "5. Recorrido Preorden\n";
        std::cout << "6. Balancear\n";
        std::cout << "7. Imprimir Arbol\n";
        std::cout << "8. Salir\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                valor=ingresar_enteros("Ingrese el numero a Ingresar");
                arbol.insertar(valor);
                break;
            case 2:
                valor=ingresar_enteros("Ingrese el numero a Eliminar");
                arbol.eliminar(valor);
                break;
            case 3:
                std::cout << "Recorrido Inorden: ";
                arbol.recorridoInorden();
                std::cout << std::endl;
                system("pause");
                break;
            case 4:
                std::cout << "Recorrido PostOrden: ";
                arbol.recorridoPostorden();
                std::cout << std::endl;
                system("pause");
                break;
            case 5:
                std::cout << "Recorrido PreOrden: ";
                arbol.recorridoPreorden();
                std::cout << std::endl;
                system("pause");
                break;
            case 6:
                std::cout << "Balancear: ";
                arbol.balancearArbol();
                break;
            case 7:
                std::cout << "Imprimir: ";
                arbol.imprimirArbol();
                std::cout << std::endl;
                system("pause");
                break;
            case 8:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 8);
    return 0;
}
