#include<iostream> 
#include<conio.h> 
#include "Calculo.h" 
#include <stdio.h> 
using namespace std; 
// **Función para sumar los valores de a y b**
template <typename T> 
T Calculo<T>::sumar() { 
 return a + b;  
 } 
// **Función para restar los valores de a y b** 
template <typename T> 
T Calculo<T>::restar() { 
 return a - b;  
 } 
// **Función para multiplicar los valores de a y b**
template <typename T> 
T Calculo<T>::multiplicar() { 
 return a * b;  
 } 
 

