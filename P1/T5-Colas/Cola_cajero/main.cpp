#include <iostream>
#include <ctime>
#include "validaciones.h"
#include "Cola.h"
#include "Generacion_cola.h"
#include "menus.h"

int main() {
    std::srand(std::time(nullptr));
	
	const int N_OPCIONES = 3;
	const char* OPCIONES[N_OPCIONES] = {"Generar cola con n clientes", "Abrir archivo desde excel", "Salir"};
	int opcion;

	std::string nombre_archivo = "COLAS.csv";
	std::string comando = "start excel.exe " + nombre_archivo;
	int n_clientes;

	do {
		system("cls");
		opcion = desplegar_menu(OPCIONES, N_OPCIONES);
		system("cls");

		if (opcion == 1) {
			n_clientes = ingresar_enteros("Ingrese el numero de clientes a generar la cola");
			(guardar_cola(generar_cola(n_clientes), nombre_archivo)) ? printf("\nSe genero correctamente el archivo\n"): printf("\nSe genero correctamente el archivo\n");

		}
		else if (opcion == 2) {
			if (system(comando.c_str()) != 0) {
				std::cerr<<"Error al abrir el archivo\nAsegurese de que generar primero la cola";
			}
		}
		else {
			printf("\n************ Byebye haz mewing :) ************\n");
		}

		system("pause");

	} while (opcion != N_OPCIONES);

	system("pause");
	return 0;
}