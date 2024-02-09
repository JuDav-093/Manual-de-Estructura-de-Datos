#include "Vector.h"

Vector::Vector() {
    vect = new int[10];
}

Vector::Vector(int* vec) {
    vect = new int[10];
    for (int i = 0; i < 10; i++) {
        vect[i] = vec[i];
    }
}

Vector::~Vector() {
    delete[] vect;
}

void Vector::setVect(int* vec) {
    for (int i = 0; i < 10; i++) {
        vect[i] = vec[i];
    }
}

int* Vector::getVect() {
    return vect;
}

