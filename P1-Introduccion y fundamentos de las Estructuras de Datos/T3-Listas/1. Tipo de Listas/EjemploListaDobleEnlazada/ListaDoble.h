#pragma once
#include <iostream>

// Definición de la clase NodoDoble
class NodoDoble {
public:
    int dato;
    NodoDoble* siguiente;
    NodoDoble* anterior;

    // Constructor
    NodoDoble(int valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}
};

// Clase ListaDoble que contiene operaciones básicas
class ListaDoble {
private:
    NodoDoble* cabeza;

public:
    // Constructor
    ListaDoble() {
        cabeza = nullptr;
    }

    // Método para insertar un elemento al inicio de la lista
    void insertarAlInicio(int valor) {
        NodoDoble* nuevoNodo = new NodoDoble(valor);
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
        }
        else {
            nuevoNodo->siguiente = cabeza;
            cabeza->anterior = nuevoNodo;
            cabeza = nuevoNodo;
        }
    }

    // Método para imprimir la lista de principio a fin
    void imprimirAdelante() {
        NodoDoble* temp = cabeza;
        while (temp != nullptr) {
            std::cout << temp->dato << " <-> ";
            temp = temp->siguiente;
        }
        std::cout << "NULL" << std::endl;
    }

    // Método para imprimir la lista de fin a principio
    void imprimirAtras() {
        NodoDoble* temp = cabeza;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        while (temp != nullptr) {
            std::cout << temp->dato << " <-> ";
            temp = temp->anterior;
        }
        std::cout << "NULL" << std::endl;
    }

    void eliminar(int valor) {
        NodoDoble* temp = cabeza;
        NodoDoble* prev = nullptr;

        // Buscar el nodo con el valor dado
        while (temp != nullptr && temp->dato != valor) {
            prev = temp;
            temp = temp->siguiente;
        }

        // Si el valor no se encuentra en la lista, no hay nada que eliminar
        if (temp == nullptr) {
            std::cout << "El elemento " << valor << " no esta en la lista." << std::endl;
            return;
        }

        // Eliminar el nodo encontrado
        if (prev != nullptr)
            prev->siguiente = temp->siguiente;
        else
            cabeza = temp->siguiente;

        if (temp->siguiente != nullptr)
            temp->siguiente->anterior = prev;

        delete temp;
    }

    // Destructor para liberar la memoria asignada a los nodos de la lista
    ~ListaDoble() {
        NodoDoble* temp = cabeza;
        while (temp != nullptr) {
            NodoDoble* siguiente = temp->siguiente;
            delete temp;
            temp = siguiente;
        }
        cabeza = nullptr;
    }
};