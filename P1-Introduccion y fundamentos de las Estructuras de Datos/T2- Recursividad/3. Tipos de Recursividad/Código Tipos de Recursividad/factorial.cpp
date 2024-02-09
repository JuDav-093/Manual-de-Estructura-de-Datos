#include <iostream>

class CalculadorFactorial {
public:
    double Calcularfactorial(double n) {
        if (n == 0 || n == 1) {
            return 1;
        } else {
            return n * Calcularfactorial(n - 1);
        }
    }
};

int main() {
    CalculadorFactorial calculadorfactorial;
    int n;

    std::cout << "Ingrese un valor para calcular el factorial: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "No puede ingresar numeros negativos" << std::endl;
    } else {
        double resultado = calculadorfactorial.Calcularfactorial(n);
        std::cout << "El factorial de " << n << " es: " << resultado << std::endl;
    }

    return 0;
}