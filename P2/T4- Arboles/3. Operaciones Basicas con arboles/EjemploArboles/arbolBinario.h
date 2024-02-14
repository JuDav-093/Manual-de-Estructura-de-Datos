#ifndef ARBOLBINARIO_H_INCLUDED
#define ARBOLBINARIO_H_INCLUDED
#include "Nodo.h"
class ArbolBinario {
private:
    Nodo* raiz;

    Nodo* insertar(Nodo* nodo, int valor);
    void inorden(Nodo* nodo);
    void preorden(Nodo* nodo);
    void postorden(Nodo* nodo);

    Nodo* encontrarMinimo(Nodo* nodo);
    Nodo* eliminar(Nodo* nodo, int valor);

    int altura(Nodo* nodo);
    int balance(Nodo* nodo);

    Nodo* rotacionDerecha(Nodo* y);
    Nodo* rotacionIzquierda(Nodo* x);

    Nodo* balancear(Nodo* nodo);
    void imprimirNodo(Nodo* nodo, int espacio);
    void imprimirArbol(Nodo* raiz, int espacio);

public:
    ArbolBinario();
    void insertar(int valor);
    void recorridoInorden();
    void recorridoPreorden();
    void recorridoPostorden();
    void eliminar(int valor);
    void balancearArbol();
    void imprimirArbol();
};


#endif // ARBOLBINARIO_H_INCLUDED
