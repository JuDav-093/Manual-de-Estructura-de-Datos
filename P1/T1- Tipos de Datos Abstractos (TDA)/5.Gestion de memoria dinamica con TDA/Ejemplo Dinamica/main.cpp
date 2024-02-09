#include <iostream>
#include "Operaciones.h"

int main() {
    std::cout << "Taller Numero 3 Memoria Estatica Vectores" << std::endl;
    Operaciones op;
    op.encerar();
    op.ingresar();
    std::cout << "Promedio: " << op.procesar() << std::endl;
    op.imprimir();
    return 0;
}

