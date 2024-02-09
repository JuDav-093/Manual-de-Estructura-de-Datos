#include "Nodo.h"

Nodo::Nodo(int valor) : dato(valor), siguiente(nullptr) {}

int Nodo::getDato() {
    return dato;
}

Nodo* Nodo::getSiguiente() {
    return siguiente;
}

void Nodo::setSiguiente(Nodo* nodo) {
    siguiente = nodo;
}
