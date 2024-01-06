#include <iostream>
#include "libro.cpp"

using namespace std;

int main() {
	
    // Creacion de objetos Libro
    Libro miLibro("Cien años de soledad", "Gabriel Garcia Marquez", 1967);
    Libro otroLibro("1984", "George Orwell", 1949);

    // Imprimir informacion de los libros
    cout << "Informacion del Libro:" << endl;
    miLibro.imprimirInformacion();

    cout << "Informacion de Otro Libro:" << endl;
    otroLibro.imprimirInformacion();

    return 0;
}
