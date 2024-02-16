#include <iostream>
#include "ListaSimple.h"
#include "Validacion.h"

int main(){
    Lista lista;
    do {
        system("cls");
        std::cout << "\n\tORDENAMIENTO BURBUJA CON LISTA SIMPLE\n\n" <<
            "1. Insertar al inicio\n" <<
            "2. Eliminar\n" <<
            "3. Mostrar\n" <<
            "4. Ordenamiento metodo burbuja\n" <<
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
            std::cout << std::endl;
            lista.imprimir();
            std::cout << std::endl;
            system("pause");
            break;
        case 4:
            lista.ordenarBurbuja();
            std::cout << std::endl;
            lista.imprimir();
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
