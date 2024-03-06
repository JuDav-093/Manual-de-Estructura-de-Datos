#include <iostream>
#include <conio.h>
#include "windows.h"

#include "Menu.h"
#include "Tablero.h"
#include "validaciones.h"
#include "Problema_Reinas.h"

int main()
{
    int opcion = 1;
    char tecla;
    int contador = 0;

    int TAM;
    Tablero* ajedrez = nullptr;

    int* _x = nullptr;
    int* _y = nullptr;

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);

    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

    do {

        mostrar(opcion);
        tecla = _getch();

        switch (tecla) {

        case 72:
            if (opcion > 1) opcion--;
            break;
        case 80:
            if (opcion < 2) opcion++;
            break;
        case 13:
            if (opcion == 1) {
                cursorInfo.bVisible = true;
                SetConsoleCursorInfo(consoleHandle, &cursorInfo);
                    
                system("cls");

                do {
                    TAM = ingresar_enteros("Ingrese el Tamano: (4-9)");
                    printf("\n");
                    if (TAM < 4 || TAM > 9) {
                        printf("Ese tamano no es valido. Intente de nuevo.\n");
                    }
                    else {
                        break;
                    }

                } while (true);
                
                ajedrez = new Tablero(TAM);

                if(ajedrez->get_piezas_strings() != nullptr){

                    _y = (int*)malloc(TAM * sizeof(int));

                    if (_y != nullptr) {
                        for (int i = 0; i < TAM; i++) {
                            *(_y + i) = 10;
                        }
                        _x = (int*)malloc(TAM * sizeof(int));
                        if (_x != nullptr) {
                            for (int j = 0; j < TAM; j++) {
                                *(_x + j) = 20;
                            }
                            fun(*ajedrez, 0, _x, 0, _y, contador);
                        }
                    }
                }

                delete ajedrez;
                delete _x;
                delete _y;
                contador = 0;

                cursorInfo.bVisible = false;
                SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                system("pause");

            }
            else if (opcion == 2) {

                system("cls");
                std::cout << "Saliendo del programa." << std::endl;
                exit(0);
                    
            }
            break;
        default:
            break;

        }

    } while (true);


}
