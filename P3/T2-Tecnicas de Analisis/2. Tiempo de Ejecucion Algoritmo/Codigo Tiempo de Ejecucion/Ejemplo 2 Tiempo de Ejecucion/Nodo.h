#ifndef NODO_H
#define NODO_H

class Nodo {
public:
    int getDato() const;
    void setDato(int valor);

    Nodo* getSiguiente() const;
    void setSiguiente(Nodo* siguiente);

    Nodo(int valor);
    
        int dato;
    Nodo* siguiente;

private:

};

#endif 
