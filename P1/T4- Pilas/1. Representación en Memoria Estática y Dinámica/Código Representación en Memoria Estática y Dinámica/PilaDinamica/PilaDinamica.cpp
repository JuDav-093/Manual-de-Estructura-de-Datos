#include "PilaDinamica.h"
#include <iostream>

PilaDinamica::PilaDinamica() : cima(nullptr) {}

PilaDinamica::~PilaDinamica() {
    while (cima != nullptr) {
        Nodo* temp = cima;
        cima = cima->siguiente;
        delete temp;
    }
}

void PilaDinamica::push(int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = cima;
    cima = nuevo;
    std::cout << "Valor " << valor << " insertado en la pila\n";
}

void PilaDinamica::pop() {
    if (cima != nullptr) {
        Nodo* temp = cima;
        cima = cima->siguiente;
        std::cout << "Valor " << temp->dato << " eliminado de la pila\n";
        delete temp;
    } else {
        std::cout << "La pila esta vacia, no se puede eliminar ningún elemento\n";
    }
}

void PilaDinamica::imprimir() {
    if (cima != nullptr) {
        std::cout << "Elementos en la pila:\n";
        Nodo* temp = cima;
        while (temp != nullptr) {
            std::cout << temp->dato << "\n";
            temp = temp->siguiente;
        }
    } else {
        std::cout << "La pila esta vacia\n";
    }
}
