#include "libro.h"
#include <iostream>

using namespace std;

// Constructor de la clase Libro
Libro::Libro(string titulo, string autor, int anioPublicacion)
    : titulo(titulo), autor(autor), anioPublicacion(anioPublicacion) {}

// Metodo para imprimir la informacion del libro
void Libro::imprimirInformacion() const {
    cout << "Titulo: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "Año de publicacion: " << anioPublicacion << endl;
    cout << "------------------------" << endl;
}
