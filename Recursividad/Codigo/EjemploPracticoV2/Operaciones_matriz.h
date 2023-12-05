#ifndef OPERACIONES_MATRIZ_H_INCLUDED
#define OPERACIONES_MATRIZ_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include "Matriz.h"

class Operaciones_matriz{
public:
    Operaciones_matriz();
    void encerar(Matriz&);
    void imprimir(Matriz&);
    Matriz multiplicar_recursivo_inslambda(Matriz&, Matriz&);
    void generar(Matriz&);
protected:
private:
};



#endif // OPERACIONES_MATRIZ_H_INCLUDED
