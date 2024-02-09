#pragma once
#include <iostream>

// Definición del TDA Vector
class Vector {
private:
    int* array; // Puntero al array dinámico
    int tamanoActual;   // Tamaño actual del vector
    int tamanoVector;

public:
    Vector(int tamInicial) : tamanoActual(0) {
        array = new int[tamInicial]; // Asigna memoria para el array
        tamanoVector = tamInicial;
    }

    void insertar(int elemento) {
        if (tamanoActual < tamanoVector) {
            array[tamanoActual++] = elemento;
        }
        else {
            std::cout << "\n\nEl vector esta lleno\n" << std::endl;
            system("pause");
        }
    }

    void eliminar(int dato) {
        int indice = -1;
        for (int i = 0; i < tamanoActual; ++i) {
            if (array[i] == dato) {
                indice = i;
                break;
            }
        }
        if (indice != -1) {
            for (int i = indice; i < tamanoActual - 1; ++i) {
                array[i] = array[i + 1];
            }
            tamanoActual--; // Decrementar el tamaño del vector
        }
        else {
            std::cout << "\n\nNo se encontro el dato\n" << std::endl;
            system("pause");
        }
    }

    void imprimir() {
        std::cout << "\n\nVector:  ";
        for (int i = 0; i < tamanoActual; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl << std::endl;
        system("pause");
    }
};