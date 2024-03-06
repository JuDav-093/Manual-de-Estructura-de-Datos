#ifndef GENERADOR_COMBINACIONES_H
#define GENERADOR_COMBINACIONES_H

#include "Nodo.cpp"
#include <fstream>

class GeneradorCombinaciones {
public:
    static void generarCombinaciones(std::ofstream& archivoSalida);
private:
    static Nodo* crearLista();
    static void generarCombinacionesUtil(Nodo* elementos, int objetivo, int sumaActual, Nodo* combinacionActual, std::ofstream& archivoSalida);
};

#endif
