#ifndef CALCULADORA_H
#define CALCULADORA_H

template <class T>
class Calculadora {
private:
    T a, b;
public:
    Calculadora(T x, T y);
    T sumar();
    T restar();
    T multiplicar();
    T dividir();
};

#endif
