#pragma once

#include "TreeNode.cpp"

enum class DireccionRecorrido {
    EnOrden,
    PostOrden,
    PreOrden
};

class ArbolRojoNegro {
public:
    ArbolRojoNegro();
    void insertar(int valor);
    void eliminar(int valor);
    int encontrar(int valor);
    int buscar(int valor);
    void recorrer(std::function<void(int)> callback, DireccionRecorrido direccion = DireccionRecorrido::EnOrden);
    void recorrer(std::function<void(NodoArbol*)> callback, DireccionRecorrido direccion = DireccionRecorrido::EnOrden);
    NodoArbol* obtener_raiz();
    int obtener_columna(NodoArbol* nodo);
    int obtener_fila(NodoArbol* nodo);
    NodoArbol* nodo_nulo = nullptr;
    

private:
    NodoArbol* raiz = nullptr;

    void eliminar(NodoArbol* nodo, int valor);
    int encontrar(NodoArbol* nodo, int valor);
    int buscar(NodoArbol* nodo, int valor);
    void recorrer(NodoArbol* nodo, std::function<void(int)> callback, DireccionRecorrido direccion = DireccionRecorrido::EnOrden);
    void recorrer(NodoArbol* nodo, std::function<void(NodoArbol*)> callback, DireccionRecorrido direccion = DireccionRecorrido::EnOrden);

    void corregir_insertar(NodoArbol* k);
    void corregir_eliminar(NodoArbol* x);
    void rotar_derecha(NodoArbol* x);
    void rotar_izquierda(NodoArbol* x);
    NodoArbol* minimo(NodoArbol* nodo);
    NodoArbol* maximo(NodoArbol* nodo);
    NodoArbol* sucesor(NodoArbol* nodo);
    void intercambiar(NodoArbol* u, NodoArbol* v);
};

