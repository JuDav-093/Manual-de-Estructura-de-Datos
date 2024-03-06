#include "Nodo.h"

Nodo::Nodo(int dato) : dato(dato), siguiente(nullptr) {}

int Nodo::obtenerDato() const {
    return dato;
}

Nodo* Nodo::obtenerSiguiente() const {
    return siguiente;
}

void Nodo::establecerSiguiente(Nodo* nodo) {
    siguiente = nodo;
}
