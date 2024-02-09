#include <iostream>
using namespace std;

// Función recursiva para calcular la suma de los dígitos
int sumaDigitos(int n) {
    // Caso base
    if (n == 0)
        return 0;
    // Caso recursivo
    else
        return (n % 10) + sumaDigitos(n / 10);
}

int main() {
    int num, result;

    // Solicitar al usuario un numero para calcular 
    cout << "Introduce un numero para calcular la suma de sus digitos: ";
    cin >> num;

    // Calcular la suma de los digitos y mostrar el resultado
    result = sumaDigitos(num);
    cout << "La suma de los digitos de " << num << " es: " << result << endl;

    return 0;
}