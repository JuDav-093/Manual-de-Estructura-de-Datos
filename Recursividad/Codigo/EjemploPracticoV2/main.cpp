#include <iostream>
#include <time.h>
#include "Matriz.h"
#include "Operaciones_matriz.h"
#include "validaciones.h"

int main(){
    srand(time(NULL));

    int m, n, p;
    Matriz mat1, mat2;

    m = ingresar_enteros("Ingrese el numero de filas de la matriz 1: \n");
    n = ingresar_enteros("Ingrese el numero de columnas de la matriz 1: \n");
    mat1 = Matriz(m,n);
    n = ingresar_enteros("Ingrese el numero de filas de la matriz 2: \n");
    p = ingresar_enteros("Ingrese el numero de columnas de la matriz 2: \n");
    mat2 = Matriz(n,p);

    Operaciones_matriz op;

    system("cls");

    op.encerar(mat1);
    op.generar(mat1);

    op.encerar(mat2);
    op.generar(mat2);

    Matriz matR = op.multiplicar_recursivo_inslambda(mat1, mat2);

    if(matR.get_ncol() != 0){
        op.imprimir(mat1);
        printf("\n \t x \t \n\n");
        op.imprimir(mat2);
        printf("\n \t = \t \n\n");
        op.imprimir(matR);
    }

    system("pause");
    return 0;
}
