#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "Nodo.h"

template <typename T>
class Pila
{
public:
    Pila<T>(Nodo<T>* tope);
    Pila<T>();
    Nodo<T>* get_tope();
    void agregar(T ndato);
    void eliminar();
    void imprimir();
    bool esta_vacia();
    void obtener_tope();
    void suma_de_elementos();
protected:
private:
    Nodo<T>* tope;
};

#endif // PILA_H_INCLUDED
