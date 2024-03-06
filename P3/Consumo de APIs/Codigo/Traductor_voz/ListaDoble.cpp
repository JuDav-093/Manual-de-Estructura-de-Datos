/***********************************************************************
 UFA - ESPE
 * Module:  ListaDoble.cpp
 * Author:  Joan Cobeña, Edison Verdesoto
 * Modified: jueves, 7 de diciembre de 2023 01:11:27 p. m.
 * Purpose: Implementacion de clase ListaDoble
 ***********************************************************************/
#include <iostream>
#include "ListaDoble.h"
#include "Nodo.h"

template <typename T>
ListaDoble<T>::ListaDoble(Nodo<T>* _cabeza)
{
    cabeza = _cabeza;
}

template <typename T>
ListaDoble<T>::ListaDoble()
{
    cabeza = nullptr;
    cola = nullptr;
}

template <typename T>
Nodo<T>* ListaDoble<T>::get_cabeza()
{
    return cabeza;
}

template <typename T>
void ListaDoble<T>::set_cabeza(Nodo<T>* nueva_cabeza)
{
    cabeza = nueva_cabeza;
}

template <typename T>
Nodo<T>* ListaDoble<T>::get_cola()
{
    return cola;
}

template <typename T>
void ListaDoble<T>::set_cola(Nodo<T>* nueva_cola)
{
    cola = nueva_cola;
}

template <typename T>
void ListaDoble<T>::insertar_cabeza(T valor)
{
    Nodo<T>* nuevo_nodo;
    if(esta_vacia())
    {
        nuevo_nodo = new Nodo<T>(valor, nullptr, nullptr);
        cola = nuevo_nodo;
    }
    else
    {
        nuevo_nodo = new Nodo<T>(valor, cabeza, nullptr);
        cabeza->set_anterior(nuevo_nodo);
    }
    cabeza = nuevo_nodo;
}

template <typename T>
void ListaDoble<T>::insertar_cola(T valor)
{
    Nodo<T>* nuevo_nodo;
    if(esta_vacia())
    {
        nuevo_nodo = new Nodo<T>(valor, nullptr, nullptr);
        cabeza = nuevo_nodo;
    }
    else
    {
        nuevo_nodo = new Nodo<T>(valor, nullptr, cola);
        cola->set_siguiente(nuevo_nodo);
    }
    cola = nuevo_nodo;
}

template <typename T>
void ListaDoble<T>::imprimir()
{
    Nodo<T>* aux = cabeza;
    while(aux!=nullptr)
    {
        std::cout<<aux->get_valor()<<"\t";
        aux = aux->get_siguiente();
    }
}

template <typename T>
void ListaDoble<T>::eliminar(T valor)
{
    Nodo<T>* aux = cabeza;
    while(aux!=nullptr)
    {
        if(valor == aux->get_valor())
        {
            if(aux->get_anterior() != nullptr && aux->get_siguiente() != nullptr)
            {
                aux->get_anterior()->set_siguiente(aux->get_siguiente());
            }
            else
            {
                cabeza = aux->get_siguiente();
            }
            if(aux->get_siguiente() != nullptr && aux->get_anterior()!= nullptr)
            {
                aux->get_siguiente()->set_anterior(aux->get_anterior());
            }
            delete aux;
            break;
        }
        aux = aux->get_siguiente();
    }
    if(aux == nullptr)
    {
        std::cout<<"No se encontro el elemento a eliminar";
    }
}

template <typename T>
void ListaDoble<T>::insertar_entre(T valor_busq, T valor)
{
    Nodo<T>* aux = cabeza;
    bool encontrado = false;
    while(aux!=nullptr)
    {
        if(valor_busq == aux->get_valor())
        {
            encontrado = true;
            Nodo<T>* nuevo = new Nodo<T>(valor,aux->get_siguiente(), aux);
            if(aux != cola && aux->get_siguiente()!= nullptr)
            {
                aux->get_siguiente()->set_anterior(nuevo);
            }
            else
            {
                cola = nuevo;
            }
            aux->set_siguiente(nuevo);
            break;
        }
        aux = aux->get_siguiente();
    }
    if(encontrado==false)printf("\n No se encontro el dato en la lista");
}

template <typename T>
Nodo<T>* ListaDoble<T>::buscar(T valor_busq)
{
    Nodo<T>* aux = cabeza;
    int pos = 0;
    while(aux!=nullptr)
    {
        if(valor_busq == aux->get_valor())
        {
            std::cout<<"Dato encontrado: "<<valor_busq<<" Posicion en la lista: "<<pos<<std::endl;;
            break;
        }
        aux = aux->get_siguiente();
        pos++;
    }
    return aux;
}

template <typename T>
int ListaDoble<T>::tam()
{
    int i = 0;
    Nodo<T>* aux = cabeza;
    while(aux!=nullptr)
    {
        aux = aux->get_siguiente();
        i++;
    }
    return i;
}


template <typename T>
bool ListaDoble<T>::esta_vacia()
{
    return (cabeza == nullptr);
}
