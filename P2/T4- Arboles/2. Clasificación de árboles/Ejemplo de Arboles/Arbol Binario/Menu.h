#pragma once
#include <windows.h>
#include <iostream>

using namespace std;

int mostrarMenu();
int leer_entero(const string mensaje);

int mostrarMenu() {
	cout << "\t\tARBOL BINARIO\n" << endl;
	cout << "\t1. Insertar Elemento" << endl;
	cout << "\t2. Eliminar Elemento" << endl;
	cout << "\t3. Buscar Elemento" << endl;
	cout << "\t4. Arbol en Inorden" << endl;
	cout << "\t5. Dibujar" << endl;
	cout << "\t6. Salir" << endl;
	cout << "\tIngrese una opcion:  ";
	int opcion;
	cin >> opcion;
	return opcion;
}

int leer_entero(const std::string mensaje) {
    int valor;

    cout << mensaje;
    cin >> valor;

    return valor;
}