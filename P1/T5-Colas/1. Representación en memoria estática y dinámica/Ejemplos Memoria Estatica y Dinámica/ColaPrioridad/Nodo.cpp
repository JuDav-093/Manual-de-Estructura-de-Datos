#include "Nodo.h"

Nodo::Nodo(int valor, int prioridad) : dato(valor), prioridad(prioridad), siguiente(nullptr) {}

int Nodo::getDato() {
    return dato;
}

int Nodo::getPrioridad() {
    return prioridad;
}

Nodo* Nodo::getSiguiente() {
    return siguiente;
}

void Nodo::setSiguiente(Nodo* nodo) {
    siguiente = nodo;
}
