#pragma once
#include <iostream>
#include <stdlib.h>
#include <conio.h>

int ingresoNumeroEntero(char* mensaje) {
    int numero = 0;
    int numeroAux = 0;
    int terminos = 0;
    char c;
    bool primerDigitoIngresado = false;
    bool continuar = true;
    std::cout << mensaje;
    do {
        c = _getch();
        if (c >= '0' && c <= '9') {
            primerDigitoIngresado = true;
            numeroAux = numeroAux * 10 + (c - '0');
            printf("%c", c);
            numero = numeroAux;
        }
        if (c == 8 && primerDigitoIngresado) {
            numeroAux = numero;
            std::cout << "\b \b";
            numeroAux /= 10;
            if (numeroAux == 0) {
                primerDigitoIngresado = false;
            }
            numero = numeroAux;
        }
        if (c == 13 && primerDigitoIngresado) {
            continuar = false;
        }
    } while (continuar);
    return numero;
}