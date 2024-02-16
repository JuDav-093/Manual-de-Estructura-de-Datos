#pragma once
#include <iostream>
#include "Nodo.h"

// Clase Lista que contiene operaciones básicas
class Lista {
private:
    Nodo* cabeza;

public:
    // Constructor
    Lista();

    // Método para insertar un elemento al inicio de la lista
    void insertarAlInicio(int valor);

    // Método para imprimir la lista
    void imprimir();

    // Método para eliminar un elemento de la lista dada una clave (valor)
    void eliminar(int clave);

    // Método para ordenar la lista usando el algoritmo de burbuja
    void ordenarBurbuja();

    // Destructor para liberar la memoria asignada a los nodos de la lista
    ~Lista();
};

