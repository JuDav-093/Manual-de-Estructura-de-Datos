#ifndef LIBRO_H
#define LIBRO_H

#include <string>

using namespace std;

class Libro {
public:
    // Constructor de la clase Libro
    Libro(string titulo, string autor, int anioPublicacion);

    // Metodo para imprimir la informacion del libro
    void imprimirInformacion() const;

private:
    // Atributos de la clase Libro
    string titulo;
    string autor;
    int anioPublicacion;
};

#endif
