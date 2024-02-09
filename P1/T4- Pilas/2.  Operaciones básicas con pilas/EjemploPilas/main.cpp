
#include <iostream>
#include "Pila.cpp"
#include "Nodo.cpp"
#include "validation.h"
using namespace std;

int main() {
    
    Pila<int> pila_ejemplo;
    pila_ejemplo.agregar(10);
    pila_ejemplo.agregar(20);
    pila_ejemplo.agregar(30);
    pila_ejemplo.suma_de_elementos();
    cout<<"Elementos pila: "<<endl;
    pila_ejemplo.imprimir();
    pila_ejemplo.eliminar();

    cout<<"Elementos despues de eliminar el tope: "<< endl;
    pila_ejemplo.imprimir();
    Pila<double> pila_ejemplo2;
    pila_ejemplo2.agregar(9.876);
    float decimal;
    
    decimal=ingresar_reales("Ingrese un numero decimal");
    pila_ejemplo2.agregar(decimal);
    cout<<"\nPila 2: "<<endl;
    pila_ejemplo2.imprimir();
    Pila<int> pila_ejemplo3;
    cout<<"Pila 3: "<<endl;
    pila_ejemplo3.imprimir();
    cout<<"Tope de la pila 1: "<<endl;
    pila_ejemplo.obtener_tope();
    cout<<"Tope de la pila 2: "<<endl;
    pila_ejemplo2.obtener_tope();
    cout<<"Tope de la pila 3: "<<endl;
    pila_ejemplo3.obtener_tope();
    return 0;
}
