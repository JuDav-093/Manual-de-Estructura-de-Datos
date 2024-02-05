#include <iostream>
#include "validaciones.h"
#include "Cola.h"

int main()
{
    int opcion, dato;
	Cola cola;
	do {
		system("cls");
		printf("\n1. Insertar elementos a la cola");
		printf("\n2. Eliminar elemento de la cola");
		printf("\n3. Imprimir cola");
		printf("\n0. Salir");
		opcion = ingresar_enteros("\nIngrese una opcion del menu:  ");
		printf("\n");
		switch (opcion) {
		case 1:
			dato = ingresar_enteros("\nIngresar un entero:  ");
			printf("\n");
			printf("\n");
			cola.insertar(dato);
			system("pause");
			break;
		case 2:
			printf("\n");
			cola.eliminar();
			system("pause");
			break;
		case 3:
			printf("\n");
			cola.imprimir();
			printf("\n");
			printf("\n");
			system("pause");
			break;
        }
	} while (opcion != 0);
	system("pause");
    return 0;
}
