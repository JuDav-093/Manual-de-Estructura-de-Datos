#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iomanip>

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
    while ((c = getch()) != 13 && i < 9) {
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
    while ((c = getch()) != 13 && i < 11) {
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
    while ((c = getch()) != 13 && i < 20) {
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

int ingresar_enteros_1_al_4(const char* msj) {
    char* datos = new char[10];
    char c;
    int i = 0;

    printf("%s", msj);
    printf("\n");
    while ((c = getch()) != 13 && i < 9) {
        if ((c >= '1' && c <= '4')|| c == 8) {
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

std::string generarEtiqueta() {
    static int contador = 0; // Variable estatica para mantener el estado entre llamadas
    std::string etiqueta = "L";

    if (contador < 10) {
        etiqueta += "000" + std::to_string(contador);
    } else if (contador < 100) {
        etiqueta += "00" + std::to_string(contador);
    } else if (contador < 1000) {
        etiqueta += "0" + std::to_string(contador);
    } else {
        etiqueta += std::to_string(contador);
    }

    contador++;
    if (contador >= 10000) {
        contador = 0; // Reiniciar el contador si llega a 10000
    } else if (contador == 10000 - 1) {
        contador = 0; // Reiniciar el contador si llega a L9999
    }

    printf("Id %s generado.\n", etiqueta.c_str());
    return etiqueta;
}

std::string ingresar_nombre(const char* msj) {
    char nombre[21];
    char c;
    int i = 0;

    printf("%s", msj);
    printf("\n");

    while ((c = getch()) != 13 && i < 20) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == 8) {
            if (c == 8) {
                i = borrar(nombre, i);
            } else {
                printf("%c", c);
                nombre[i++] = c;
            }
        }
    }

    nombre[i] = '\0';

 for (int j=0;j<21;j++){
        if (j ==0) {
        nombre[0] = std::toupper(nombre[0]);
    }else{
        nombre[j] = std::tolower(nombre[j]);
    }

}
return std::string(nombre);
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
