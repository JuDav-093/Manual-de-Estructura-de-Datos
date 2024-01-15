//aquí tienes un ejemplo práctico de código en C++ que utiliza el manejo de plantillas 
//para crear una función que intercambia dos valores de cualquier tipo:
#include <iostream>

// Función de intercambio de valores utilizando plantillas
template <typename T>
void intercambiar(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    // Ejemplo de intercambio de valores para enteros
    int num1 = 5, num2 = 10;
    std::cout << "Antes del intercambio: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    intercambiar(num1, num2);

    std::cout << "Después del intercambio: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    // Ejemplo de intercambio de valores para strings
    std::string str1 = "Hola", str2 = "Mundo";
    std::cout << "Antes del intercambio: str1 = " << str1 << ", str2 = " << str2 << std::endl;

    intercambiar(str1, str2);

    std::cout << "Después del intercambio: str1 = " << str1 << ", str2 = " << str2 << std::endl;

    return 0;
}
