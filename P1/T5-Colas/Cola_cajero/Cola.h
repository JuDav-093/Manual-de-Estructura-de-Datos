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
    void insertar(int ID, int t_llegada, int t_espera, int t_no_trabaja, int t_servicio, int t_salida, int t_entre_llegadas);
    void eliminar();
    void imprimir();
    bool estaVacia();
    Nodo* extraer_cabeza();
    int actSize();
};

#endif // COLA_H_INCLUDED