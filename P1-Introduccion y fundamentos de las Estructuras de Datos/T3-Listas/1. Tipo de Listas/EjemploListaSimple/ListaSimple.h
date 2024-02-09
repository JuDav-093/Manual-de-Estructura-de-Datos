#pragma once
#include <iostream>

// Definici�n de la clase Nodo
class Nodo {
public:
    int dato;
    Nodo* siguiente;

    // Constructor
    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

// Clase Lista que contiene operaciones b�sicas
class Lista {
private:
    Nodo* cabeza;

public:
    // Constructor
    Lista() {
        cabeza = nullptr;
    }

    // M�todo para insertar un elemento al inicio de la lista
    void insertarAlInicio(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    // M�todo para imprimir la lista
    void imprimir() {
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            std::cout << temp->dato << " -> ";
            temp = temp->siguiente;
        }
        std::cout << "NULL" << std::endl;
    }

    // M�todo para eliminar un elemento de la lista dada una clave (valor)
    void eliminar(int clave) {
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

    // Destructor para liberar la memoria asignada a los nodos de la lista
    ~Lista() {
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            Nodo* siguiente = temp->siguiente;
            delete temp;
            temp = siguiente;
        }
        cabeza = nullptr;
    }
};

