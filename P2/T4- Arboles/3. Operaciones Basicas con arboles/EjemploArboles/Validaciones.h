#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <cstring>

int ingresar_enteros(const char* msj);
int borrar(char* datos, int& i);
float ingresar_reales(const char* msj);
std::string ingresar_alfabetico(const char* msj);

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

float ingresar_reales(const char* msj) {
    char* datos = new char[12];
    char c;
    int i = 0;
    bool hay_punto = false;
    int posicion_punto;

    printf("%s", msj);
    printf("\n");
    while ((c = _getch()) != 13 && i < 11) {
        if ((c >= '0' && c <= '9') || (c == '.' && !hay_punto)|| c == 8 || c == '-') {
            if(!((c == '.')&& i == 0)){
                if(!((c == '-') && i != 0)){
                    if (c == 8) {
                        i = borrar(datos, i);
                        if((i+1) == posicion_punto){
                            hay_punto = false;
                        }
                    }
                    else {
                        printf("%c", c);
                        datos[i++] = c;

                        if (c == '.') {
                            posicion_punto = i;
                            hay_punto = true;
                        }
                    }
                }
            }
        }
    }
    datos[i] = '\0';
    return atof(datos);
}

std::string ingresar_alfabetico(const char* msj) {
    char datos[21];
    char c;
    int i = 0;

    printf("%s", msj);
    printf("\n");
    while ((c = _getch()) != 13 && i < 20) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')|| c == 32||c == 8) {
            if (c == 8) {
                i = borrar(datos, i);
            } else {
                printf("%c", c);
                datos[i++] = c;
            }
        }
    }
    datos[i] = '\0';
    return std::string(datos);
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
