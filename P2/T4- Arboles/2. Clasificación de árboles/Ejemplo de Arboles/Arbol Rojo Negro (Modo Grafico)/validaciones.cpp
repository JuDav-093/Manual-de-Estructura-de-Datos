#include <iostream>
#include <conio.h>
#include <cctype>
#include <algorithm>
#include "validaciones.h"
#include <stdlib.h>
#include <stdio.h>


int Validaciones::borrar(char* datos, int i) {
    if (i > 0) {
        putchar(8);
        putchar(32);
        putchar(8);
        i--;
    }
    return i;
}

int Validaciones::validarNumero() {
    char* datos = new char[10];
    char c;
    int i = 0;

    while (true) {
        c = _getch();

        if ((c >= '0' && c <= '9') || c == 8) {
            if (c == 8) {
                i = borrar(datos, i);
            }
            else {
                printf("%c", c);
                datos[i++] = c;
            }
        }
        else if (c == 13) {
            break;
        }
    }
    datos[i] = '\0';
    return atoi(datos);
}