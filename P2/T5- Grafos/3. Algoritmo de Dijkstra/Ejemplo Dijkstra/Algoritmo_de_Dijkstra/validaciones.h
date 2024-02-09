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
#include <cctype>

int ingresar_enteros(const char* msj);
int borrar(char* datos, int& i);
float ingresar_reales(const char* msj);
std::string ingresar_alfabetico(const char* msj);

bool esEspecial(char tecla)
{
    return(tecla == 'c' || tecla == 's' ||tecla == 'r'  || tecla == 't');
}

bool esParentesis(char tecla)
{
    return (tecla == '('|| tecla == ')');
}

bool esOperador(char tecla)
{
    return (tecla == '+' || tecla == '-' || tecla == '*' || tecla == '/'|| tecla == '^');
}

int ingresar_enteros(const char* msj)
{
    char* datos = new char[10];
    char c;
    int i = 0;

    printf("%s", msj);
    printf("\n");

    while ((c = _getch()) != 13 || i == 0)
    {
        if(i<8 || c == 8)
        {
            if ((c >= '0' && c <= '9')|| c == 8)
            {
                if(c == 8)
                {
                    i = borrar(datos,i);
                }
                else
                {
                    printf("%c", c);
                    datos[i++] = c;
                }

            }
        }
    }
    datos[i] = '\0';
    return atoi(datos);
}

float ingresar_reales(const char* msj)
{
    char* datos = new char[12];
    char c;
    int i = 0;
    bool hay_punto = false;
    int posicion_punto;

    printf("%s", msj);
    printf("\n");

    while ((c = _getch()) != 13 && i < 11)
    {
        if ((c >= '0' && c <= '9') || (c == '.' && !hay_punto)|| c == 8 || c == '-')
        {
            if(!((c == '.')&& i == 0))
            {
                if(!((c == '-') && i != 0))
                {
                    if (c == 8)
                    {
                        i = borrar(datos, i);
                        if((i+1) == posicion_punto)
                        {
                            hay_punto = false;
                        }
                    }
                    else
                    {
                        printf("%c", c);
                        datos[i++] = c;

                        if (c == '.')
                        {
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

std::string ingresar_alfabetico(const char* msj)
{
    char datos[21];
    char c;
    int i = 0;

    printf("%s", msj);
    printf("\n");

    while ((c = _getch()) != 13 && i < 20)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')|| c == 32||c == 8)
        {
            if (c == 8)
            {
                i = borrar(datos, i);
            }
            else
            {
                printf("%c", c);
                datos[i++] = c;
            }
        }
    }
    datos[i] = '\0';
    return std::string(datos);
}

int ingresar_caracter(const char* msj)
{
    char dato;
    char c;
    int i = 0;

    printf("%s", msj);
    printf("\n");

    while ((c = _getch()) != 13 || i == 0)
    {
        if(i < 1 || c == 8)
        {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')|| c == 8)
            {
                if(c == 8)
                {
                    printf("\b \b");
                    i = (i==0)? i : i-1;
                }
                else
                {
                    printf("%c", c);
                    i++;
                    dato = c;
                }

            }
        }
    }
    return dato;
}


int borrar(char* datos, int& i)
{
    if (i > 0)
    {
        printf("\b \b");
        i--;
        datos[i] = '\0';
        return i;
    }
    return 0;
}

std::string ingresar_string(const char* msj)
{
    char *entrada = new char[21];
    char tecla;
    int i = 0;

    printf("%s", msj);
    printf("\n");

    while (true)
    {
        tecla = _getch();

        if (tecla == '\r' && i > 0)
        {
            break;
        }

        else if (tecla == '\b' && i > 0)
        {
            std::cout << "\b \b";
            i--;
            entrada[i] = 0;
        }
        else if (isalpha(tecla))
        {
            if (i == 0)
            {
                char tecla_M = toupper(tecla);
                entrada[i++] = tecla_M;
                std::cout << tecla_M;
            }
            else if (std::isupper(tecla))
            {
                char tecla_m = tolower(tecla);
                entrada[i++] = tecla_m;
                std::cout << tecla_m;
            }
            else if (std::islower(tecla))
            {
                entrada[i++] = tecla;
                std::cout << tecla;
            }
        }
    }
    entrada[i] = '\0';
    return entrada;
}

bool es_cedula_valida(std::string cedula)
{
    int suma_verif = 0;
    int digito_verificador = cedula[9]-'0';
    int decena_prox;
    int digito_actual_sum;
    int codigo_prov = 0;

    for(int i = 0; i < 9; i++)
    {
        digito_actual_sum = cedula[i]-'0';

        if(i % 2 == 0)
        {
            digito_actual_sum *= 2;

            if(digito_actual_sum > 9)
                digito_actual_sum -= 9;
        }
        if(i<2)
        {
            codigo_prov = codigo_prov*10 + (cedula[i]-'0');
            if(i==1)
            {
                if(codigo_prov<1 || codigo_prov>30)
                {
                    return false;
                }
            }
        }


        suma_verif += digito_actual_sum;
    }

    decena_prox = (suma_verif/10);

    if(suma_verif % 10 != 0)
        decena_prox += 1;

    decena_prox *= 10;

    return (decena_prox-suma_verif == digito_verificador);
}

std::string ingresar_numeros_cedula(const char* msj)
{
    char* datos = new char[11];
    char c;
    int i = 0;
    bool es_valida;

    printf("%s", msj);
    printf("\n");

    do
    {
        while ((c = _getch()) != 13)
        {
            if(i<10 || c == 8)
            {
                if ((c >= '0' && c <= '9')|| c == 8)
                {
                    if(c == 8)
                    {
                        i = borrar(datos,i);
                    }
                    else
                    {
                        printf("%c", c);
                        datos[i++] = c;
                    }

                }
            }
        }

        es_valida = es_cedula_valida(std::string(datos));

        if(!es_valida)
        {
            int borrar_cont = 0;
            for(borrar_cont; borrar_cont<10; borrar_cont++)
            {
                printf("\b \b");
            }

            printf("Cedula invalida, pulse una tecla para editarla");
            _getch();

            for(borrar_cont = 0; borrar_cont<50; borrar_cont++)
            {
                printf("\b \b");
            }

            for(borrar_cont = 0; borrar_cont<i; borrar_cont++)
            {
                printf("%c", datos[borrar_cont]);
            }
        }
    }
    while(!es_valida);

    datos[i] = '\0';
    return std::string(datos);
}

#endif // VALIDACIONES_H_INCLUDED
