#include "Validacion.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string>

void Validacion::backSpace(char* datos, int& i) {
    if (i > 0) {
        std::cout << "\b \b";
        i--;
        datos[i] = '\0';
    }
}

char* Validacion::ingresoNumerico(const char* msj) {
    char* datos = new char[10];
    char c;
    int i = 0;
    system("cls");
    std::cout << msj << std::endl;
    while ((c = getch()) != 13 && i < 9) {
        if ((c >= '0' && c <= '9') || c == 8) {
            if (c == 8) {
                backSpace(datos, i);
            } else {
                printf("%c", c);
                datos[i++] = c;
            }
        }
    }
    datos[i] = '\0';
    return datos;
}

char* Validacion::ingresoDecimal(const char* msj) {
    char* datos = new char[10];
    char c;
    int i = 0;
    bool puntoDecimal = false;

    system("cls");
    std::cout << msj << std::endl;
    while ((c = getch()) != 13 && i < 9) {
        if ((c >= '0' && c <= '9') || (c == '.' && !puntoDecimal) || c == 8) {
            if (c == 8) {
                backSpace(datos, i);
                if (datos[i - 1] == '.') {
                    puntoDecimal = false;
                }
            } else {
                if (c == '.') {
                    puntoDecimal = true;
                }
                std::cout << c;
                datos[i++] = c;
            }
        }
    }
    datos[i] = '\0';
    return datos;
}

std::string Validacion::ingresoAlfabetico(const char* msj) {
    char datos[10];
    char c;
    int i = 0;
    system("cls");
    std::cout << msj << std::endl;
    while ((c = getch()) != 13 && i < 9) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == 32 || c == 8) {
            if (c == 8) {
                backSpace(datos, i);
            } else {
                std::cout << c;
                datos[i++] = c;
            }
        }
    }
    datos[i] = '\0';
    return std::string(datos);
}
