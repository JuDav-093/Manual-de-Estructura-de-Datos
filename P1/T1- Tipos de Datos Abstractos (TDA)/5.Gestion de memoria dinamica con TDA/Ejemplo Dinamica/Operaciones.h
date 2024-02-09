
#include <iostream>
#include "Vector.h"

class Operaciones {
private:
    Vector* v;

public:
    Operaciones();
    Operaciones(Vector&);
    ~Operaciones();
    void encerar();
    void ingresar();
    float procesar();
    void imprimir();
    Vector* getVector();
};
