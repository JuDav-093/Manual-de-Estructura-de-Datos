#include <iostream>
using namespace std;

class Potencia {
public:
    int calcularPotencia(int base, int exponente) {
        if (exponente == 0) {
            return 1;
        } else {
            return base * calcular(base, exponente - 1); // Llamada recursiva
        }
    }

    int calcular(int base, int exponente) {
        if (exponente == 0) {
            return 1;
        } else {
            return base * calcular(base, exponente - 1); // Llamada recursiva
        }
    }
};

int main() {
    Potencia potencia;

    int base, exponente;
    cout << "Ingrese la base: ";
    cin >> base;
    cout << "Ingrese el exponente: ";
    cin >> exponente;
    cout << "Potencia: " << potencia.calcularPotencia(base, exponente) << endl;

    return 0;
}
