/***********************************************************************
 * Module:  validaciones.h
 * Author:  Edison Verdesoto
 * Modified: viernes, 20 de noviembre de 2023 11:05:38 a. m.
 * Purpose: Declaration of the class validaciones
 ***********************************************************************/

#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include "Stack.h"
#include "Node.h"

int ingresar_enteros(const char* msj);
int borrar(char* datos, int& i);
float ingresar_reales(const char* msj);
std::string ingresar_alfabetico(const char* msj);
bool es_especial (char tecla){
    return (tecla == 'c' || tecla == 's' ||tecla == 'r'  || tecla == 't' || tecla == 'l');
}

bool esParentesis(char tecla){
	return (tecla == '('|| tecla == ')');
}

bool esOperador(char tecla){
	return (tecla == '+' || tecla == '-' || tecla == '*' || tecla == '/'|| tecla == '^');
}

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

int ingresarDimension(char filas, char columnas) {
    char *entrada = new char[30];
    char tecla;
    int i = 0;
    int dim;

    while (true) {
        tecla = getch();

        if (tecla == '\r') {
            dim = atoi(entrada);
            if (dim >= 2) {
                std::cout << std::endl;
                break;
            } else {
                std::cout << "La dimension no puede ser menor a 2" << std::endl;
            }

        } else if (tecla == '\b' && i > 0) {
            i--;
            std::cout << "\b \b";
            entrada[i] = 0;
        } else if (tecla >= filas && tecla <= columnas && i < 1) {
            entrada[i++] = tecla;
            std::cout << tecla;
        }
    }

    return dim;
}

int ingresarEntero() {
    char *entrada = new char[30];
    char tecla;
    int i = 0;

    while (true) {
        tecla = getch();

        if (tecla == '\r') {
            std::cout << std::endl;
            break;
        } else if (tecla == '\b' && i > 0) {
            i--;
            std::cout << "\b \b";
            entrada[i] = 0;
        } else if (isdigit(tecla) && i < 12) {
            entrada[i++] = tecla;
            std::cout << tecla;
        }
    }

    return atoi(entrada);
}

float ingresarFloat() {
    char *entrada = new char[30];
    char tecla;
    int i = 0;
    bool punto = false;
    int signoMenosPos = -1;

    while (true) {
        tecla = getch();

        if (tecla == '\r') {
            std::cout << std::endl;
            break;
        } else if (tecla == '\b' && i > 0) {
            i--;
            std::cout << "\b \b";
            if (entrada[i] == '.') {
                punto = false;
            }
            if (i == signoMenosPos) {
                signoMenosPos = -1;
            }
            entrada[i] = 0;
        } else if (isdigit(tecla) && i < 15) {
            entrada[i++] = tecla;
            std::cout << tecla;
        } else if (tecla == '.' && !punto) {
            entrada[i++] = tecla;
            punto = true;
            std::cout << tecla;
        } else if (tecla == '-' && i == 0) {
            entrada[i++] = tecla;
            signoMenosPos = i - 1;
            std::cout << tecla;
        }
    }

    return atof(entrada);
}

void ingresar_expresion(Stack<char>* expresion, char tecla){
    int parentesisApertura = 0;
    int parentesisCierre = 0;
    int caracteresEliminar= 0;
    Node<char>* aux = expresion->get_top();
    char elementoAnterior;
    char elementoAnteriorAnterior;
    bool huboPunto = false;
    bool hayPunto = false;
    bool contadorOp = false;
    bool negativo = false;

    auto expresion_borrar = [&caracteresEliminar, &expresion, &parentesisApertura](){
        for (int i = 0; i < caracteresEliminar; i++){
            std::cout << "\b \b";
            expresion->delete_of_stack();
        }
        parentesisApertura--;
    };

    while (true) {
    aux = expresion->get_top();
        if(aux != nullptr){
            elementoAnterior = aux->get_value();
            if (aux->get_below() != nullptr){
                elementoAnteriorAnterior = aux->get_below()->get_value();
            }
            else {
                elementoAnteriorAnterior = '\0';
            }
        }
        else {
            elementoAnterior = '\0';
            elementoAnteriorAnterior = '\0';
        }
        tecla = getch();
        if (tecla == '\r' && !expresion->is_stack_void() && !esOperador(elementoAnterior) && elementoAnterior != '.') {
            if (parentesisApertura == parentesisCierre) {
                break;
            }
        }
        else if (tecla == '\b' && !expresion->is_stack_void()) {
            if (elementoAnterior == 'i' || (elementoAnterior == '(' && (elementoAnteriorAnterior == 's' ||
                elementoAnteriorAnterior == 'n' || elementoAnteriorAnterior == 'z') || elementoAnteriorAnterior == 'g')) {
                caracteresEliminar = 4;
                if (elementoAnterior == 'i') {
                    caracteresEliminar = 2;
                }
                else if (elementoAnteriorAnterior == 'z') {
                    caracteresEliminar = 5;
                }
                expresion_borrar();
            }
            else if (esParentesis(elementoAnterior)) {
                std::cout << "\b \b";
                expresion->delete_of_stack();
                contadorOp = elementoAnterior == ')';
                parentesisCierre -= (elementoAnterior == ')');
                parentesisApertura -= (elementoAnterior == '(');
            }
            else if (elementoAnterior == '.') {
                std::cout << "\b \b";
                expresion->delete_of_stack();
                hayPunto = false;
            }
            else if (esOperador(elementoAnterior)) {
                std::cout << "\b \b";
                expresion->delete_of_stack();
                hayPunto = huboPunto;
            }
            else {
                std::cout << "\b \b";
                expresion->delete_of_stack();
            }

        }
        if (isalpha(tecla) && elementoAnterior != '.' && (esOperador(elementoAnterior) || elementoAnterior == '(' || expresion->is_stack_void())) {
            if (es_especial(tecla)) {
                switch (tecla) {
                    case 'c':
                        expresion->aggregate('c');
                        expresion->aggregate('o');
                        expresion->aggregate('s');
                        std::cout << "cos(";
                        break;
                    case 's':
                        expresion->aggregate('s');
                        expresion->aggregate('i');
                        expresion->aggregate('n');
                        std::cout << "sin(";
                        break;
                    case 't':
                        expresion->aggregate('t');
                        expresion->aggregate('a');
                        expresion->aggregate('n');
                        std::cout << "tan(";
                        break;
                    case 'r':
                        expresion->aggregate('r');
                        expresion->aggregate('a');
                        expresion->aggregate('i');
                        expresion->aggregate('z');
                        std::cout << "raiz(";
                        break;
                }
                expresion->aggregate('(');
                parentesisApertura++;
            }
        }
        if (esParentesis(tecla)) {
            if (tecla == '(' && elementoAnterior != '.' && (esOperador(elementoAnterior) || elementoAnterior == '('
                                || expresion->is_stack_void())) {
                parentesisApertura++;
                expresion->aggregate(tecla);
                std::cout << tecla;
            } else if (tecla == ')' && elementoAnterior != '.' && elementoAnterior != '(' && !esOperador(elementoAnterior)
                                && (isdigit(elementoAnterior) || elementoAnterior == ')' || elementoAnterior == 'i')) {
                parentesisCierre++;
                if (parentesisApertura > 0 && parentesisCierre <= parentesisApertura) {
                    expresion->aggregate(tecla);
                    std::cout << tecla;
                    contadorOp = false;
                } else {
                    parentesisCierre--;
                }
            }
        }
        else if (isdigit(tecla) && elementoAnterior != 'i' &&(expresion->is_stack_void() || esOperador(elementoAnterior)|| elementoAnterior == '('
                                || isdigit(elementoAnterior) || elementoAnterior == '.')) {
            int k = 0;
            if (!expresion->is_stack_void()){
                Node<char>* c_aux = expresion->get_top();
                for (k; k < 8; k++){
                    if (c_aux == nullptr){
                        break;
                    }
                    else if (!isdigit(c_aux->get_value())) {
                        break;
                    }
                    c_aux = c_aux->get_below();
                }
            }
            if (elementoAnterior == '0' && (elementoAnteriorAnterior == '\0' || esOperador(elementoAnteriorAnterior))) {
                k = 8;
            }
            if (k < 7) {
                expresion->aggregate(tecla);
                std::cout << tecla;
            }
        }
        else if (esOperador(tecla) && elementoAnterior != '.' && !esOperador(elementoAnterior)
                                && elementoAnterior != '(' && !expresion->is_stack_void() && contadorOp==false ) {
            expresion->aggregate(tecla);
            std::cout << tecla;
            huboPunto = hayPunto;
            hayPunto = false;
        }
        else if (tecla == '-' && !esOperador(elementoAnterior) && elementoAnterior != '.'
                                && elementoAnterior == '(' && elementoAnteriorAnterior != 'z' && elementoAnteriorAnterior != 'g') {
            expresion->aggregate(tecla);
            std::cout << tecla;
            contadorOp = true;
        }
        else if (tecla == '.' && isdigit(elementoAnterior)) {
            if (!hayPunto) {
                expresion->aggregate(tecla);
                std::cout << tecla;
                hayPunto = true;
            }
        }
    }
}



#endif // VALIDACIONES_H_INCLUDED
