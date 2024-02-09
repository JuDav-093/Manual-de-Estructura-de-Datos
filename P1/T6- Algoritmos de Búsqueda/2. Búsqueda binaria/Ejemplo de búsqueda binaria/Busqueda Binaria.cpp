
 #include <iostream>
 #include "validaciones.h"
#include "windows.h"
#include "conio.h"
#include <algorithm>

 int busquedaBin(int a[], int n, int clave)
 {
  int central, bajo, alto;
  int valorCentral;
  bajo = 0;
  alto = n - 1;
  while (bajo <= alto)
  {
    central = (bajo + alto)/2;          // índice de elemento central
    valorCentral = a[central];          // valor del índice central
    if (clave == valorCentral)
      return central;                   // encontrado, devuelve posición
    else if (clave < valorCentral)
      alto = central - 1;               // ir a sublista inferior
    else
      bajo = central + 1;               // ir a sublista superior
  }
  return -1;                            //elemento no encontrado
}

// Función para imprimir el menú
void imprimirMenu(int opcionSeleccionada) {
    system("cls"); // Limpiar la consola
    std::cout << "*** Menu ***" << std::endl;
    std::cout << (opcionSeleccionada == 1 ? "> " : "  ") << "1. Anadir elemento al arreglo" << std::endl;
    std::cout << (opcionSeleccionada == 2 ? "> " : "  ") << "2. Imprimir arreglo" << std::endl;
    std::cout << (opcionSeleccionada == 3 ? "> " : "  ") << "3. Buscar elemento en el arreglo" << std::endl;
    std::cout << (opcionSeleccionada == 4 ? "> " : "  ") << "4. Ordenar el arreglo" << std::endl;
    std::cout << (opcionSeleccionada == 5 ? "> " : "  ") << "5. Salir del programa" << std::endl;
}

int main() {
    int* arreglo = nullptr; // Inicializamos el puntero a nullptr
    int tamano = 0;
    int opcion = 1; // Opción seleccionada por defecto
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
                if (opcion < 5) opcion++;
                break;
            case 13: // Enter
                if (opcion == 1) {

                    cursorInfo.bVisible = true;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
                    // Añadir elemento al arreglo
                    int elemento;
                    printf("\n");
                    elemento=ingresar_enteros("Ingrese el elemento a anadir: ");
                    // Reasignamos memoria para un nuevo arreglo con un tamaño incrementado
                    int* nuevo_arreglo = new int[tamano + 1];
                    // Copiamos los elementos del arreglo original al nuevo arreglo
                    for (int i = 0; i < tamano; ++i) {
                        nuevo_arreglo[i] = arreglo[i];
                    }
                    // Añadimos el nuevo elemento al final del nuevo arreglo
                    nuevo_arreglo[tamano] = elemento;
                    // Incrementamos el tamaño del arreglo
                    tamano++;
                    // Liberamos la memoria del arreglo original
                    delete[] arreglo;
                    // Asignamos el puntero al nuevo arreglo
                    arreglo = nuevo_arreglo;
                    printf("\n");
                    std::cout << "Elemento anadido al arreglo." << std::endl;
                    printf("\n");

            		system("pause");

            		cursorInfo.bVisible = false;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                } else if (opcion == 2) {

                    cursorInfo.bVisible = true;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                    // Ordenar arreglo
                    std::cout << "Arreglo actual: ";
                    for (int i = 0; i < tamano; ++i) {
                        std::cout << arreglo[i] << " ";
                    }
                    std::cout << std::endl;
            		system("pause");

            		cursorInfo.bVisible = false;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                } else if(opcion==3){
                    printf("\n");
                    // Buscar elemento en el arreglo
                    int elemento;
                    elemento=ingresar_enteros("Ingrese el elemento a buscar: ");
                    int resultado = busquedaBin(arreglo, tamano, elemento);
                    if (resultado != -1) {
                            printf("\n");
                        std::cout << "El elemento " << elemento << " se encuentra en la posicion " << resultado+1 << std::endl;
                    printf("\n");
                    } else {
                        printf("\n");
                        std::cout << "El elemento " << elemento << " no se encuentra en el arreglo o el arreglo no esta ordenado" << std::endl;
                        printf("\n");
                    }

            		system("pause");

                } else if(opcion==4){
                    printf("\n");
                    std::sort(arreglo, arreglo + tamano);
                    std::cout << "Arreglo ordenado correctamente." << std::endl;
                    printf("\n");
            		system("pause");

                }
                else if(opcion==5){
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
