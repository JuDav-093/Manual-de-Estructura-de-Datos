#include <iostream>
#include "Matriz.h"

void Matriz::set_nfilas(int _nfilas)
{
    nfilas = _nfilas;
}

int Matriz::get_nfilas()
{
    return nfilas;
}

void Matriz::set_ncol(int _ncol)
{
    ncol = _ncol;
}

int Matriz::get_ncol()
{
    return ncol;
}

void Matriz::set_matriz(int** _matriz)
{
    matriz = _matriz;
}

int** Matriz::get_matriz()
{
    return matriz;
}
