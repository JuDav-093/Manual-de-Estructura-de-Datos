#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <sstream>
#include "Mapa.h"
#include "TablaHash.h"

std::string trim(const std::string& to_trim) {

    size_t first = to_trim.find_first_not_of(" \t\n\r");
    size_t last = to_trim.find_last_not_of(" \t\n\r");

    if (first == std::string::npos || last == std::string::npos) {
        // La cadena está completamente compuesta por espacios en blanco
        return "";
    }

    return to_trim.substr(first, last - first + 1);
}

TablaHash<Mapa*>* cargar_traducciones() {
    
    TablaHash<Mapa*>* traducciones = new TablaHash<Mapa*>(79);

    std::string ruta;
    char tmp[256];

    _getcwd(tmp, 256);
    ruta = std::string(tmp);

    std::string nombre_original = ruta + "//" + "Traducciones.txt";

    std::ifstream archivo_original(nombre_original);
    std::string linea;
    std::string traducir;
    std::string traduccion;
    Mapa* mapa;

    if (!archivo_original) {
        std::cout << "\nNo se pudieron cargar las traducciones\n";
        return traducciones;
    }
    else {
        while (std::getline(archivo_original, linea))
        {
            std::istringstream ss(linea);
            std::getline(ss, traducir, ':');
            std::getline(ss, traduccion, ':');


            mapa = new Mapa(trim(traducir), trim(traduccion));

            traducciones->insertar(mapa, mapa->get_traducir());
        }
    }

    archivo_original.close();
    
    return traducciones;
}