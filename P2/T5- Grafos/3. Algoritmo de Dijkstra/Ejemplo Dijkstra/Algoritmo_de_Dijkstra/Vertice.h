#ifndef VERTICE_H
#define VERTICE_H

#include "ListaDoble.h"

class Vertice
{
    public:
        Vertice(char);

        void set_distancia_estim(double);
        double get_distancia_estim();
        char get_id();

        ~Vertice();

    protected:

    private:
        char id;
        double distancia_estim;
};

Vertice* encontrar_vertice(ListaDoble<Vertice*>* vertices, char id);

#endif // VERTICE_H
