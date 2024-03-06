#include <iostream>
#include <vector>
#include "validaciones.h"

using namespace std;

// Estructura de un objeto
struct Objeto {
    int peso;
    int valor;
};

// Función para calcular el máximo entre dos números
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Función que resuelve el problema de la mochila utilizando programación dinámica
int problemaMochila(int capacidad, vector<int>& pesos, vector<int>& valores, int n) {
    vector<vector<int>> V(n + 1, vector<int>(capacidad + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacidad; j++) {
            if (pesos[i - 1] <= j) {
                V[i][j] = max(V[i - 1][j], valores[i - 1] + V[i - 1][j - pesos[i - 1]]);
            } else {
                V[i][j] = V[i - 1][j];
            }
        }
    }

    return V[n][capacidad];
}

int main() {
    system("cls");
    validaciones v;

    int n;
    // Validación para el número de objetos
    do {
        n = v.ingresar_enteros("\nIngrese el numero de objetos (menos de 25): ");
        if (n <= 0 || n >25) {
            cout << "\nPor favor, ingrese un numero valido de objetos." << endl;
        }
    } while (n <= 0 || n > 25);

    vector<int> pesos(n);
    vector<int> valores(n);

    // Ingreso de los pesos y valores de los objetos
    for (int i = 0; i < n; ++i) {
        cout << "\nObjeto " << i + 1 << endl;
        // Validación para el peso del objeto
        do {
            pesos[i] = v.ingresar_enteros("\nIngrese el peso del objeto (mayor que 0 y menor que 100): ");
            if (pesos[i] <= 0 || pesos[i] >= 100) {
                cout << "\nPor favor, ingrese un peso mayor que 0 y menor que 100" << endl;
            }
        } while (pesos[i] <= 0);

        // Validación para el valor del objeto
        do {
            valores[i] = v.ingresar_enteros("\nIngrese el valor del objeto (mayor que 0): ");
            if (valores[i] <= 0) {
                cout << "\nPor favor, ingrese un valor mayor que 0." << endl;
            }
        } while (valores[i] <= 0);
    }

    int capacidadMaxima;
    capacidadMaxima = v.ingresar_enteros("\nIngrese la capacidad maxima de la mochila: ");

    // Resolución del problema de la mochila
    int maxValor = problemaMochila(capacidadMaxima, pesos, valores, n);

    cout << "\nEl valor maximo que se puede llevar en la mochila es: " << maxValor << endl;
    system("pause");

    return 0;
}

