#include "Nodo.h"

Nodo::Nodo(int valor) : dato(valor), siguiente(nullptr) {}

int Nodo::getDato() const {
    return dato;
}

void Nodo::setDato(int valor) {
    dato = valor;
}

Nodo* Nodo::getSiguiente() const {
    return siguiente;
}

void Nodo::setSiguiente(Nodo* siguiente) {
    this->siguiente = siguiente;
}

