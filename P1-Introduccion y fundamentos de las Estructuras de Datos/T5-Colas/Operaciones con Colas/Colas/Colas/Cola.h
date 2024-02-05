#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include <iostream>
#include "Nodo.h"

class Cola{
private:
    Nodo* cabeza;
    Nodo* cola;
public:
    Cola();
    Nodo* getCabeza();
    void setCabeza(Nodo*);
    Nodo* getCola();
    void setCola(Nodo*);
    void insertar(int valor);
    void eliminar();
    void imprimir();
    bool estaVacia();
    int sumaDeCola();
    void retornarColaPar(Cola* cola_par);
    Cola extraerNumerosImpares(Cola& cola);
    bool esPrimo(int numero);
    Cola extraerNumerosPrimos(Cola& cola);
    int sumarValoresCola(Cola& cola);
};

#endif // COLA_H_INCLUDED
