#include <iostream>
#include "calculadora.h"
#include "calculadora.cpp"
using namespace std;

int main() {
    double x, y;
    cout << "Ingrese el primer numero: ";
    cin >> x;
    cout << "Ingrese el segundo numero: ";
    cin >> y;

    Calculadora<double> Op(x, y);
    cout << "Suma: " << Op.sumar() << endl;
    cout << "Resta: " << Op.restar() << endl;
    cout << "Multiplicacion: " << Op.multiplicar() << endl;
    cout << "Division: " << Op.dividir() << endl;

    return 0;
}
