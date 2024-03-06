/*************************
 UFA - ESPE
 * Module:  Validacoines.h
 * Author:  Chiliquinga Yeshua, Marin Alquinga,Salcedo Micaela
 * Modified: domingo, 17 de diciembre de 2023
 * Purpose: Declaracion del encabezado validaciones
 ***********************************************************************/
#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <ios>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <fstream>

class validaciones{
    public:
        int ingresar_enteros(const char* msj);
        int borrar(char* datos, int& i);
        float ingresar_reales(const char* msj);
        std::string ingresar_alfabetico(const char* msj);
        int ingresar_diaMes(const char* msj);
        int ingresar_anio(const char* msj);
        std::string ingresar_cedula(const char* msj);
        std::string ingresar_numeros_como_string(const char* msj);
        bool validarCedula(std::string cedula);
        std::string mayusculas_primeras(const std::string& cadena);
        std::string ingresar_cadena_con_espacio(const char* msj);
        std::string ingresar_alfabetico_con_un_espacio(const char* msj);
         std::string leerArchivoTxt();

};

#endif // VALIDACIONES_H_INCLUDED
