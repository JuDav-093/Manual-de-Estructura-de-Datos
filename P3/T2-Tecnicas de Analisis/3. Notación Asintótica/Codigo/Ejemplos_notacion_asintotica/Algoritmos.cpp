#include <iostream>
#include <cmath>

void ejemploTheta1() {
    // Theta(1)
    std::cout << "Ejemplo de Theta(1):" << std::endl;
    std::cout << "Operacion de tiempo constante" << std::endl;
}

void ejemploThetaLog2n(int n) {
    // Theta(log2n)
    std::cout << "Ejemplo de Theta(log2n):" << std::endl;
    int i = 1;
    while (i < n) {
        i *= 2;
        std::cout << "Operacion de tiempo logaritmico" << std::endl;
    }
}

void ejemploThetaN(int n) {
    // Theta(n)
    std::cout << "Ejemplo de Theta(n):" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Operacion de tiempo lineal" << std::endl;
    }
}

void ejemploThetaNlog2n(int n) {
    // Theta(n log2n)
    std::cout << "Ejemplo de Theta(n log2n):" << std::endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= log2(i); j++) {
            std::cout << "Operacion de tiempo linealitmico" << std::endl;
        }
    }
}

void ejemploThetaN2(int n) {
    // Theta(n^2)
    std::cout << "Ejemplo de Theta(n^2):" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "Operacion de tiempo cuadratico" << std::endl;
        }
    }
}

void ejemploThetaN2log2n(int n) {
    // Theta(n^2 log2n)
    std::cout << "Ejemplo de Theta(n^2 log2n):" << std::endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= log2(j); k++) {
                std::cout << "Operacion de tiempo cuadratico logaritmico" << std::endl;
            }
        }
    }
}

void ejemploThetaN3(int n) {
    // Theta(n^3)
    std::cout << "Ejemplo de Theta(n^3):" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                std::cout << "Operacion de tiempo cubico" << std::endl;
            }
        }
    }
}

void ejemploTheta2N(int n) {
    // Theta(2^n)
    std::cout << "Ejemplo de Theta(2^n):" << std::endl;
    for (int i = 0; i < pow(2, n); i++) {
        std::cout << "Operacion de tiempo exponencial" << std::endl;
    }
}

int factorial(int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

void operacionFactorial(int n) {
    if (n == 0 || n == 1) {
        std::cout << "Operacion de tiempo factorial para n=" << n << std::endl;
    } else {
        std::cout << "Operacion de tiempo factorial para n=" << n << std::endl;
        operacionFactorial(n - 1);
    }
}

void ejemploThetaNFact(int n) {
    // Theta(n!)
    std::cout << "Ejemplo de Theta(n!):" << std::endl;
    operacionFactorial(n);
}
