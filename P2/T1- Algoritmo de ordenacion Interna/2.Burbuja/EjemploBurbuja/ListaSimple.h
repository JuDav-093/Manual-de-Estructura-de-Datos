#pragma once
#include <iostream>
#include "Nodo.h"

// Clase Lista que contiene operaciones b�sicas
class Lista {
private:
    Nodo* cabeza;

public:
    // Constructor
    Lista();

    // M�todo para insertar un elemento al inicio de la lista
    void insertarAlInicio(int valor);

    // M�todo para imprimir la lista
    void imprimir();

    // M�todo para eliminar un elemento de la lista dada una clave (valor)
    void eliminar(int clave);

    // M�todo para ordenar la lista usando el algoritmo de burbuja
    void ordenarBurbuja();

    // Destructor para liberar la memoria asignada a los nodos de la lista
    ~Lista();
};

