#include "graphics.h"
#include "Menu.h"
#include "ArbolBinario.h"
#include "GraficarArbol.h"

#pragma comment(lib,"graphics.lib")

using namespace std;

int main() {
    int ancho_pantalla = GetSystemMetrics(SM_CXSCREEN);
    int alto_pantalla = GetSystemMetrics(SM_CYSCREEN);
    int gd = DETECT, gm;
    
    ArbolBinario arbol;
    Nodo* raiz = NULL;
    bool continuar = true;
    bool defRaiz = false;

    do {
        system("cls");
        switch (mostrarMenu()) {
        case 1:
            system("cls");
            if (defRaiz) {
                arbol.insertarNodo(raiz, leer_entero("\n\tIngrese un valor a insertar: "));
            }
            else {
                raiz = arbol.insertarNodo(raiz, leer_entero("\n\tIngrese un valor a insertar: "));
                defRaiz = true;
            }
            break;
        case 2:
            system("cls");
            arbol.eliminarNodo(raiz, leer_entero("\n\tIngrese un valor a eliminar: "));
            break;
        case 3:
            system("cls");
            if (arbol.buscarNodo(raiz, leer_entero("\n\tIngrese un valor a buscar: ")) == NULL) {
                cout << "\n\tEl valor NO se encuentra en el arbol\n\n\t";
            }
            else {
                cout << "\n\tEl valor se encuentra en el arbol\n\n\t";
            }
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "\n\tArbol en inorde:\n\n\t";
            arbol.inorden(raiz);
            cout << "\n\n\t";
            system("pause");
            break;
        case 5:
            system("cls");
            initgraph(&gd, &gm, (char*)"");
            initwindow(ancho_pantalla, alto_pantalla);
            graficarArbol(raiz, getmaxx() / 2, 50, getmaxx() / 4, 50);
            system("pause");
            closegraph();
            break;
        case 6:
            continuar = false;
            break;
        default:
            break;
        }
    } while (continuar);    
}