#pragma once

#include <iostream>

void mostrar(int);

void mostrar(int opcion) {
    system("cls");
    std::cout << "\n--------------N REINAS-----------------\n";
    std::cout << "\nSeleccione una opcion:\n\n";
    std::cout << (opcion == 1 ? "> " : "  ") << "Solucionar\n";
    std::cout << (opcion == 2 ? "> " : "  ") << "Salir\n";
}
