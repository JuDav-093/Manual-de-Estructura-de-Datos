#include <iostream>

void intercambio(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Compara elementos adyacentes
            if (arr[j] > arr[j + 1]) {
                // Intercambia si están en el orden incorrecto
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arreglo[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    std::cout << "Arreglo original: ";
    for (int i = 0; i < n; i++) {
        std::cout << arreglo[i] << " ";
    }

    // Llamada a la función de intercambio
    intercambio(arreglo, n);

    std::cout << "\nArreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        std::cout << arreglo[i] << " ";
    }

    return 0;
}
