#include <iostream>
#include "Grafo.h"
#include "Vertice.h"
#include "Arista.h"
#include "menus.h"
#include "validaciones.h"
#include "ListaDoble.cpp"

int main()
{
    //Parametros del Menu
    const int NUM_OPCIONES = 4;
    const char* opciones[NUM_OPCIONES] = {"Ingresar vertices","Insertar aristas","Ruta mas corta Dijkstra","Salir"};
    const int NUM_OPCIONES_SI_NO = 2;
    const char* opciones_si_no[NUM_OPCIONES_SI_NO] = {"Reintentar","Volver al menu principal"};
    int opcion;

    //Variables a usar en la creacion del grafo
    Vertice* vertice;
    Vertice* vertice_sig;
    Arista* arista;
    Grafo* grafo;
    ListaDoble<char> ids_vert;
    char id_vert;
    int numero_vertices;
    double peso_arista;
    bool existe_id;
    bool existe_arista;

    do{
        system("cls");
        opcion = desplegar_menu(opciones, NUM_OPCIONES);
        system("cls");

        if(opcion == 1)
        {
            do{
                system("cls");
                numero_vertices = ingresar_enteros("Ingrese el numero de vertices del grafo");

                if(numero_vertices<=0){
                    printf("\nEl numero de vertices debe ser mayor a 0");
                    system("pause");
                }

            }
            while(numero_vertices<=0);

            grafo = new Grafo();

            for(int i = 0; i<numero_vertices; i++){
                id_vert = 'A'+i;
                ids_vert.insertar_cola(id_vert);
                vertice = new Vertice(id_vert);
                grafo->get_vertices()->insertar_cola(vertice);
            }
        }
        else if(opcion == 2)
        {
            if(ids_vert.tam()<2){
                printf("No hay suficientes vertices para insertar una arista (MIN 2)");
                system("pause");
            }
            else{
                do{
                    system("cls");
                    printf("id's ingresados:\n");
                    ids_vert.imprimir();
                    printf("\nAristas insertadas:\n");
                    grafo->imprimir_aristas();
                    id_vert = ingresar_caracter("\nIngrese el id del vertice de donde sale la arista");
                    existe_id = ids_vert.buscar(id_vert);

                    if(!existe_id){
                        printf("\nIngrese un id valido\n");
                        system("pause");
                        system("cls");
                        if(desplegar_menu(opciones_si_no, NUM_OPCIONES_SI_NO) == NUM_OPCIONES_SI_NO){
                            break;
                        }
                        else{
                            system("cls");
                        }

                    }
                    else{

                        vertice = encontrar_vertice(grafo->get_vertices(), id_vert);

                        id_vert = ingresar_caracter("\nIngrese el id del vertice a donde llega la arista");
                        existe_id = ids_vert.buscar(id_vert);

                        if(!existe_id){
                            printf("\nIngrese un id valido\n");
                            system("pause");
                            system("cls");
                            if(desplegar_menu(opciones_si_no, NUM_OPCIONES_SI_NO) == NUM_OPCIONES_SI_NO){
                                break;
                            }
                            else{
                                system("cls");
                            }
                        }
                        else if (id_vert == vertice->get_id()){
                            printf("\nIngrese un id distinto del anterior\n");
                            system("pause");
                            system("cls");
                            if(desplegar_menu(opciones_si_no, NUM_OPCIONES_SI_NO) == NUM_OPCIONES_SI_NO){
                                break;
                            }
                            else{
                                system("cls");
                            }
                        }
                        else{
                            vertice_sig = encontrar_vertice(grafo->get_vertices(), id_vert);

                            existe_arista = grafo->existe_arista(vertice, vertice_sig);
                            if(existe_arista){
                                printf("\nLa arista entre estos dos vertices ya existe\n");
                                system("pause");
                                system("cls");
                                if(desplegar_menu(opciones_si_no, NUM_OPCIONES_SI_NO) == NUM_OPCIONES_SI_NO){
                                    break;
                                }
                                else{
                                    system("cls");
                                }
                            }
                        }
                    }
                }
                while(!existe_id || id_vert == vertice->get_id() || existe_arista);

                if(!(!existe_id || id_vert == vertice->get_id() || existe_arista)){
                    do{
                        peso_arista = ingresar_reales("\nIngrese el peso de la arista (distancia entre los dos vertices)");
                        if(peso_arista<=0){
                            printf("\nEl peso debe ser mayor a 0\n");
                            system("pause");
                        }
                    }
                    while(peso_arista<=0);

                    arista = new Arista(vertice, vertice_sig, peso_arista);

                    grafo->get_aristas()->insertar_cola(arista);
                }
            }

        }
        else if(opcion == 3)
        {
            do{
                system("cls");
                printf("id's ingresados:\n");
                ids_vert.imprimir();
                printf("Aristas insertadas:\n");
                grafo->imprimir_aristas();
                id_vert = ingresar_caracter("Ingrese el id del vertice donde quiere iniciar la ruta");
                existe_id = ids_vert.buscar(id_vert);

                if(!existe_id){
                    printf("\nIngrese un id valido\n");
                    system("pause");
                }
                else
                {

                    vertice = encontrar_vertice(grafo->get_vertices(), id_vert);

                    id_vert = ingresar_caracter("\nIngrese el id del vertice donde terminar la ruta");
                    existe_id = ids_vert.buscar(id_vert);

                    if(!existe_id){
                        printf("\nIngrese un id valido\n");
                        system("pause");
                    }
                    else if (id_vert == vertice->get_id()){
                        printf("\nIngrese un id distinto del anterior\n");
                        system("pause");
                    }
                    else{
                        vertice_sig = encontrar_vertice(grafo->get_vertices(), id_vert);
                    }
                }

            }
            while(!existe_id || id_vert == vertice->get_id());

            printf("\nLa distancia de la ruta mas corta es: %.3f", grafo->dijkstra(vertice, vertice_sig));

            system("pause");
        }

    }while(opcion!=NUM_OPCIONES);

    return 0;
}
