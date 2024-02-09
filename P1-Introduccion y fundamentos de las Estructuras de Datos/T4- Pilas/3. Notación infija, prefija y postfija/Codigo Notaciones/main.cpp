/***********************************************************************
 * Module:  main.cpp
 * Author:  Edison Verdesoto
 * Modified: viernes, 19 de diciembre de 2023 15:05:38 a. m.
 * Purpose: main class
 ***********************************************************************/

#include <iostream>
#include "Stack.h"
#include "Stacks_operations.h"
#include "validaciones.h"
#include <string>

int main()
{
    std::string expresion;

                std::cout <<"\nIngrese la expresion en notacion infija: "<<std::endl;
                std::string expresion = ingresarExpresion();
                std::string expresion_posfija = polaca_inversa(expresion);
                std::string expresion_prefija = polaca(expresion);
                std::string expresion_impares = polaca_inversa_impares(expresion);
                printf("\nExpresion en notacion infija: %s\n", expresion.c_str());
                printf("Expresion en notacion prefija: %s\n", expresion_prefija.c_str());
                printf("Expresion en notacion postfija: %s\n", expresion_posfija.c_str());
                system("pause");
    return 0;
}