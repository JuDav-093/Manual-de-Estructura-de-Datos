#include "arbolBinario.h"
#include "Nodo.cpp"
#include <algorithm>
#include <iostream>

ArbolBinario::ArbolBinario() : raiz(nullptr) {

}

Nodo* ArbolBinario::insertar(Nodo* nodo, int valor) {
    if (nodo == nullptr) {
        return new Nodo(valor);
    }

    if (valor < nodo->dato) {
        nodo->izquierda = insertar(nodo->izquierda, valor);
    } else if (valor > nodo->dato) {
        nodo->derecha = insertar(nodo->derecha, valor);
    }else if (valor = nodo->dato) {
        nodo->derecha = insertar(nodo->derecha, valor);
    }

    return nodo;
}

void ArbolBinario::inorden(Nodo* nodo) {
    if (nodo != nullptr) {
        inorden(nodo->izquierda);
        std::cout << nodo->dato << " ";
        inorden(nodo->derecha);
    }
}

void ArbolBinario::preorden(Nodo* nodo) {
    if (nodo != nullptr) {
        std::cout << nodo->dato << " ";
        preorden(nodo->izquierda);
        preorden(nodo->derecha);
    }
}

void ArbolBinario::postorden(Nodo* nodo) {
    if (nodo != nullptr) {
        postorden(nodo->izquierda);
        postorden(nodo->derecha);
        std::cout << nodo->dato << " ";
    }
}

Nodo* ArbolBinario::encontrarMinimo(Nodo* nodo) {
    while (nodo->izquierda != nullptr) {
        nodo = nodo->izquierda;
    }
    return nodo;
}

Nodo* ArbolBinario::eliminar(Nodo* nodo, int valor) {
    if (nodo == nullptr) {
        return nodo;
    }

    if (valor < nodo->dato) {
        nodo->izquierda = eliminar(nodo->izquierda, valor);
    } else if (valor > nodo->dato) {
        nodo->derecha = eliminar(nodo->derecha, valor);
    } else {
        if (nodo->izquierda == nullptr) {
            Nodo* temp = nodo->derecha;
            delete nodo;
            return temp;
        } else if (nodo->derecha == nullptr) {
            Nodo* temp = nodo->izquierda;
            delete nodo;
            return temp;
        }

        Nodo* temp = encontrarMinimo(nodo->derecha);
        nodo->dato = temp->dato;
        nodo->derecha = eliminar(nodo->derecha, temp->dato);
    }

    return nodo;
}

void ArbolBinario::insertar(int valor) {
    raiz = insertar(raiz, valor);
}

void ArbolBinario::recorridoInorden() {
    inorden(raiz);
    std::cout << std::endl;
}

void ArbolBinario::recorridoPreorden() {
    preorden(raiz);
    std::cout << std::endl;
}

void ArbolBinario::recorridoPostorden() {
    postorden(raiz);
    std::cout << std::endl;
}

void ArbolBinario::eliminar(int valor) {
    raiz = eliminar(raiz, valor);
}
int ArbolBinario::altura(Nodo* nodo) {
    if (nodo == nullptr)
        return 0;
    return nodo->altura;
}

int ArbolBinario::balance(Nodo* nodo) {
    if (nodo == nullptr)
        return 0;
    return altura(nodo->izquierda) - altura(nodo->derecha);
}

Nodo* ArbolBinario::rotacionDerecha(Nodo* y) {
    Nodo* x = y->izquierda;
    Nodo* T2 = x->derecha;

    // Realizar rotación
    x->derecha = y;
    y->izquierda = T2;

    // Actualizar alturas
    y->altura = std::max(altura(y->izquierda), altura(y->derecha)) + 1;
    x->altura = std::max(altura(x->izquierda), altura(x->derecha)) + 1;

    return x;
}

Nodo* ArbolBinario::rotacionIzquierda(Nodo* x) {
    Nodo* y = x->derecha;
    Nodo* T2 = y->izquierda;

    // Realizar rotación
    y->izquierda = x;
    x->derecha = T2;

    // Actualizar alturas
    x->altura = std::max(altura(x->izquierda), altura(x->derecha)) + 1;
    y->altura = std::max(altura(y->izquierda), altura(y->derecha)) + 1;

    return y;
}

Nodo* ArbolBinario::balancear(Nodo* nodo) {
    // Actualizar la altura de este nodo
    nodo->altura = std::max(altura(nodo->izquierda), altura(nodo->derecha)) + 1;

    // Obtener el factor de equilibrio de este nodo
    int factorEquilibrio = balance(nodo);

    // Caso izquierda-izquierda
    if (factorEquilibrio > 1 && balance(nodo->izquierda) >= 0) {
        return rotacionDerecha(nodo);
    }

    // Caso derecha-derecha
    if (factorEquilibrio < -1 && balance(nodo->derecha) <= 0) {
        return rotacionIzquierda(nodo);
    }

    // Caso izquierda-derecha
    if (factorEquilibrio > 1 && balance(nodo->izquierda) < 0) {
        nodo->izquierda = rotacionIzquierda(nodo->izquierda);
        return rotacionDerecha(nodo);
    }

    // Caso derecha-izquierda
    if (factorEquilibrio < -1 && balance(nodo->derecha) > 0) {
        nodo->derecha = rotacionDerecha(nodo->derecha);
        return rotacionIzquierda(nodo);
    }

    // No se requiere equilibrado
    return nodo;
}


void ArbolBinario::balancearArbol() {
    raiz = balancear(raiz);
}


void ArbolBinario::imprimirNodo(Nodo* nodo, int espacio) {
    if (nodo == nullptr) {
        return;
    }

    espacio += 5;

    imprimirNodo(nodo->derecha, espacio);

    std::cout << nodo->dato << " "; // Imprimir el nodo

    imprimirNodo(nodo->izquierda, espacio);
}

void ArbolBinario::imprimirArbol(Nodo* raiz, int espacio) {
     if (raiz == nullptr) {
        return;
    }

    imprimirArbol(raiz->derecha, espacio + 5);

    for (int i = 5; i < espacio; i++) {
        std::cout << " ";
    }

    std::cout << raiz->dato << "\n";

    imprimirArbol(raiz->izquierda, espacio + 5);
}

void ArbolBinario::imprimirArbol() {
    imprimirNodo(raiz, 0);
}

