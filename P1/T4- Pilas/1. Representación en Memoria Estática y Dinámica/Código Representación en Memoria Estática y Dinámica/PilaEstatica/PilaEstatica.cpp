#include "PilaEstatica.h"
#include <iostream>

PilaEstatica::PilaEstatica() : cima(-1) {}

void PilaEstatica::push(int valor) {
    if (cima < TAMANO_MAX - 1) {
        arreglo[++cima] = valor;
    } else {
        std::cout << "Desbordamiento de la pila\n";
    }
}

void PilaEstatica::pop() {
    if (cima >= 0) {
        --cima;
    } else {
        std::cout << "Subdesbordamiento de la pila\n";
    }
}

void PilaEstatica::imprimir() {
    std::cout << "Elementos en la pila:" << std::endl;
    for (int i = 0; i <= cima; ++i) {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;
}