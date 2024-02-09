
#include <iostream>
#include "Pila.cpp"
#include "Nodo.cpp"
using namespace std;
int main() {

    Pila<int> pila_ejemplo;
    pila_ejemplo.agregar(10);
    pila_ejemplo.agregar(20);
    pila_ejemplo.agregar(30);
    pila_ejemplo.agregar(40);
    pila_ejemplo.agregar(50);
    pila_ejemplo.agregar(60);
    cout<<"Elementos: "<<endl;
    pila_ejemplo.imprimir();
    pila_ejemplo.eliminar();

    cout<<"Elementos despues de eliminar el tope: "<< endl;
    pila_ejemplo.imprimir();
    return 0;
}
