#ifndef ARISTA_H
#define ARISTA_H

#include "Vertice.h"

class Arista
{
    public:
        Arista(Vertice*, Vertice*, double);
        Vertice* get_previo();
        Vertice* get_siguiente();
        double get_peso();
        ~Arista();

    protected:

    private:
        Vertice* previo;
        Vertice* siguiente;
        double peso;

};

#endif // ARISTA_H
