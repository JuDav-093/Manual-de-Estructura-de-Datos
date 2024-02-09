#include <stdlib.h>
#include "Operaciones.h"

Operaciones::Operaciones() {
    v = new Vector();
}

Operaciones::Operaciones(Vector& vec) {
    v = new Vector(vec.getVect());
}

Operaciones::~Operaciones() {
    delete v;
}

void Operaciones::encerar() {
    int* vec = new int[10];
    for (int i = 0; i < 10; i++) {
        vec[i] = 0;
    }
    v->setVect(vec);
    delete[] vec;
}

void Operaciones::ingresar() {
    int* vec = new int[10];
    for (int i = 0; i < 10; i++) {
        vec[i] = rand() % 11;
    }
    v->setVect(vec);
    delete[] vec;
}

float Operaciones::procesar() {
    float promedio = 0;
    int* vect = v->getVect();
    for (int i = 0; i < 10; i++) {
        promedio += vect[i];
    }
    return promedio / 10;
}

void Operaciones::imprimir() {
    int* vect = v->getVect();
    std::cout << "\nvector={";
    for (int i = 0; i < 10; i++) {
        std::cout << vect[i] << " ";
    }
    std::cout << "}\n";
}

Vector* Operaciones::getVector() {
    return v;
}
