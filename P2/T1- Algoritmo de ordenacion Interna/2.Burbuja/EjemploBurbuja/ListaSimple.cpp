#include <iostream>
#include "ListaSimple.h"

Lista::Lista() {
    cabeza = nullptr;
}

// Método para insertar un elemento al inicio de la lista
void Lista::insertarAlInicio(int valor) {
    Nodo* nuevoNodo = new Nodo(valor);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

// Método para imprimir la lista
void Lista::imprimir() {
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        std::cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }
    std::cout << "NULL" << std::endl;
}

// Método para eliminar un elemento de la lista dada una clave (valor)
void Lista::eliminar(int clave) {
    Nodo* temp = cabeza;
    Nodo* prev = nullptr;

    // Buscar el nodo con la clave dada
    while (temp != nullptr && temp->dato != clave) {
        prev = temp;
        temp = temp->siguiente;
    }

    // Si la clave no se encuentra en la lista, no hay nada que eliminar
    if (temp == nullptr) {
        std::cout << "\nEl elemento " << clave << " no esta en la lista." << std::endl;
        return;
    }

    // Eliminar el nodo encontrado
    if (prev != nullptr)
        prev->siguiente = temp->siguiente;
    else
        cabeza = temp->siguiente;

    delete temp;
}

// Método para ordenar la lista usando el algoritmo de burbuja
void Lista::ordenarBurbuja() {
    if (cabeza == nullptr || cabeza->siguiente == nullptr) {
        // La lista está vacía o tiene solo un elemento, no es necesario ordenar
        return;
    }

    bool intercambiado;
    Nodo* actual;
    Nodo* anterior = nullptr;

    do {
        intercambiado = false;
        actual = cabeza;

        while (actual->siguiente != anterior) {
            if (actual->dato > actual->siguiente->dato) {
                // Intercambiar los valores de los nodos
                int temp = actual->dato;
                actual->dato = actual->siguiente->dato;
                actual->siguiente->dato = temp;
                intercambiado = true;
            }
            actual = actual->siguiente;
        }
        anterior = actual;
    } while (intercambiado);
}

// Destructor para liberar la memoria asignada a los nodos de la lista
Lista::~Lista() {
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        Nodo* siguiente = temp->siguiente;
        delete temp;
        temp = siguiente;
    }
    cabeza = nullptr;
}