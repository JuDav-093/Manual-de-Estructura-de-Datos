#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include "Nodo.cpp"

class ListaSimple {
private:
    Nodo* inicio;

public:
    ListaSimple();
    ~ListaSimple();

    void agregarElemento(int valor);
    void intercambiar(Nodo* a, Nodo* b);
    void ordenarBurbuja();
    void mostrarLista();
};

#endif 
