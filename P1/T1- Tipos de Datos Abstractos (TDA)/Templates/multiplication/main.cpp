/*************************
 * Module:  main.cpp
 * Author:  JoseSanmartin, Ruben Benavidez
 * Modified: lunes, 27 de noviembre de 2023
 * Purpose: Exercise of Overide
 *************************/
//Llamamos las librerias adecuadas
#include <iostream>
#include "Frac.cpp"

int main(){
    Frac<int> F1, F2, result;

    system("cls");
    //Pedimos al usuario que ingrese la primera fraccion
    cout << "Enter the fist fraction: " << endl;
    F1.in();
    //Pedimos al usuario que ingrese laSegunda fraccion
    cout << "Enter the secod fraction: " << endl;
    F2.in();
    // Se realiza la operacion
    result = F1 * F2;
    //Imprimos el resultado
    result.out();

    return 0;
}
