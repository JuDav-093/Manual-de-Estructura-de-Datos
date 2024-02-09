

#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include <vector>
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
bool validar_Ecuacion(const char* ecuacion);
static bool esOperador(char c);
static bool esParentesis(char c);
static bool esDigito(char c);
static bool posUltima(const char* c);
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


int borrar(char* datos, int& i) {
    if (i > 0) {
        printf("\b \b");
        i--;
        datos[i] = '\0';
        return i;
    }
    return 0;
}
static bool esOperador(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

static bool esParentesis(char c) {
        return c == '(' || c == ')';
    }

static bool esDigito(char c) {
        return std::isdigit(static_cast<unsigned char>(c)) != 0;
    }
static bool posUltima(const char* c){
   for (int i = 0; i < strlen(c); i++) {
    if (c[i] != '/' || c[i] != '-' || c[i] != '+' || c[i] != '*') {
      return i;
    }
  }
  return false;
  }
bool validar_Ecuacion(const char* ecuacion) {
        int parAbiertos = 0;
        for (int i = 0; ecuacion[i] != '\0'; ++i) {
            char c = ecuacion[i];
            char c1= ecuacion[0];
            char c2= ecuacion[1];

            if (ecuacion[0] == '+' || ecuacion[0] == '*' || ecuacion[0] == '/') {
    std::cout << "Ecuacion no valida: La ecuacion no puede comenzar con un operador.\n";
    return false;
  }

            if (esOperador(c)) {
                // Verificar que no hayan dos operadores consecutivos
                if (i > 0 && esOperador(ecuacion[i - 1])) {
                    std::cout << "Ecuacion no valida: Dos operadores consecutivos.\n";
                    return false;
                }
            } else if (esParentesis(c)) {
                // Verificar el balance de paréntesis
                if (c == '(') {
                    parAbiertos++;
                } else if (c == ')') {
                    parAbiertos--;
                    if (parAbiertos < 0) {
                        std::cout << "Ecuacion no valida: Parentesis desbalanceados.\n";
                        return false;
                    }
                }
            } else if (!esDigito(c)) {
                // Carácter no reconocido
                std::cout << "Ecuacion no valida: Caracter no reconocido.\n";
                return false;
            }
             if (esOperador(c) && i == strlen(ecuacion) - 1) {
      std::cout << "Ecuacion no valida: Operador en la ultima posicion.\n";
      return false;
    }
        if (esParentesis(c) && i == strlen(ecuacion) - 1) {
    if (esOperador(ecuacion[i - 1])) {
        std::cout << "Ecuacion no valida: Operador en la penultima posicion.\n";
        return false;
    }}
    if (ecuacion[0] == '(' ) {
    if (ecuacion[1] == '+' || ecuacion[1] == '*' || ecuacion[1] == '/') {
        std::cout << "con operador en la primera posicion.\n";
        return false;
    }}

    }




















   // Verificar el balance final de paréntesis
        if (parAbiertos != 0) {
            std::cout << "Ecuacion no valida: Parentesis desbalanceados.\n";
            return false;
        }


        std::cout << "Ecuacion valida.\n";
        return true;
    }


#endif // VALIDACIONES_H_INCLUDED
