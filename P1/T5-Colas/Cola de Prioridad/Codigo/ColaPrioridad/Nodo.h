#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

class Nodo {
private:
    int dato;
    int prioridad;
    Nodo* siguiente;

public:
    Nodo(int valor, int prioridad);
    int getDato();
    int getPrioridad();
    Nodo* getSiguiente();
    void setSiguiente(Nodo* nodo);
};

#endif // NODO_H_INCLUDED
