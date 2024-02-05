#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

class Nodo{
private:
    int valor;
    Nodo* siguiente;
public:
    Nodo(int, Nodo*);
    Nodo* getSiguiente();
    void setSiguiente(Nodo*);
    int getValor(void);
    void setValor(int);
    ~Nodo();
};

#endif // NODO_H_INCLUDED
