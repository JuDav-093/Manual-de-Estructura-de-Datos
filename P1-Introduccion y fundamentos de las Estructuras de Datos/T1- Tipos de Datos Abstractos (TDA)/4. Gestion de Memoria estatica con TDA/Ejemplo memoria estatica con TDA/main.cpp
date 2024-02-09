#include <iostream>
#include "Vector.h"
#include "Validacion.h"

int main()
{
    std::cout << "\n\tMEMORIA ESTATICA CON TDA\n\n";
    int tamanoVector = ingresar_enteros("Ingresar el tamanio de la vector:  ");
    Vector vec(tamanoVector);
    do {
        system("cls");
        std::cout << "\n\tMEMORIA ESTATICA CON TDA\n\n" <<
            "1. Agregar\n" <<
            "2. Eliminar\n" <<
            "3. Mostrar\n" <<
            "4. Salir\n\n";
        switch (ingresar_enteros("Ingresar la opcion:  ")) {
        case 1:
            vec.insertar(ingresar_enteros("\n\nIngresar un numero:  "));
            break;
        case 2:
            vec.eliminar(ingresar_enteros("\n\nIngresar el numero a eliminar:  "));
            break;
        case 3:
            vec.imprimir();
            break;
        case 4:
            return 0;
        default:
            break;
        }
    } while (true);
}
