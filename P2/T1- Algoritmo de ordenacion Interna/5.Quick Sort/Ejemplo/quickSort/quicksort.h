#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED
#include <iostream>

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
    Nodo(int valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}
};

class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada();
    ~ListaEnlazada();

    void insertar(int valor);
    void mostrar();
    void quicksort();

private:
    Nodo* obtenerUltimoNodo();
    Nodo* Particionar(Nodo* inicio, Nodo* fin);
    Nodo* QuicksortRecursivo(Nodo* inicio, Nodo* fin);
};


#endif // QUICKSORT_H_INCLUDED
