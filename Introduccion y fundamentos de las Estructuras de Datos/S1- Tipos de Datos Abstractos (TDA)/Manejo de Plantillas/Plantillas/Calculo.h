#include<iostream>
#include<conio.h>
#include <iostream> 
using namespace std; 
// **Declaración de la plantilla de la clase Calculo**
template <typename T> 
class Calculo 
{ 
public: 
// **Constructor**
// Este constructor inicializa las 2 variables privadas
// de la clase Calculo, con los valores especificados en
// los valores especificados en los argumentos a y b tipo template
	Calculo(T a, T b) : a(a), b(b) {}; 
// **Función para sumar los valores de a y b**
    T sumar(); 
// **Función para restar los valores de a y b**
    T restar(); 
// **Función para multiplicar los valores de a y b**
    T multiplicar(); 
private: 
// **Atributos**
// Almacenan los valores de tipo T que se utilizarán en las operaciones.
    T a; 
    T b; 
}; 

