#include "GeneradorCombinaciones.h"
#include "Validaciones.cpp"
#include <iostream>
#include <fstream>

void GeneradorCombinaciones::generarCombinaciones(std::ofstream& archivoSalida) {
    Validaciones validador;
	Nodo* elementos = crearLista();
    int objetivo;

    std::cout << "\n- Ingrese el objetivo: ";
    objetivo = validador.validarEnteros();
    std::cout << "\n";

    Nodo* combinacionActual = nullptr; // Nodo para la combinacion actual
    generarCombinacionesUtil(elementos, objetivo, 0, combinacionActual, archivoSalida);

    // Liberar memoria
    while (elementos != nullptr) {
        Nodo* siguiente = elementos->obtenerSiguiente();
        delete elementos;
        elementos = siguiente;
    }
}

Nodo* GeneradorCombinaciones::crearLista() {
	Validaciones validador;
    int n;
    std::cout << " =====   BUSQUEDA EXHAUSTIVA   =====\n\n";
    std::cout << "- Ingrese el numero de elementos: ";
    n = validador.validarEnteros();
    std::cout << "\n";

    Nodo* cabeza = nullptr; // Nodo inicial para la lista
    Nodo* temp = nullptr;

    for (int i = 1; i <= n; ++i) {
        int dato;
        std::cout << "  - Ingrese el elemento " << i << ": ";
        dato = validador.validarEnteros();
    	std::cout << "\n";

        if (cabeza == nullptr) {
            cabeza = new Nodo(dato);
            temp = cabeza;
        } else {
            temp->establecerSiguiente(new Nodo(dato));
            temp = temp->obtenerSiguiente();
        }
    }
    return cabeza;
}

void GeneradorCombinaciones::generarCombinacionesUtil(Nodo* elementos, int objetivo, int sumaActual, Nodo* combinacionActual, std::ofstream& archivoSalida) {
    if (sumaActual == objetivo) {
        // Imprimir la combinacion actual en la consola
        Nodo* temp = combinacionActual;
        while (temp != nullptr) {
            std::cout << temp->obtenerDato() << " ";
            temp = temp->obtenerSiguiente();
        }
        std::cout << std::endl;

        // Guardar la combinacion actual en el archivo de salida
        temp = combinacionActual;
        while (temp != nullptr) {
            archivoSalida << temp->obtenerDato() << " ";
            temp = temp->obtenerSiguiente();
        }
        archivoSalida << std::endl;

        return;
    }

    // Iterar sobre los elementos restantes
    Nodo* temp = elementos;
    while (temp != nullptr) {
        int nuevaSuma = sumaActual + temp->obtenerDato();
        if (nuevaSuma <= objetivo) {
            // Crear un nuevo nodo para la combinacion actual
            Nodo* nuevaCombinacion = new Nodo(temp->obtenerDato());
            nuevaCombinacion->establecerSiguiente(combinacionActual);

            // Llamada recursiva con el nuevo elemento agregado
            generarCombinacionesUtil(temp->obtenerSiguiente(), objetivo, nuevaSuma, nuevaCombinacion, archivoSalida);

            // Liberar memoria del nodo creado
            delete nuevaCombinacion;
        }
        temp = temp->obtenerSiguiente();
    }
}
