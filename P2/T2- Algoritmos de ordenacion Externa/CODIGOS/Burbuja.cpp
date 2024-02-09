#include <iostream>

void intercambiar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void burbuja(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                intercambiar(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arreglo[] = {60, 36, 24, 12, 21, 10, 70};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    std::cout << "Arreglo original: ";
    for (int i = 0; i < n; i++) {
        std::cout << arreglo[i] << " ";
    }

    // Llamada a la función de burbuja para ordenar el arreglo
    burbuja(arreglo, n);

    std::cout << "\nArreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        std::cout << arreglo[i] << " ";
    }

    return 0;
}
