#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <cstring>

int ingresar_enteros(const char* msj);
float ingresar_reales(const char* msj);
std::string ingresar_alfabetico(const char* msj);
void borrar(char* datos, int& i);

int ingresar_enteros(const char* msj) {
    char* datos = new char[10];
    char c;
    int i = 0;
    system("cls");
    printf(msj);
    while ((c = getch()) != 13 && i < 9) {
        if ((c >= '0' && c <= '9')|| c == 8) {
            if(c==8){
                borrar(datos,i);
            }else{
                printf("%c", c);
                datos[i++] = c;
            }

        }
    }
    datos[i] = '\0';
    return atoi(datos);
}

float ingresar_reales(const char* msj) {
    char* datos = new char[10];
    char c;
    int i = 0;
    bool hay_punto = false;

    system("cls");
    printf(msj);
    while ((c = getch()) != 13 && i < 9) {
        if ((c >= '0' && c <= '9') || (c == '.' && !hay_punto)|| c == 8) {
            if (c == 8) {
                borrar(datos, i);
            } else if (c == '.') {
                    hay_punto = true;
            }
            datos[i++] = c;
        }
    }
    datos[i] = '\0';
    return atof(datos);
}

std::string ingresar_alfabetico(const char* msj) {
    char datos[10];
    char c;
    int i = 0;
    system("cls");
    printf(msj);
    while ((c = getch()) != 13 && i < 9) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')|| c == 32||c == 8) {
            if (c == 8) {
                borrar(datos, i);
            } else {
                printf("%c",c);
                datos[i++] = c;
            }
        }
    }
    datos[i] = '\0';
    return std::string(datos);
}


void borrar(char* datos, int& i) {
    if (i > 0) {
        printf("\b \b");
        i--;
    }
    if (i > 0) {
        datos[i-1] = '\0';
    }
}

#endif // VALIDACIONES_H_INCLUDED
