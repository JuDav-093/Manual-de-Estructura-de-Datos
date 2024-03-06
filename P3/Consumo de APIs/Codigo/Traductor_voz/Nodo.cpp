/***********************************************************************
 UFA - ESPE
 * Module:  Nodo.cpp
 * Author:  Joan Cobeña, Edison Verdesoto
 * Modified: jueves, 7 de diciembre de 2023 01:11:27 p. m.
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/

#include "Nodo.h"

template <typename T>
Nodo<T>::Nodo(T _valor, Nodo<T>* _siguiente, Nodo<T>* _anterior)
{
    valor = _valor;
    siguiente = _siguiente;
    anterior = _anterior;
}


template <typename T>
Nodo<T>::Nodo(T _valor, Nodo<T>* _siguiente)
{
    valor = _valor;
    siguiente = _siguiente;
}

template <typename T>
Nodo<T>::Nodo()
{
}

template <typename T>
Nodo<T>::~Nodo()
{
    // TODO : implement
}

template <typename T>
T Nodo<T>::get_valor()
{
    return valor;
}

template <typename T>
void Nodo<T>::set_valor(T new_valor)
{
    valor = new_valor;
}

template <typename T>
Nodo<T>* Nodo<T>::get_siguiente()
{
    return siguiente;
}

template <typename T>
void Nodo<T>::set_siguiente(Nodo<T>* new_siguiente)
{
    siguiente = new_siguiente;
}

template <typename T>
Nodo<T>* Nodo<T>::get_anterior()
{
    return anterior;
}

template <typename T>
void Nodo<T>::set_anterior(Nodo<T>* new_anterior)
{
    anterior = new_anterior;
}
