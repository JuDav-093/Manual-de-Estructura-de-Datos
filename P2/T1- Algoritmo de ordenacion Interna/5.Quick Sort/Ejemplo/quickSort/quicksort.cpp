#include "quicksort.h"

ListaEnlazada::ListaEnlazada() : cabeza(nullptr) {}

ListaEnlazada::~ListaEnlazada() {
    while (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

void ListaEnlazada::insertar(int valor) {
    Nodo* nuevoNodo = new Nodo(valor);
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    } else {
        Nodo* temp = cabeza;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
        nuevoNodo->anterior = temp;
    }
}

void ListaEnlazada::mostrar() {
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        std::cout << temp->dato << " ";
        temp = temp->siguiente;
    }
    std::cout << "\n";
}

void ListaEnlazada::quicksort() {
    cabeza = QuicksortRecursivo(cabeza, obtenerUltimoNodo());
}

Nodo* ListaEnlazada::obtenerUltimoNodo() {
    Nodo* temp = cabeza;
    while (temp != nullptr && temp->siguiente != nullptr) {
        temp = temp->siguiente;
    }
    return temp;
}

Nodo* ListaEnlazada::Particionar(Nodo* inicio, Nodo* fin) {
    int pivote = fin->dato;
    Nodo* i = inicio->anterior;

    for (Nodo* j = inicio; j != fin; j = j->siguiente) {
        if (j->dato <= pivote) {
            i = (i == nullptr) ? inicio : i->siguiente;
            std::swap(i->dato, j->dato);
        }
    }

    i = (i == nullptr) ? inicio : i->siguiente;
    std::swap(i->dato, fin->dato);
    return i;
}

Nodo* ListaEnlazada::QuicksortRecursivo(Nodo* inicio, Nodo* fin) {
    if (inicio != nullptr && inicio != fin && inicio != fin->siguiente) {
        Nodo* pivote = Particionar(inicio, fin);
        QuicksortRecursivo(inicio, pivote->anterior);
        QuicksortRecursivo(pivote->siguiente, fin);
    }

    return inicio;
}
