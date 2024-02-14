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

std::string ingresarNombre(std::string mensaje) {
    std::string datos;
    char c;
    int i = 0;
    std::cout << mensaje;
    bool continuar = true;
    do {
        c = _getch();
        if ((c >= 'A' && c <= 'Z' && i == 0) || (c >= 'a' && c <= 'z' && i > 0)) {
            printf("%c", c);
            datos.push_back(c);
            i++;
        }
        else if (c == 8 && i > 0) {
            printf("\b \b");
            i--;
            datos.pop_back();
        }
        if (c == 13 && i > 1) {
            continuar = false;
        }
    } while (continuar);
    return datos;
}