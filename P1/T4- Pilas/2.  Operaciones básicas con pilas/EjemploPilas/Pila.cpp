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
void Pila<T>::obtener_tope(){
    if (esta_vacia()) {
        std::cout<<"La pila esta vacia"<<std::endl;
       
    }else{
        std::cout<<tope->get_valor()<<std::endl;

    }
       
        
        
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
bool Pila<T>::esta_vacia(){
    return (tope == nullptr);
}

template <typename T>
void Pila<T>::imprimir()
{
    Nodo<T>* aux = tope;
    std::cout << "\n";
    if (esta_vacia()){

        std::cout<<"La pila esta vacia"<<std::endl;

    }else{
        while(aux != nullptr){
        std::cout << aux->get_valor() << "\t"<<std::endl;
        aux = aux->get_siguiente();
    }
    }
}

template <typename T>
void Pila<T>::suma_de_elementos()
{
    Nodo<T>* aux = tope;
    T suma=0;
    std::cout << "\n";
    if (esta_vacia()){

        std::cout<<"La pila esta vacia"<<std::endl;

    }else{
        while(aux != nullptr){
        suma += aux->get_valor();
        aux = aux->get_siguiente();
    }
        std::cout << "La suma es: " <<suma<<std::endl;
    }
}

