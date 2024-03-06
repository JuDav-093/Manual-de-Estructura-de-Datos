#include "TablaHash.h"
#include <iostream>
#include "Mapa.h"
#include "ListaDoble.cpp"
#include "Nodo.cpp"

template <typename T>
TablaHash<T>::TablaHash(int t)
{
    tam = t;
    listas_indices = new ListaDoble<T>*[tam];
    for(int i = 0; i<=tam; i++)
    {
        listas_indices[i] = new ListaDoble<T>();
    }
}

template <typename T>
void TablaHash<T>::insertar(T dato, std::string hashear_cadena)
{
    int hashear = 0;
    for (char ch : hashear_cadena)
    {
        hashear += int(ch);
    }
    int pos_hash = hashear % tam;
    listas_indices[pos_hash]->insertar_cola(dato);
}

template <typename T>
void TablaHash<T>::insertar(T dato, int hashear)
{
    int pos_hash = hashear % tam;
    listas_indices[pos_hash]->insertar_cola(dato);
}

template <typename T>
Nodo<T>* TablaHash<T>::buscar(T dato, int hashear)
{
    int pos_hash = hashear % tam;
    return listas_indices[pos_hash]->buscar(dato);
}

template <>
TablaHash<Mapa*>::TablaHash(int t)
{
    tam = t;
    listas_indices = new ListaDoble<Mapa*>*[tam];
    for (int i = 0; i < tam; i++)
    {
        listas_indices[i] = new ListaDoble<Mapa*>();
    }
}

template <>
void TablaHash<Mapa*>::insertar(Mapa* dato, std::string hashear_cadena)
{
    int hashear = 0;
    int i = 0;
    for (char ch : hashear_cadena)
    {
        hashear += int(ch);
        i++;
        if (i > 4) {
            break;
        }
    }
    int pos_hash = abs(hashear) % tam;
    listas_indices[pos_hash]->insertar_cola(dato);
}


template <>
Nodo<Mapa*>* TablaHash<Mapa*>::buscar_mapa(std::string hashear_cadena)
{
    int hashear = 0;
    int i = 0;
    for (char ch : hashear_cadena)
    {
        hashear += int(ch);
        i++;
        if (i > 4) {
            break;
        }
    }
    
    int pos_hash = abs(hashear) % tam;

    Nodo<Mapa*>* mapa_nodo = listas_indices[pos_hash]->get_cabeza();

    std::string encontrado;

    while(mapa_nodo !=nullptr)
    {
        encontrado = mapa_nodo->get_valor()->get_traducir();

        if (encontrado == hashear_cadena)
        {
            return mapa_nodo;
        }
        mapa_nodo = mapa_nodo->get_siguiente();
    }

    return mapa_nodo;
}

template <typename T>
void TablaHash<T>::eliminar(T dato)
{
    int pos_hash = dato % tam;
    listas_indices[pos_hash]->eliminar(dato);
}

template <typename T>
void TablaHash<T>::imprimir()
{
    for(int i = 0; i<tam; i++)
    {
        printf("%d\t", i);
        listas_indices[i]->imprimir();
        printf("\n");
    }
}

template <typename T>
TablaHash<T>::~TablaHash()
{

}
