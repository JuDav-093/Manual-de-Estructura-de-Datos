#pragma once
#include <iostream>
#include "Nodo.h"
using namespace std;

class ArbolBinario {
public:
    Nodo* crearNodo(int valor) {
        Nodo* nodo = new Nodo();
        nodo->valor = valor;
        nodo->izquierdo = NULL;
        nodo->derecho = NULL;

        return nodo;
    }

    Nodo* insertarNodo(Nodo* raiz, int valor) {
        if (raiz == NULL) {
            return crearNodo(valor);
        }

        if (valor < raiz->valor) {
            raiz->izquierdo = insertarNodo(raiz->izquierdo, valor);
        }
        else if (valor > raiz->valor) {
            raiz->derecho = insertarNodo(raiz->derecho, valor);
        }

        return raiz;
    }

    Nodo* encontrarNodoMinimo(Nodo* raiz) {
        Nodo* actual = raiz;

        while (actual->izquierdo != NULL) {
            actual = actual->izquierdo;
        }

        return actual;
    }

    Nodo* eliminarNodo(Nodo* raiz, int valor) {
        if (raiz == NULL) {
            return raiz;
        }

        if (valor < raiz->valor) {
            raiz->izquierdo = eliminarNodo(raiz->izquierdo, valor);
        }
        else if (valor > raiz->valor) {
            raiz->derecho = eliminarNodo(raiz->derecho, valor);
        }
        else {
            if (raiz->izquierdo == NULL) {
                Nodo* temp = raiz->derecho;
                delete raiz;
                return temp;
            }
            else if (raiz->derecho == NULL) {
                Nodo* temp = raiz->izquierdo;
                delete raiz;
                return temp;
            }

            Nodo* temp = encontrarNodoMinimo(raiz->derecho);
            raiz->valor = temp->valor;
            raiz->derecho = eliminarNodo(raiz->derecho, temp->valor);
        }

        return raiz;
    }

    Nodo* buscarNodo(Nodo* raiz, int valor) {
        if (raiz == NULL || raiz->valor == valor) {
            return raiz;
        }
        if (raiz->valor < valor) {
            return buscarNodo(raiz->derecho, valor);
        }
        return buscarNodo(raiz->izquierdo, valor);
    }

    void inorden(Nodo* raiz) {
        if (raiz != NULL) {
            inorden(raiz->izquierdo);
            cout << raiz->valor << " ";
            inorden(raiz->derecho);
        }
    }
};
