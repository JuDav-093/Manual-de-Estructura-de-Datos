#ifndef PILA_ESTATICA_H_INCLUDED
#define PILA_ESTATICA_H_INCLUDED

class PilaEstatica {
private:
    static const int TAMANO_MAX = 10;
    int arreglo[TAMANO_MAX];
    int cima;

public:
    PilaEstatica();
    void push(int valor);
    void pop();
    void imprimir();
};

#endif // PILA_ESTATICA_H_INCLUDED