#include <iostream>
#include "ListaDobleEnlazada.h"

ListaDobleEnlazada::ListaDobleEnlazada() : cabeza(nullptr), cola(nullptr) {}

void ListaDobleEnlazada::insertarCabeza(int valor) {
    Nodo* nodoNuevo = new Nodo(valor, nullptr, nullptr);
    if (cabeza == nullptr) {
        cabeza = nodoNuevo;
        cola = nodoNuevo;
    } else {
        nodoNuevo->set_siguiente(cabeza);
        cabeza->set_anterior(nodoNuevo);
        cabeza = nodoNuevo;
    }
}

void ListaDobleEnlazada::insertarCola(int valor) {
    Nodo* nodoNuevo = new Nodo(valor, nullptr, nullptr);
    if (cabeza == nullptr) {
        cabeza = nodoNuevo;
        cola = nodoNuevo;
    } else {
        cola->set_siguiente(nodoNuevo);
        nodoNuevo->set_anterior(cola);
        cola = nodoNuevo;
    }
}

void ListaDobleEnlazada::insertarEntreCabezaYCola(int valor) {
    Nodo* nodoNuevo = new Nodo(valor, nullptr, nullptr);
    if (cabeza == nullptr) {
        cabeza = nodoNuevo;
        cola = nodoNuevo;
    } else {
        if (cabeza->get_siguiente() == nullptr) {
            nodoNuevo->set_anterior(cabeza);
            cabeza->set_siguiente(nodoNuevo);
            cola = nodoNuevo;
        } else {
            Nodo* nodoActual = cabeza->get_siguiente();
            cabeza->set_siguiente(nodoNuevo);
            nodoNuevo->set_anterior(cabeza);
            nodoNuevo->set_siguiente(nodoActual);
            nodoActual->set_anterior(nodoNuevo);
        }
    }
}

void ListaDobleEnlazada::imprimirLista() const {
    Nodo* actual = cabeza;
    std::cout << "Elementos de la lista: ";
    while (actual != nullptr) {
        std::cout << actual->get_valor() << " ";
        actual = actual->get_siguiente();
    }
    std::cout << std::endl;
}