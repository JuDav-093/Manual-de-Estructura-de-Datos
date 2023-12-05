/***********************************************************************
 * Module:  Matriz.cpp
 * Author:  joanc
 * Modified: 26 de noviembre de 2023.
 * Purpose: Implementation of the class Matriz
 ***********************************************************************/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include "Operaciones_matriz.h"


Operaciones_matriz::Operaciones_matriz(){
}

void Operaciones_matriz::encerar(Matriz& _matriz){
    for(int j=0;j<_matriz.get_nfilas();j++){
        *(_matriz.get_matriz()+j) = (int*)calloc(_matriz.get_ncol(), sizeof(int*));
    }
}

void Operaciones_matriz::imprimir(Matriz& _matriz){
	for(int i=0;i<_matriz.get_nfilas();i++){
		for(int j=0;j<_matriz.get_ncol();j++){
			printf("%d\t",*(*(_matriz.get_matriz()+i)+j));
		}
		printf("\n");
	}
}

Matriz Operaciones_matriz::multiplicar_recursivo_inslambda(Matriz& matriz1, Matriz& matriz2) {
    if(matriz1.get_ncol() == matriz2.get_nfilas()){
        Matriz _matriz(matriz1.get_nfilas(), matriz2.get_ncol());
        encerar(_matriz);
        auto multiplicar_recursivo = [this, &matriz1, &matriz2, &_matriz](int fil_act, int col_act, int mov, auto&&multiplicar_recursivo)->void{
			*(*(_matriz.get_matriz() + fil_act) + col_act) += *(*(matriz1.get_matriz() + fil_act) + mov) * (*(*(matriz2.get_matriz() + mov) + col_act));
			if (mov < matriz2.get_nfilas()-1) {
				multiplicar_recursivo(fil_act, col_act, mov + 1, multiplicar_recursivo);
			}
			else {
				mov = 0;
				if(fil_act < matriz1.get_nfilas()-1){
                    multiplicar_recursivo(fil_act + 1, col_act, mov, multiplicar_recursivo);
				}
				else if (col_act < matriz2.get_ncol()-1) {
					multiplicar_recursivo(0, col_act + 1, mov, multiplicar_recursivo);
				}
			}
		};
        multiplicar_recursivo(0,0,0, multiplicar_recursivo);
        return _matriz;
    }
    else{
        printf("Las matrices no cumplen el requisito dimensional para poder multiplicarse \n");
        return Matriz(0,0);
    }
}

void Operaciones_matriz::generar(Matriz& _matriz){
	for(int i=0;i<_matriz.get_nfilas();i++){
		for(int j=0;j<_matriz.get_ncol();j++){
			*(*(_matriz.get_matriz()+i)+j)=rand()%10;
		}
	}
}
