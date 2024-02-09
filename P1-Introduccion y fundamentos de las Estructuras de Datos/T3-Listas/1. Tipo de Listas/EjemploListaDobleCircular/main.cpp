#include <iostream>
#include "ListaDobleCircular.h"
#include "Validacion.h"

int main(){
    ListaDobleCircular lista;
    do {
        system("cls");
        std::cout << "\n\tLISTA DOBLE CIRCULAR\n\n" <<
            "1. Insertar al inicio\n" <<
            "2. Eliminar\n" <<
            "3. Mostrar\n" <<
            "4. Salir\n\n";
        switch (ingresar_enteros("Ingresar la opcion:  ")) {
        case 1:
            lista.insertarAlInicio(ingresar_enteros("\n\nIngresar un numero:  "));
            std::cout << std::endl;
            system("pause");
            break;
        case 2:
            lista.eliminar(ingresar_enteros("\n\nIngresar el numero a eliminar:  "));
            std::cout << std::endl;
            system("pause");
            break;
        case 3:
            lista.imprimir();
            std::cout << std::endl;
            system("pause");
            break;
        case 4:
            return 0;
        default:
            break;
        }
    } while (true);
}