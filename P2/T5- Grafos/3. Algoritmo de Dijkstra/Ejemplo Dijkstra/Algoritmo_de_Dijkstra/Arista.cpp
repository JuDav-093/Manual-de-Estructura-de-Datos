#include "Arista.h"

Arista::Arista(Vertice* _previo, Vertice* _siguiente, double _peso)
{
    previo = _previo;
    siguiente = _siguiente;
    peso = _peso;
}

Vertice* Arista::get_previo(){
    return previo;
}

Vertice* Arista::get_siguiente(){
    return siguiente;
}

double Arista::get_peso(){
    return peso;
}


Arista::~Arista()
{
    //dtor
}
