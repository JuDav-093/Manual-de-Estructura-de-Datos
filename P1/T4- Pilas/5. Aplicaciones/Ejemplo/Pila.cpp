#include <iostream>
#include "Pila.h"

template <typename T>
Pila<T>::Pila(Nodo<T>* _tope){
    tope = _tope;
}

template <typename T>
Pila<T>::Pila(){
    tope = nullptr;
}

template <typename T>
Nodo<T>* Pila<T>::get_tope(){
    return tope;
}

template <typename T>
void Pila<T>::agregar(T ndato){
    Nodo<T>* nuevo_nodo = new Nodo<T>();
    nuevo_nodo->set_valor(ndato);
    nuevo_nodo->set_siguiente(tope);
    tope = nuevo_nodo;
}

template <typename T>
void Pila<T>::eliminar(){
    Nodo<T>* aux = tope;
    tope = tope->get_siguiente();
    delete aux;
}

template <typename T>
void Pila<T>::imprimir(){
    Nodo<T>* aux = tope;
    std::cout << "\n";
    while(aux != nullptr){
        std::cout << aux->get_valor() << "\t";
        aux = aux->get_siguiente();
    }
}

template <typename T>
bool Pila<T>::esta_vacia(){
    return (tope == nullptr);
}
