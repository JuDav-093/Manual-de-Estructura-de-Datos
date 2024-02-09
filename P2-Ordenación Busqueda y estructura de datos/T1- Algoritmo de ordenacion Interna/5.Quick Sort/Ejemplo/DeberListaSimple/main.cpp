#include <iostream>
#include "Nodo.h"
#include "ListaSimple.h"
#include "validaciones.h"
#include "ListaDobleEnlazada.h"

int main()
{
    int opcion, dato;
    ListaSimple lista;
    ListaDobleEnlazada listaDoble;
    Nodo cabeza;

    do{
        system("cls");
        printf("\n1. Insertar por la cabeza");
        printf("\n2. Insertar por la cola");
        printf("\n3. Imprimir por la cabeza");
        printf("\n4. Imprimir por la cola");
        printf("\n5. Buscar");
        printf("\n6. Eliminar por la cabeza");
        printf("\n7. Imprimir por la cola");
        printf("\n8. Suma Primos");
        printf("\n9. Suma de cada digito en posiciones pares");
        printf("\n13. Ordenar lista");
        printf("\n LISTA DOBLEMENTE ENLAZADA");
        printf("\n10. Insertar por la cabeza");
        printf("\n11. Insertar entre cabezaz y cola");
        printf("\n12. Imprimir lista");
        printf("\n0. Salir");
        opcion = ingresar_enteros("\nIngrese una opcion del menu");
        switch(opcion){
            case 1:
                dato = ingresar_enteros("\nIngresar un entero como dato del nodo a insertar");
                printf("\n");
                lista.insertar_cabeza(dato);
                system("pause");
                break;
            case 2:
                dato = ingresar_enteros("\nIngresar un entero como dato del nodo a insertar");
                printf("\n");
                lista.insertar_cola(dato);
                system("pause");
                break;    
            case 3:
                printf("\n");
                lista.imprimir_desde_la_cabeza();
                system("pause");
                break;
            case 4:
                printf("\n");
                lista.imprimir_desde_la_cola();
                system("pause");
                break;
            case 5:
                dato = ingresar_enteros("\nIngresar el valor a buscar");
                printf("\n");
                lista.buscar(dato);
                system("pause");
                break;
            case 6:
                printf("\n");
                lista.eliminar_por_la_cabeza();
                system("pause");
                break;
            case 7:
                printf("\n");
                lista.eliminar_por_la_cola();
                system("pause");
                break;
            case 8:
                printf("\n");
                lista.suma_elementos_primos();
                system("pause");
                break;
            case 9:
                printf("\n");
                lista.suma_de_digitos_de_un_numero_en_posiciones_pares();
                system("pause");
                break;
            case 10:
                dato = ingresar_enteros("\nIngresar un entero como dato del nodo a insertar");
                printf("\n");
                listaDoble.insertarCabeza(dato);
                system("pause");
                break;
            case 11:
                dato = ingresar_enteros("\nIngresar un entero como dato del nodo a insertar");
                printf("\n");
                listaDoble.insertarEntreCabezaYCola(dato);
                system("pause");
                break;
            case 12:
                printf("\n");
                listaDoble.imprimirLista();
                system("pause");
                break;
            case 13:
                printf("\n");
                lista.ordenarLista();
                system("pause");
                break;
        }
    }while(opcion != 0);

    system("pause");
    return 0;
}
