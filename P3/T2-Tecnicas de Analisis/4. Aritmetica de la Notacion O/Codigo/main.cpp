#include <iostream>
#include <vector>

// Funci�n para encontrar el m�ximo elemento en una matriz
int encontrarMaximo(const std::vector<int>& arr) {
    int maxElemento = arr.at(0);
    for (int i = 1; i < arr.size(); ++i) {
        if (arr.at(i) > maxElemento) {
            maxElemento = arr.at(i);
        }
    }
    return maxElemento;
}

int main() {
    std::vector<int> numeros = { 10, 5, 8, 15, 3, 20, 12 };
    int maximoElemento = encontrarMaximo(numeros);
    std::cout << "El m�ximo elemento es: " << maximoElemento << std::endl;
    return 0;
}