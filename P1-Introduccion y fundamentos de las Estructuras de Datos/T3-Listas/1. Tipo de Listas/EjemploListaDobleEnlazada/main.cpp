#include <iostream>
#include "ListaDoble.h"
#include "Validacion.h"

int main(){
    ListaDoble lista;
    do {
        system("cls");
        std::cout << "\n\tLISTA DOBLE ENLAZADA\n\n" <<
            "1. Insertar al inicio\n" <<
            "2. Eliminar\n" <<
            "3. Mostrar cabeza\n" <<
            "4. Mostrar cola\n" <<
            "5. Salir\n\n";
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
            lista.imprimirAdelante();
            std::cout << std::endl;
            system("pause");
            break;
        case 4:
            lista.imprimirAtras();
            std::cout << std::endl;
            system("pause");
            break;
        case 5:
            return 0;
        default:
            break;
        }
    } while (true);
}