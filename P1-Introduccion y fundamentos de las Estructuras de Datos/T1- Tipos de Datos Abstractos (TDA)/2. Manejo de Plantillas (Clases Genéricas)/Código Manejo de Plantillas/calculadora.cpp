#include "calculadora.h"

template <class T>
Calculadora<T>::Calculadora(T x, T y) {
    a = x;
    b = y;
}

template <class T>
T Calculadora<T>::sumar() {
    return a + b;
}

template <class T>
T Calculadora<T>::restar() {
    return a - b;
}

template <class T>
T Calculadora<T>::multiplicar() {
    return a * b;
}

template <class T>
T Calculadora<T>::dividir() {
    if (b != 0) {
        return a / b;
    } else {
        std::cout << "No se puede dividir por cero" << std::endl;
        return 0;
    }
}
