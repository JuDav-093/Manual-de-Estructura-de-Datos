#pragma once

#include <string>
#include "ListaDoble.h"
#include "Nodo.h"

template <typename T>

class TablaHash
{
public:
    TablaHash(int);
    void insertar(T, int);
    void insertar(T dato, std::string hashear_cadena);
    Nodo<T>* buscar(T, int);
    Nodo<T>* buscar_mapa(std::string hashear_cadena);
    Nodo<T>* buscar(int);
    void eliminar(T);
    void imprimir();
    ~TablaHash();

protected:

private:
    int tam;
    ListaDoble<T>** listas_indices;
};



