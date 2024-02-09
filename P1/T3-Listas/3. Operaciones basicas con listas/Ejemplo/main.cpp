#include <iostream>
#include "Nodo.cpp"
#include "ListaSimple.cpp"
#include "validacion.h"

int main() {
    int opcion, dato;
    ListaSimple lista;

    do {
        system("cls");
        printf("\n1. Operaciones por la cabeza");
        printf("\n2. Operaciones por la cola");
        printf("\n3. Salir");

        opcion = ingresar_enteros("\nIngrese una opcion del menu");

        switch (opcion) {
            case 1:
                do {
                    system("cls");
                    printf("\n1. Insertar elemento por la cabeza");
                    printf("\n2. Imprimir lista por la cabeza");
                    printf("\n3. Eliminar elemento por la cabeza");
                    printf("\n0. Volver al menu principal");

                    opcion = ingresar_enteros("\nIngrese una opcion del submenu");

                    switch (opcion) {
                        case 1:
                            dato = ingresar_enteros("\nIngresar un entero como dato del nodo a insertar");
                            lista.insertar_cabeza(dato);
                            break;
                        case 2:
                            lista.imprimir_cabeza();
                            system("pause");
                            break;
                        case 3:
                            lista.eliminar_cabeza();
                            break;
                    }
                } while (opcion != 0);
                break;

            case 2:
                do {
                    system("cls");
                    printf("\n1. Insertar elemento por la cola");
                    printf("\n2. Imprimir lista por la cola");
                    printf("\n3. Eliminar elemento por la cola");
                    printf("\n0. Volver al menu principal");

                    opcion = ingresar_enteros("\nIngrese una opcion del submenu");

                    switch (opcion) {
                        case 1:
                            dato = ingresar_enteros("\nIngresar un entero como dato del nodo a insertar");
                            lista.insertar_cola(dato);
                            break;
                        case 2:
                            lista.imprimir_cola();
                            system("pause");
                            break;
                        case 3:
                            lista.eliminar_cola();
                            break;
                    }
                } while (opcion != 0);
                break;
        }
    } while (opcion != 3);

    system("pause");
    return 0;
}
