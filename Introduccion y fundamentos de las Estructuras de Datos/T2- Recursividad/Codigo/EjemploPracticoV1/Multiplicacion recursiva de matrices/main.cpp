/***********************************************************************
 * Module:  main.cpp
 * Author:  VerdesotoDamian
 * Modified: domingo, 26 de noviembre de 2023 23:44:51
 * Purpose: Multiplicación recursiva de matrices
 ***********************************************************************/

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "Multiplicacion.h"
#include <time.h>

int main(){

	srand (time(NULL));
	Cproceso p;

    //Menu del Programa
    system("cls");
    printf("\t\tMultiplicacion de Matrices con datos random\n");
    p.encerarMatriz();
	p.llenarMatriz();
	p.imprimirMatriz(p.getMat1(),"A");
	cout<<"\n";
	p.imprimirMatriz(p.getMat2(),"B");
	cout<<"\n";
	p.multiplicacionRecursivaMatrices( p.getMat1(),p.getMat2(),p.getMatR(), 2, 2, 2);
	p.imprimirMatriz(p.getMatR(),"R");

    system("pause");
    return 0;
}
