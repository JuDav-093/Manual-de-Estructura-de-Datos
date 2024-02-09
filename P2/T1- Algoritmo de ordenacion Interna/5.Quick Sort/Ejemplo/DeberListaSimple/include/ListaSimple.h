#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include "Nodo.h"

class ListaSimple
{
    public:
        void insertar_cabeza(int valor);
        ListaSimple();
        ~ListaSimple();

    protected:

    private:
        Nodo* cabeza;
};

#endif // LISTASIMPLE_H
