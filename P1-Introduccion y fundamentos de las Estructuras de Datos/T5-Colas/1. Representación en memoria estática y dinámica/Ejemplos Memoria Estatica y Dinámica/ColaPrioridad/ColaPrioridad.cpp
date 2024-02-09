#include "ColaPrioridad.h"
#include <iostream>

ColaPrioridad::ColaPrioridad() : frente(nullptr), fin(nullptr) {}

ColaPrioridad::~ColaPrioridad() {
    while (frente != nullptr) {
        Nodo* temp = frente;
        frente = frente->getSiguiente();
        delete temp;
    }
}

void ColaPrioridad::encolar(int valor, int prioridad) {
    Nodo* nuevo = new Nodo(valor, prioridad);

    if (frente == nullptr || prioridad < frente->getPrioridad()) {
        nuevo->setSiguiente(frente);
        frente = nuevo;
    } else {
        Nodo* actual = frente;
        while (actual->getSiguiente() != nullptr && actual->getSiguiente()->getPrioridad() <= prioridad) {
            actual = actual->getSiguiente();
        }
        nuevo->setSiguiente(actual->getSiguiente());
        actual->setSiguiente(nuevo);
    }
}

void ColaPrioridad::desencolar() {
    if (frente != nullptr) {
        Nodo* temp = frente;
        frente = frente->getSiguiente();
        delete temp;
    } else {
        std::cout << "La cola esta vacia, no se puede desencolar\n";
    }
}

void ColaPrioridad::imprimir() {
    Nodo* temp = frente;
    while (temp != nullptr) {
        std::cout << temp->getDato() << " ";
        temp = temp->getSiguiente();
    }
    std::cout << "\n";
}
