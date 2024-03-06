#include "ListaSimple.h"
#include <iostream>

ListaSimple::ListaSimple() : inicio(nullptr) {}

ListaSimple::~ListaSimple() {
    while (inicio != nullptr) {
        Nodo* temp = inicio;
        inicio = inicio->siguiente;
        delete temp;
    }
}

void ListaSimple::agregarElemento(int valor) {
    Nodo* nuevoNodo = new Nodo(valor);
    nuevoNodo->siguiente = inicio;
    inicio = nuevoNodo;
}

void ListaSimple::intercambiar(Nodo* a, Nodo* b) {
    int temp = a->dato;
    a->dato = b->dato;
    b->dato = temp;
}

void ListaSimple::ordenarBurbuja() {
    if (!inicio || !inicio->siguiente) {
        return;
    }

    bool intercambio;
    Nodo* actual;
    Nodo* siguiente = nullptr;

    do {
        intercambio = false;
        actual = inicio;

        while (actual->siguiente != siguiente) {
            if (actual->dato > actual->siguiente->dato) {
                intercambiar(actual, actual->siguiente);
                intercambio = true;
            }
            actual = actual->siguiente;
        }
        siguiente = actual;

    } while (intercambio);
}

void ListaSimple::mostrarLista() {
    Nodo* temp = inicio;
    while (temp != nullptr) {
        std::cout << temp->dato << " ";
        temp = temp->siguiente;
    }
    std::cout << std::endl;
}
