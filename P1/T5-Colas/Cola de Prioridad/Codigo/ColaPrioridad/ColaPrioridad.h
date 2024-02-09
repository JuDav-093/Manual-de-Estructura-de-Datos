#ifndef COLA_PRIORIDAD_H_INCLUDED
#define COLA_PRIORIDAD_H_INCLUDED

#include "Nodo.h"

class ColaPrioridad {
private:
    Nodo* frente;
    Nodo* fin;

public:
    ColaPrioridad();
    ~ColaPrioridad();
    void encolar(int valor, int prioridad);
    void desencolar();
    void imprimir();
};

#endif // COLA_PRIORIDAD_H_INCLUDED
