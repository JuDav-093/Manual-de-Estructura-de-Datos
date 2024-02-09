#include <iostream>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

void hanoi(int n, char origen, char auxiliar, char destino) {
    if (n == 1) {
        std::cout << "Mover disco 1 desde " << origen << " hacia " << destino << std::endl;
        return;
    }
    hanoi(n - 1, origen, destino, auxiliar);
    std::cout << "Mover disco " << n << " desde " << origen << " hacia " << destino << std::endl;
    hanoi(n - 1, auxiliar, origen, destino);
}

void fibonacci(int n, int a = 0, int b = 1) {
    if (n > 0) {
        std::cout << a << " ";
        fibonacci(n - 1, b, a + b);
    }
}

int main() {
    int opcion;
    do {
        system("cls");
        std::cout << "Seleccione una opción:" << std::endl;
        std::cout << "1. Calcular factorial" << std::endl;
        std::cout << "2. Resolver Torres de Hanoi" << std::endl;
        std::cout << "3. Imprimir secuencia de Fibonacci" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int num;
                std::cout << "Ingrese un número para calcular su factorial: ";
                std::cin >> num;
                std::cout << "El factorial de " << num << " es: " << factorial(num) << std::endl;
                break;
            }
            case 2: {
                int num_discos;
                std::cout << "Ingrese el número de discos en las Torres de Hanoi: ";
                std::cin >> num_discos;
                std::cout << "Pasos para resolver las Torres de Hanoi con " << num_discos << " discos:" << std::endl;
                hanoi(num_discos, 'A', 'B', 'C');
                break;
            }
            case 3: {
                int num_termino;
                std::cout << "Ingrese el término para imprimir la secuencia de Fibonacci: ";
                std::cin >> num_termino;
                std::cout << "Secuencia de Fibonacci hasta el término " << num_termino << ": ";
                fibonacci(num_termino);
                std::cout << std::endl;
                break;
            }
            case 4:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opción inválida. Por favor, seleccione una opción válida." << std::endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}
