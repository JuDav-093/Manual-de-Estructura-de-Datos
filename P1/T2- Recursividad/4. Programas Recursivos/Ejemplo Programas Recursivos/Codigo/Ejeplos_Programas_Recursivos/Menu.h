#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "validaciones.h"

void mover_cursor(int x, int y){
    HANDLE manejo_consola = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(manejo_consola, pos);
}

void visibilidad_cursor(bool visible) {
    HANDLE manejo_consola = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 1;
    info.bVisible = visible;
    SetConsoleCursorInfo(manejo_consola, &info);
}

int desplegar_menu(const char** opciones, int nopciones){
    const short int ANCHO_BOTON = 35;
    visibilidad_cursor(false);
    char tecla;
    HANDLE manejo_consola = GetStdHandle(STD_OUTPUT_HANDLE);
    short int cursor_x = 0, cursor_y = 1, color_act = 0, opcion = 1;
    int colores[2] = {15, 15*8+8+14};

    auto imprimir_opciones = [&](){
        auto imprimir_boton = [&ANCHO_BOTON](const char* opcion){
            short int caracteres_en_opcion = 0;
            while (opcion[caracteres_en_opcion] != '\0') {
                caracteres_en_opcion++;
            }
            int espacios_faltantes = ANCHO_BOTON - caracteres_en_opcion;

            for(short int i = 0; i<ANCHO_BOTON; i++){
                printf("%c",' ');
            }
            printf("\n");

            for(short int i = 0; i<espacios_faltantes/2; i++){
                printf("%c",' ');
            }
            printf("%s", opcion);
            if(espacios_faltantes%2 == 0){
                for(short int i = 0; i<espacios_faltantes/2; i++){
                    printf("%c",' ');
                }
            }else{
                for(short int i = 0; i<(espacios_faltantes/2)+1; i++){
                    printf("%c",' ');
                }
            }

            printf("\n");
            for(short int i = 0; i<ANCHO_BOTON; i++){
                printf("%c",' ');
            }
        };

        for (int i = 0; i<nopciones; i++){
            color_act = 0;

            if((i*3)+1 == cursor_y)color_act = 1;

            mover_cursor(cursor_x, (i*3));
            SetConsoleTextAttribute(manejo_consola, colores[color_act]);
            imprimir_boton(opciones[i]);
        }
        color_act = 0;
        SetConsoleTextAttribute(manejo_consola, colores[color_act]);
    };

    imprimir_opciones();

    while((tecla = getch()) != 13){

        //mover pos cursor arriba
        if(tecla == 72 && opcion>1)cursor_y = cursor_y-3, imprimir_opciones();
        //mover pos cursor abajo
        else if(tecla == 80 && opcion<nopciones)cursor_y = cursor_y + 3, imprimir_opciones();

        mover_cursor(cursor_x, cursor_y);
        opcion = ((cursor_y-1)/3)+1;
    }

    return opcion;
}
void fibonacci(int n, double a = 0, double b = 1) {
    if (n > 0) {
        std::cout << a << " - ";
        fibonacci(n - 1, b, a + b);
    }
    else{
        std::cout << " \b\b\b\b  ";
        std::cout << "\n";
    }
}
void hanoi(int n, char origen, char auxiliar, char destino);
int factorial(int n);

void desplegar_menu_principal(){
    const int NUM_OPCIONES = 4;
    const char* OPCIONES[NUM_OPCIONES] = {"Calculo Factorial", "Torres de Hanoi", "Secuencia de Fibonacci", "Salir" };

    int opcion;
    do{
        system("cls");
        opcion = desplegar_menu(OPCIONES, NUM_OPCIONES);
        if(opcion == 1) {
            system("cls");
            int n;
            std::cout << "Ingrese el termino a calcular el factorial\n";
            visibilidad_cursor(true);
            n = ingresarEntero();
            std::cout << "El factorial de " << n << " es: " << factorial(n) << "\n" << std::endl;
            system("pause");
            visibilidad_cursor(false);
        }

        else if(opcion == 2){
            system("cls");
            int num_discos;
            std::cout << "Ingrese el numero de discos\n";
            visibilidad_cursor(true);
            num_discos = ingresarEntero();
            hanoi(num_discos, 'A', 'B', 'C');
            system("pause");
            visibilidad_cursor(false);
        }

        else if(opcion == 3){
            system("cls");
            int termino;
            std::cout << "Ingrese el termino para imprimir la secuencia de Fibonacci: \n";
            visibilidad_cursor(true);
            termino = ingresarEntero();
            std::cout << "Secuencia de Fibonacci hasta el termino " << termino << ": ";
            fibonacci(termino);
            system("pause");
            visibilidad_cursor(false);
        }
        else if(opcion == 4);

        visibilidad_cursor(false);
    }while(opcion != NUM_OPCIONES);

    mover_cursor(0,(opcion*3)+1);
}



void hanoi(int n, char origen, char auxiliar, char destino) {
    if (n == 1) {
        std::cout << "Mover disco 1 desde " << origen << " hacia " << destino << std::endl;
        return;
    }
    hanoi(n - 1, origen, destino, auxiliar);
    std::cout << "Mover disco " << n << " desde " << origen << " hacia " << destino << std::endl;
    hanoi(n - 1, auxiliar, origen, destino);
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

#endif // MENU_H_INCLUDED
