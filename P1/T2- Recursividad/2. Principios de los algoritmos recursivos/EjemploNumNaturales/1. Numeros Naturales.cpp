#include <iostream>

class CalculadoraSuma {
public:
    int sumaRecursiva(int n) {
        if (n == 1) {
            return 1;
        } else {
            return n + sumaRecursiva(n - 1);
        }
    }
};

int main() {
    CalculadoraSuma objetoSuma;
    int n = 5; 
    int resultado = objetoSuma.sumaRecursiva(n);

    std::cout << "La suma de los primeros " << n << " numeros naturales es: " << resultado << std::endl;

    return 0;
}  
