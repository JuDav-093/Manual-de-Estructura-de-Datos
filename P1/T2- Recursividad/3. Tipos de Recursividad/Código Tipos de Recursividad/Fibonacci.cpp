#include <iostream>
using namespace std;

class Fibonacci {
public:
    int calcularFibonacci(int n) {
        if (n <= 1) {
            return n;
        } else {
            return calcularFibonacci(n - 1) + calcularFibonacci(n - 2);
        }
    }

    void imprimirSecuencia(int n) {
        cout << "Secuencia de Fibonacci hasta " << n << ": " << endl;
        for (int i = 0; i < n; ++i) {
            cout << calcularFibonacci(i) << " ";
        }
        cout << endl;
    }
};

int main() {
    Fibonacci fibonacci;
    int n;
    cout << "Ingrese la cantidad de numeros de la serie Fibonacci a mostrar: ";
    cin >> n;
    fibonacci.imprimirSecuencia(n);
    return 0;
}