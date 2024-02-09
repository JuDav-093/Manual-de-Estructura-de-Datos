#pragma once
#include <conio.h>
#include <iostream>

int borrar(char* datos, int& i) {
    if (i > 0) {
        printf("\b \b");
        i--;
        datos[i] = '\0';
        return i;
    }
    return 0;
}

int ingresar_enteros(std::string msj) {
    char* datos = new char[10];
    char c;
    int i = 0;

    std::cout << msj;
    while ((c = _getch()) != 13 && i < 9) {
        if ((c >= '0' && c <= '9') || c == 8) {
            if (c == 8) {
                i = borrar(datos, i);
            }
            else {
                printf("%c", c);
                datos[i++] = c;
            }

        }
    }
    datos[i] = '\0';
    return atoi(datos);
}
