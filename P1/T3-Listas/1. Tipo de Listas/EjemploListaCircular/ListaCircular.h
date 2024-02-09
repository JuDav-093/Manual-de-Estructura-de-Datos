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

// Clase ListaCircular que contiene operaciones b�sicas
class ListaCircular {
private:
    Nodo* cabeza;

public:
    // Constructor
    ListaCircular() : cabeza(nullptr) {}

    // M�todo para verificar si la lista est� vac�a
    bool estaVacia() {
        return cabeza == nullptr;
    }

    // M�todo para insertar un elemento al inicio de la lista
    void insertarAlInicio(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (estaVacia()) {
            nuevoNodo->siguiente = nuevoNodo;
            cabeza = nuevoNodo;
        }
        else {
            nuevoNodo->siguiente = cabeza->siguiente;
            cabeza->siguiente = nuevoNodo;
        }
    }

    // M�todo para imprimir la lista
    void imprimir() {
        if (estaVacia()) {
            std::cout << "La lista est� vac�a." << std::endl;
            return;
        }

        Nodo* temp = cabeza->siguiente;
        std::cout << "Lista: ";
        do {
            std::cout << temp->dato << " -> ";
            temp = temp->siguiente;
        } while (temp != cabeza->siguiente);
        std::cout << "(Cabeza)" << std::endl;
    }

    // M�todo para eliminar un elemento de la lista dada una clave (valor)
    void eliminar(int clave) {
        if (estaVacia()) {
            std::cout << "La lista est� vac�a." << std::endl;
            return;
        }

        Nodo* temp = cabeza;
        Nodo* prev = nullptr;

        // Buscar el nodo con la clave dada
        do {
            prev = temp;
            temp = temp->siguiente;
            if (temp->dato == clave) {
                prev->siguiente = temp->siguiente;
                if (temp == cabeza)
                    cabeza = prev;
                delete temp;
                std::cout << "Elemento " << clave << " eliminado." << std::endl;
                return;
            }
        } while (temp != cabeza->siguiente);

        std::cout << "Elemento " << clave << " no encontrado en la lista." << std::endl;
    }

    // Destructor para liberar la memoria asignada a los nodos de la lista
    ~ListaCircular() {
        if (!estaVacia()) {
            Nodo* temp = cabeza->siguiente;
            while (temp != cabeza) {
                Nodo* siguiente = temp->siguiente;
                delete temp;
                temp = siguiente;
            }
            delete cabeza;
            cabeza = nullptr;
        }
    }
};
