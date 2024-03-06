#include <iostream>
#include <vector>

// Función para encontrar el máximo elemento en una matriz
int encontrarMaximo(const std::vector<int>& arr, int izquierda, int derecha) {
    if (izquierda == derecha) {
        return arr[izquierda];
    }
    else {
        int mitad = (izquierda + derecha) / 2;
        int maxIzquierda = encontrarMaximo(arr, izquierda, mitad);
        int maxDerecha = encontrarMaximo(arr, mitad + 1, derecha);
        return std::max(maxIzquierda, maxDerecha);
    }
}

int main() {
    std::vector<int> numeros = { 10, 5, 8, 15, 3, 20, 12 };
    int maximoElemento = encontrarMaximo(numeros, 0, numeros.size() - 1);
    std::cout << "El maximo elemento es: " << maximoElemento << std::endl;
    return 0;
}
