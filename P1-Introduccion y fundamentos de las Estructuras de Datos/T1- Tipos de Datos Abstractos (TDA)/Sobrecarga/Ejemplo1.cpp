/*Ejemplo de sobrecarga de operadores utilizando los operadores + y % */
#include <iostream>

class Numero {
private:
    int valor;

public:
    Numero() : valor(0) {}

    Numero(int val) : valor(val) {}

    // Sobrecarga del operador de suma (+)
    Numero operator+(const Numero& otro) const {
        Numero resultado;
        resultado.valor = this->valor + otro.valor;
        return resultado;
    }

    // Sobrecarga del operador de modulo (%)
    Numero operator%(const Numero& otro) const {
        Numero resultado;
        resultado.valor = this->valor % otro.valor;
        return resultado;
    }

    // Función para ingresar el valor del número desde el teclado
    void ingresarNumero() {
        std::cout << "Ingrese un numero: ";
        std::cin >> valor;
    }

    // Función para imprimir el valor del número
    void mostrarNumero() const {
        std::cout << "Valor del numero: " << valor << std::endl;
    }
};

int main() {
    // Crear instancias de la clase Numero
    Numero numero1, numero2;

    // Ingresar valores desde el teclado
    std::cout << "Para el primer numero:" << std::endl;
    numero1.ingresarNumero();

    std::cout << "\nPara el segundo numero:" << std::endl;
    numero2.ingresarNumero();

    // Sobrecarga del operador de suma
    Numero resultadoSuma = numero1 + numero2;
    std::cout << "\nResultado de la suma:" << std::endl;
    resultadoSuma.mostrarNumero();

    // Sobrecarga del operador de modulo
    Numero resultadoModulo = numero1 % numero2;
    std::cout << "\nResultado del modulo:" << std::endl;
    resultadoModulo.mostrarNumero();

    return 0;
}
