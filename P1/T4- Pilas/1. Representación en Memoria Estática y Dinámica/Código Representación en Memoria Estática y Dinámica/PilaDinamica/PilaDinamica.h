#ifndef PILA_DINAMICA_H_INCLUDED
#define PILA_DINAMICA_H_INCLUDED

class PilaDinamica {
private:
    struct Nodo {
        int dato;
        Nodo* siguiente;
    };

    Nodo* cima;

public:
    PilaDinamica();
    ~PilaDinamica();
    void push(int valor);
    void pop();
    void imprimir();
};

#endif // PILA_DINAMICA_H_INCLUDED
