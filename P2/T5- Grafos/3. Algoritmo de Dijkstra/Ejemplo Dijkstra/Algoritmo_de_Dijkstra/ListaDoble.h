/***********************************************************************
 UFA - ESPE
 * Module:  ListaDoble.h
 * Author:  Joan Cobeña, Edison Verdesoto
 * Modified: jueves, 7 de diciembre de 2023 01:11:27 p. m.
 * Purpose: Declaracion de clase ListaDoble
 ***********************************************************************/
#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include "Nodo.h"

template <typename T>
class ListaDoble
{
public:
    ListaDoble<T>(Nodo<T>* _cabeza);
    ListaDoble<T>();
    Nodo<T>* get_cabeza();
    void set_cabeza(Nodo<T>*);
    Nodo<T>* get_cola();
    void set_cola(Nodo<T>*);
    void insertar_entre(T valor_busq, T valor);
    void insertar_cabeza(T valor);
    void insertar_cola(T valor);
    bool buscar(T);
    void eliminar(T valor);
    void eliminar_cola();
    void imprimir();
    int tam();
    bool esta_vacia();

protected:
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
};

#endif // LISTADOBLE_H_INCLUDED
