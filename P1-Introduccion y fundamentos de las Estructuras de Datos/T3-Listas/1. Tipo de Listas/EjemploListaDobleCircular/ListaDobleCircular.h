#pragma once
#include <iostream>

// Definici�n de la clase Nodo
class Nodo {
public:
    int dato;
    Nodo* siguiente;
    Nodo* anterior;

    // Constructor
    Nodo(int valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}
};

// Clase ListaDobleCircular que contiene operaciones b�sicas
class ListaDobleCircular {
private:
    Nodo* cabeza;

public:
    // Constructor
    ListaDobleCircular() : cabeza(nullptr) {}

    // M�todo para verificar si la lista est� vac�a
    bool estaVacia() {
        return cabeza == nullptr;
    }

    // M�todo para insertar un elemento al inicio de la lista
    void insertarAlInicio(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (estaVacia()) {
            nuevoNodo->siguiente = nuevoNodo;
            nuevoNodo->anterior = nuevoNodo;
            cabeza = nuevoNodo;
        }
        else {
            nuevoNodo->siguiente = cabeza;
            nuevoNodo->anterior = cabeza->anterior;
            cabeza->anterior->siguiente = nuevoNodo;
            cabeza->anterior = nuevoNodo;
            cabeza = nuevoNodo;
        }
    }

    // M�todo para imprimir la lista
    void imprimir() {
        if (estaVacia()) {
            std::cout << "La lista est� vac�a." << std::endl;
            return;
        }

        Nodo* temp = cabeza;
        std::cout << "Lista hacia adelante: ";
        do {
            std::cout << temp->dato << " <-> ";
            temp = temp->siguiente;
        } while (temp != cabeza);
        std::cout << "(Cabeza)" << std::endl;

        temp = cabeza->anterior;
        std::cout << "Lista hacia atr�s: ";
        do {
            std::cout << temp->dato << " <-> ";
            temp = temp->anterior;
        } while (temp != cabeza->anterior);
        std::cout << "(Cabeza)" << std::endl;
    }

    // M�todo para eliminar un elemento de la lista dada una clave (valor)
    void eliminar(int clave) {
        if (estaVacia()) {
            std::cout << "La lista est� vac�a." << std::endl;
            return;
        }

        Nodo* temp = cabeza;
        do {
            if (temp->dato == clave) {
                if (temp == cabeza) {
                    cabeza = temp->siguiente;
                }
                temp->anterior->siguiente = temp->siguiente;
                temp->siguiente->anterior = temp->anterior;
                delete temp;
                std::cout << "Elemento " << clave << " eliminado." << std::endl;
                return;
            }
            temp = temp->siguiente;
        } while (temp != cabeza);
        std::cout << "Elemento " << clave << " no encontrado en la lista." << std::endl;
    }

    // Destructor para liberar la memoria asignada a los nodos de la lista
    ~ListaDobleCircular() {
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