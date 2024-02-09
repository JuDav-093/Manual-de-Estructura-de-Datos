#include "Vertice.h"
#include "ListaDoble.cpp"
#include "Nodo.h"

Vertice::Vertice(char _id)
{
    id = _id;
    distancia_estim = std::numeric_limits<double>::infinity();

}

void Vertice::set_distancia_estim(double nueva_distancia_estim){
    distancia_estim = nueva_distancia_estim;
}

double Vertice::get_distancia_estim(){
    return distancia_estim;
}

char Vertice::get_id(){
    return id;
}

Vertice* encontrar_vertice(ListaDoble<Vertice*>* vertices, char id){
    Nodo<Vertice*>* vertice_nodo = vertices->get_cabeza();

    while(vertice_nodo!=nullptr){

        if(vertice_nodo->get_valor()->get_id() == id){
            break;
        }

        vertice_nodo = vertice_nodo->get_siguiente();
    }

    return vertice_nodo->get_valor();
}

Vertice::~Vertice()
{
    //dtor
}
