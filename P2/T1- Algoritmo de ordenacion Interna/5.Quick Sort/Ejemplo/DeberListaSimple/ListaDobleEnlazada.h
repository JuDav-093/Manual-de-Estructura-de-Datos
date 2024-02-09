
#include "Nodo.h"

class ListaDobleEnlazada {
private:
    Nodo* cabeza;
    Nodo* cola;

public:
    ListaDobleEnlazada();

    void insertarCabeza(int valor);
    void insertarCola(int valor);
    void insertarEntreCabezaYCola(int valor);
    void imprimirLista()const;

    Nodo* getCabeza() const { return cabeza; }
    Nodo* getCola() const { return cola; }
};

