#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

class Nodo {
private:
    int dato;
    Nodo* siguiente;

public:
    Nodo(int valor);
    int getDato();
    Nodo* getSiguiente();
    void setSiguiente(Nodo* nodo);
};

#endif // NODO_H_INCLUDED
