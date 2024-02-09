#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "validaciones.h"


void visibilidad_cursor(bool);
void mover_cursor(int x, int y);

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
    const short int ANCHO_BOTON = 60;
    visibilidad_cursor(false);
    char tecla;
    HANDLE manejo_consola = GetStdHandle(STD_OUTPUT_HANDLE);
    short int cursor_x = 0, cursor_y = 1, color_act = 0, opcion = 1;
    int colores[2] = {15, 191};

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

#endif // MENUS_H_INCLUDED
