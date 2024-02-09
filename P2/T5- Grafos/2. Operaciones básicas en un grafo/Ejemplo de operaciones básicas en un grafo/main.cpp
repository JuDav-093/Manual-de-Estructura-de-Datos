#include <iostream>
#include "GrafoNoDirigido.h"
#include "validaciones.h"
#include "windows.h"
#include "conio.h"
#include <algorithm>

void imprimirMenu(int opcionSeleccionada) {
    system("cls"); // Limpiar la consola
    std::cout << "*** Menu ***" << std::endl;
    std::cout << (opcionSeleccionada == 1 ? "> " : "  ") << "1. Agregar Nodo" << std::endl;
    std::cout << (opcionSeleccionada == 2 ? "> " : "  ") << "2. Eliminar Nodo" << std::endl;
    std::cout << (opcionSeleccionada == 3 ? "> " : "  ") << "3. Agregar arista" << std::endl;
    std::cout << (opcionSeleccionada == 4 ? "> " : "  ") << "4. Eliminar Arista" << std::endl;
    std::cout << (opcionSeleccionada == 5 ? "> " : "  ") << "5. Mostrar Grafo" << std::endl;
    std::cout << (opcionSeleccionada == 6 ? "> " : "  ") << "6. Salir" << std::endl;

}
int main(){

    GrafoNoDirigido grafo(0);
    int opcion;
    int nodo, nodoA, nodoB;
    char key;

HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);

    // Ocultar el cursor
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

    do {
        imprimirMenu(opcion);
        key = _getch();

        switch (key) {
            case 72: // Flecha arriba
                if (opcion > 1) opcion--;
                break;
            case 80: // Flecha abajo
                if (opcion < 6) opcion++;
                break;
            case 13: // Enter
                if (opcion == 1) {

                    cursorInfo.bVisible = true;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
                    grafo.agregarNodo();

                    std::cout << "\nNodo anadido\n" << std::endl;

            		system("pause");

            		cursorInfo.bVisible = false;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                } else if (opcion == 2) {

                    cursorInfo.bVisible = true;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                    nodo=ingresar_enteros("\nIngrese el nodo a eliminar: \n");
                    grafo.eliminarNodo(nodo);
            		system("pause");

            		cursorInfo.bVisible = false;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                } else if(opcion==3){
                    nodoA=ingresar_reales("\nIngrese el numero del primer nodo de la arista\n");
                    nodoB=ingresar_reales("\nIngrese el numero del segundo nodo de la arista\n");
                    grafo.agregarArista(nodoA, nodoB);
            		system("pause");

                } else if(opcion==4){
                    nodoA=ingresar_reales("\nIngrese el numero del primer nodo de la arista\n");
                    nodoB=ingresar_reales("\nIngrese el numero del segundo nodo de la arista\n");
                    grafo.eliminarArista(nodoA, nodoB);
            		system("pause");

                }   else if(opcion==5){
                    printf("\n");
                    grafo.imprimirGrafo();
                    printf("\n");
            		system("pause");

                }
                else if(opcion==6){
					system("cls");
   					std::cout << "Saliendo del programa." << std::endl;
   					exit(0);
				}
                break;
            default:
                break;
        }
    } while (true);

	system("pause");
	return 0;


}

