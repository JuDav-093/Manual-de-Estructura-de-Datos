#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void agregar(std::string nombre) {
    std::ofstream archivo("nombres.txt", std::ios_base::app);

    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo." << std::endl;
        return;
    }

    archivo << nombre << std::endl;
    archivo.close();
}

void mostrar() {
    std::ifstream archivo("nombres.txt");

    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo." << std::endl;
        return;
    }

    std::string nombre;
    std::cout << "Nombres:" << std::endl;
    while (std::getline(archivo, nombre)) {
        std::cout << nombre << std::endl;
    }

    archivo.close();
}

std::vector<std::string> obtenerNombres() {
    std::ifstream archivo("nombres.txt");
    std::vector<std::string> listaNombres;

    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo." << std::endl;
        return listaNombres;
    }
    std::string nombre;
    while (std::getline(archivo, nombre)) {
        listaNombres.push_back(nombre);
    }
    archivo.close();

    return listaNombres;
}