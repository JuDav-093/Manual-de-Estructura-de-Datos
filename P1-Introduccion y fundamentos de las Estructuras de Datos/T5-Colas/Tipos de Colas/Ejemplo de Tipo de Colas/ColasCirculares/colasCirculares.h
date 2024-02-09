#ifndef COLASCIRCULARES_H_INCLUDED
#define COLASCIRCULARES_H_INCLUDED
#include <iostream>

class CircularQueue {
private:
    int *array;
    int frente, final, capacidad;

public:
    CircularQueue(int size);
    ~CircularQueue();

    bool estaVacia();
    bool estaLlena();
    void encolar(int elemento);
    void desencolar();
    void mostrarContenido();
};


#endif // COLASCIRCULARES_H_INCLUDED
