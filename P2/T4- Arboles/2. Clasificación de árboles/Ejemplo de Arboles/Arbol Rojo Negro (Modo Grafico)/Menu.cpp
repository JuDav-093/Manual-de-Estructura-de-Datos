#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <graphics.h>
#include <conio.h>
#include <locale.h>
#include <codecvt>
#include "validaciones.cpp"
#include <windows.h>
#include "Menu.h"
#include "RedBlackTree.cpp"

using namespace std;


void Menu::dibujar_arbol(ArbolRojoNegro& arbol, int x, int y, int radio_nodo) {
    auto dibujar_nodo = [&](NodoArbol* nodo) {
        int nodo_x = x + arbol.obtener_columna(nodo) * 2 * radio_nodo;
        int nodo_y = y + arbol.obtener_fila(nodo) * 2 * radio_nodo;

        if (nodo->izquierda() != arbol.nodo_nulo) {
            int izquierda_nodo_x = x + arbol.obtener_columna(nodo->izquierda()) * 2 * radio_nodo;
            int izquierda_nodo_y = y + arbol.obtener_fila(nodo->izquierda()) * 2 * radio_nodo;
            setcolor(BLACK);
            line(nodo_x, nodo_y, izquierda_nodo_x, izquierda_nodo_y);
        }

        if (nodo->derecha() != arbol.nodo_nulo) {
            int derecha_nodo_x = x + arbol.obtener_columna(nodo->derecha()) * 2 * radio_nodo;
            int derecha_nodo_y = y + arbol.obtener_fila(nodo->derecha()) * 2 * radio_nodo;
            setcolor(BLACK);
            line(nodo_x, nodo_y, derecha_nodo_x, derecha_nodo_y);
        }

        std::string texto_nodo = std::to_string(nodo->valor());
        int ancho_texto = textwidth((char*)texto_nodo.c_str());
        int texto_x = nodo_x - ancho_texto / 2;
        int texto_y = (nodo_y - radio_nodo / 2) + 2;

        setcolor(nodo->color() == ColorNodoArbol::Rojo ? RED : LIGHTGRAY);
        setfillstyle(SOLID_FILL, nodo->color() == ColorNodoArbol::Rojo ? RED : DARKGRAY);
        fillellipse(nodo_x, nodo_y, radio_nodo, radio_nodo);
        setbkcolor(nodo->color() == ColorNodoArbol::Rojo ? RED : DARKGRAY);
        setcolor(nodo->color() == ColorNodoArbol::Rojo ? WHITE : BLACK);
        outtextxy(
            texto_x,
            texto_y,
            (char*)std::to_string(nodo->valor()).c_str());
    };

    arbol.recorrer(dibujar_nodo, DireccionRecorrido::PreOrden);
}

void Menu::setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor | (bgColor << 4));

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

   COORD bufferSize = {
        static_cast<SHORT>(csbi.srWindow.Right - csbi.srWindow.Left + 1),
        static_cast<SHORT>(csbi.srWindow.Bottom - csbi.srWindow.Top + 1)
    };


    SetConsoleScreenBufferSize(hConsole, bufferSize);
}

void Menu::menuBase(){
	Validaciones validador;
    int ancho_pantalla = GetSystemMetrics(SM_CXSCREEN);
    int alto_pantalla = GetSystemMetrics(SM_CYSCREEN);

    // Crear la ventana de consola de compilación
    HWND hwndConsolaCompilacion = GetConsoleWindow();
    SetWindowPos(hwndConsolaCompilacion, HWND_TOP, 0, 0, ancho_pantalla / 2, alto_pantalla, SWP_SHOWWINDOW);

    ArbolRojoNegro arbol;
    int opcion = 1;
    int totalOpciones = 4;

    // Crear la ventana gráfica
    initwindow(1100, 700, "Arbol Rojo Negro", ancho_pantalla / 2, 0);
    setbkcolor(WHITE);
    cleardevice();
    dibujar_arbol(arbol, 10, 50, 25);
    
    do {
        system("cls");
        setColor(10,0); 
        cout << "           -- Arbol Rojo Negro --\n" << endl;
        for (int i = 1; i <= totalOpciones; i++) {
            if (i == opcion) {
                setColor(1,0);  
                cout << "   >> ";
            } else {
                setColor(10,0);   
                cout << "      ";
            }
            switch (i) {
                case 1:
                    cout << "1: Insertar Elemento" << endl;
                    break;
                case 2:
                    cout << "2: Eliminar Elemento" << endl;
                    break;
                case 3:
                    cout << "3: Buscar Elemento" << endl;
                    break;
                case 4:
                    cout << "4: Salir" << endl;
                    break;
            }
        }

        int tecla = _getch();
        if (tecla == 224) {
            tecla = _getch();
            switch (tecla) {
                case 72:
                    opcion = (opcion > 1) ? opcion - 1 : totalOpciones;
                    break;
                case 80:
                    opcion = (opcion < totalOpciones) ? opcion + 1 : 1;
                    break;
            }
        } else if (tecla == 13) {
            if (opcion == 4) {
                cout << "\nSaliendo del programa." << endl;
                break;
            } else {	
                switch (opcion) {
						case 1:
		            {
		            	system("cls");
		            	cout << "Ingrese un valor a insertar: ";
		            	int valor = validador.validarNumero();
		                arbol.insertar(valor);
		                cout << endl;
		            }
		            break;
		            case 2:
		            {
		            	system("cls");
		                cout << "Ingrese un valor a eliminar: ";
		            	int valor = validador.validarNumero();
		                arbol.eliminar(valor);
		                cout << endl;
		            }
		            break;
		            case 3:
		            {
		            	system("cls");
		                cout << "Ingrese un valor a buscar: ";
		            	int valor = validador.validarNumero();
		                arbol.buscar(valor);
		                cout << endl;
		            }
		            break;
		            case 4:
		            {
		                std::exit(0);
		            }
		            break;
	        	}
	        	system("pause");
	        }
        }
        if (opcion != 4) {
            setbkcolor(WHITE);
            cleardevice();
            dibujar_arbol(arbol, 10, 50, 25);
        }
    } while (true);
}