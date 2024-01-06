
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "Cproceso.h"
#include <time.h>

int main(){

	srand (time(NULL));
	Cproceso p;

    //Menu del Programa
    system("cls");
    printf("\t\tSuma de Matrices con datos random\n");
    p.encerarMatriz();
	p.llenarMatriz();
	p.imprimirMatriz(p.getMat1(),"A");
	cout<<"\n";
	p.imprimirMatriz(p.getMat2(),"B");
	cout<<"\n";
	p.sumaRecursivaMatrices( p.getMat1(),p.getMat2(),p.getMatR(), 2, 2);
	p.imprimirMatriz(p.getMatR(),"R");
	cout<<"\nPulse enter para continuar\n"<<endl;
	getch();

    system("pause");
    return 0;
}
