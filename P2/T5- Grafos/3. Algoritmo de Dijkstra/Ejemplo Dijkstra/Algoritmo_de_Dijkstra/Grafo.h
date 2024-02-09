#ifndef GRAFO_H
#define GRAFO_H

#include "ListaDoble.h"
#include "Arista.h"
#include "Vertice.h"

class Grafo
{
    public:
        Grafo();

        ListaDoble<Arista*>* get_aristas();
        ListaDoble<Vertice*>* get_vertices();
        void resetear_dist_est();
        bool existe_arista(Vertice*, Vertice*);
        double dijkstra(Vertice*, Vertice*);
        void imprimir();
        void imprimir_aristas();
        ~Grafo();

    protected:

    private:
        ListaDoble<Arista*>* aristas;
        ListaDoble<Vertice*>* vertices;
};


#endif // GRAFO_H
