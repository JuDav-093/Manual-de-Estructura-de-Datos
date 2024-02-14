#include <iostream>
#include "Validacion.h"
#include "Archivo.h"
#include "MezclaNatural.h"

int main(){
    std::vector<std::string> listaNombres;
    do {
        system("cls");
        std::cout << "\n\tMEZCLA NATURAL\n\n" <<
            "1. Agregar Nombre\n" <<
            "2. Mostrar Nombres\n" <<
            "3. Ordenar\n" <<
            "4. Salir\n\n";
        switch (ingresar_enteros("Ingresar la opcion:  ")) {
        case 1:
            agregar(ingresarNombre("\n\nIngresar un nombre (ej. Juan):  "));
            break;
        case 2:
            system("cls");
            mostrar();
            std::cout << std::endl;
            system("pause");
            break;
        case 3:
            system("cls");
            listaNombres = obtenerNombres();
            externalMergeSort(listaNombres, 0, listaNombres.size() - 1);
            std::cout << "Nombres:" << std::endl;
            for (int i = 0; i < listaNombres.size(); i++) {
                std::cout << listaNombres.at(i) << std::endl;
            }
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