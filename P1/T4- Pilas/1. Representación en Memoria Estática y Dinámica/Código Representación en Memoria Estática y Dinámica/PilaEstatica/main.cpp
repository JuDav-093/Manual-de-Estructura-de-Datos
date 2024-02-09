#include "PilaEstatica.cpp"

int main() {
    PilaEstatica miPila;

    // Ejemplo de uso de la pila Estatica
    miPila.push(10);
    miPila.push(20);

    miPila.imprimir();

    miPila.pop();

    miPila.imprimir();

    return 0;
}