#include "Calculo.cpp" 
# include <stdio.h> 
int main() 
{ 
	float a, b; //Declaracion de variables tipo float
    printf("Calculadora para numeros mayores a cero\n\n ");
  do {
  //se pide que se ingresen 2 numeros mayores a cero
  printf("Ingrese un numero a: ");
  scanf("%f", &a);
  printf("Ingrese un numero b: ");
  scanf("%f", &b);	
  if (a <= 0 || b <= 0) {
  	//si no se ingresa un numero correcto se imprime el mensaje y se vuelve a pedir los valores
    printf("El numero ingresado no es valido. Ingrese un numero mayor a cero \n\n");
  }
	} while (a <= 0 || b <= 0);
  // **Crea un objeto de la clase Calculo de tipo float**
  Calculo<float> intCalculo(a, b);
  // **Asigna los resultados de las operaciones aritméticas a variables**
  float resultadoSuma = intCalculo.sumar();
  float resultadoResta = intCalculo.restar();
  float resultadoMultiplicacion = intCalculo.multiplicar();
  // **Imprime los resultados**
  printf("La suma es: %f\n", resultadoSuma);
  printf("La resta es: %f\n", resultadoResta);
  printf("La multiplicación es: %f\n", resultadoMultiplicacion);
  // **Retorna 0**
  return 0;
} 
