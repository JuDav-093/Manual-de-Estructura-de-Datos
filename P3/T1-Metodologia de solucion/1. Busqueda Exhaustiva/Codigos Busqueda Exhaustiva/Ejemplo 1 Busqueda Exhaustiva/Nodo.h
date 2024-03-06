#ifndef NODO_H
#define NODO_H

class Nodo {
private:
    int dato;
    Nodo* siguiente;

public:
    Nodo(int dato);
    int obtenerDato() const;
    Nodo* obtenerSiguiente() const;
    void establecerSiguiente(Nodo* nodo);
};

#endif
