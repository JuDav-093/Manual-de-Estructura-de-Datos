#include <iostream>
#include "windows.h"
#include "validaciones.h"
#include "math.h"

int calcular_potencia(int, int);
int invertir_numero(int, int);

int calcular_potencia(int base, int power){
    if(power != 0){
        return base*calcular_potencia(base,power-1);
    }
    else{
        return 1;
    }
}

int invertir_numero(int numero, int resultado){
    if(numero > 0){
        resultado = resultado*10 + numero%10;
        invertir_numero(numero/10, resultado);
    }
    else{
        return resultado;
    }
}

void mostrar_menu_principal(int opcion){
    system("cls");
    std::cout << "\n--------------RECURSIVIDAD-----------------\n";
    std::cout << "\nSeleccione una opcion:\n\n";
    std::cout << (opcion == 1 ? "> " : "  ") << "Calcule la potencia de un numero entero positivo\n";
    std::cout << (opcion == 2 ? "> " : "  ") << "Invertir un numero entero positivo\n";
    std::cout << (opcion == 3 ? "> " : "  ") << "Salir\n";
}

int main()
{
    int numero1, numero2;
    int opcion = 1;
    char tecla;

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

    do{
        mostrar_menu_principal(opcion);
        tecla = _getch();

        switch(tecla){
            case 72: // Flecha arriba
                if (opcion > 1) opcion--;
                break;
            case 80: // Flecha abajo
                if (opcion < 3) opcion++;
                break;
            case 13: // Enter
                if(opcion == 1){
                    cursorInfo.bVisible = true;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                    numero1 = ingresar_enteros("Ingrese la base:");
                    printf("\n");

                    numero2 = ingresar_enteros("Ingrese el exponente:");
                    printf("\n");

                    printf("%d ^ %d = %d\n", numero1, numero2, calcular_potencia(numero1, numero2));

					system("pause");
					cursorInfo.bVisible = false;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
                }
                else if(opcion == 2){
                    cursorInfo.bVisible = true;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                    numero1 = ingresar_enteros("Ingrese el numero el cual quiere invertir:");
                    printf("\n");

                    numero2 = 0;

                    printf("Numero Invertido = %d\n", invertir_numero(numero1, numero2));

					system("pause");
					cursorInfo.bVisible = false;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
                }
                else if(opcion == 3){
                    system("cls");
   					std::cout << "Saliendo del programa." << std::endl;
   					exit(0);
                }
                break;
            default:
                break;
        }

    }while(true);

    system("pause");
	cursorInfo.bVisible = true;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
