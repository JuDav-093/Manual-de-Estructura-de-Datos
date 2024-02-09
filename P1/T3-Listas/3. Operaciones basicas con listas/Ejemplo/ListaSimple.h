#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED


#include "Nodo.h"

class ListaSimple
{
    public:
        void insertar_cabeza(int);
        void imprimir_cabeza();
        void eliminar_cabeza();
        void insertar_cola(int);
        void imprimir_cola();
        void eliminar_cola();

        ListaSimple();
        ~ListaSimple();
    protected:

    private:
        Nodo* cabeza;
        Nodo* cola;
};

#endif // LISTASIMPLE_H_INCLUDED
