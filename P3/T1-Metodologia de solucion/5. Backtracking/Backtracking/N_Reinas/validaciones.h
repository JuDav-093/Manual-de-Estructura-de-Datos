#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <cctype>

int ingresar_enteros(const char* msj);
int borrar(char* datos, int& i);

int ingresar_enteros(const char* msj) {
    char* datos = new char[10];
    char c;
    int i = 0;

    printf("%s", msj);
    printf("\n");
    while ((c = _getch()) != 13 && i < 9) {
        if ((c >= '0' && c <= '9')|| c == 8) {
            if(c == 8){
                i = borrar(datos,i);
            }else{
                printf("%c", c);
                datos[i++] = c;
            }

        }
    }
    datos[i] = '\0';
    return atoi(datos);
}


int ingresar_enteros_definidos(const char* msj, bool para_bandos)
{
    char* datos = new char[1];
    char tecla;
    int i = 0;

    printf("%s", msj);
    printf("\n");

    while (true)
    {
        tecla = _getch();

        if (tecla == '\r' && i != 0)
        {
            break;
        }
        else if (tecla == '\r' && i == 0) {
            std::cout << "Ingrese un valor\n";
        }
        else if (tecla == '\b')
        {
            i = borrar(datos, i);
        }
        if (!para_bandos) {
            if (isdigit(tecla) && tecla != '-1' && tecla != '8' && i == 0)
            {
                printf("%c", tecla);
                datos[i++] = tecla;
            }
        }
        else {
            if ((tecla == '-' || tecla == '1') && i < 2)
            {   
                if (i == 0 || (i>0 && datos[0] == '-')) {
                    printf("%c", tecla);
                    datos[i++] = tecla;
                }
            }
        }
        
    }
    return atoi(datos);
}


int borrar(char* datos, int& i) {
    if (i > 0) {
        printf("\b \b");
        i--;
        datos[i] = '\0';
        return i;
    }
    return 0;
}

#endif // VALIDACIONES_H_INCLUDED
