#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#include <sys/time.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>
#include <string>
#include <limits>
#include <graphics.h>
#include <math.h>

using namespace std;

vector<int> sumandos_version1(const vector<int> &numeros, int suma) {
    for (auto a : numeros) {
        int diferencia = suma - a;
        for (auto b : numeros) {
            if ((b != a) && (b == diferencia))
                return {a, b};
        }
    }
    return {0, 0};
}
vector<int> sumandos_version2(const vector<int> &numeros, int suma) {
    set<int> conjunto;
    for (auto a : numeros) {
        int diferencia = suma - a;
        if (conjunto.find(diferencia) != conjunto.end())
            return {a, diferencia};
        else
            conjunto.insert(a);
    }
    return {0, 0};
}
void graficarCuadraticaO_n2() {
    initwindow(900, 900, "Plano Cartesiano", 200, 100);
    // Dibujar ejes x e y
    setcolor(WHITE);
    line(400, 400, 750, 400); // Eje x
    line(400, 400, 400, 50);  // Eje y
    // Etiquetas de los ejes
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 0);
    outtextxy(770, 400, "x");
    outtextxy(400, 30, "y");
    // Dibujar la línea que representa la complejidad O(n^2) en el primer cuadrante
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 0);
    int x2, y2;
    double c = 8;
    for (x2 = 0; x2 <= 100; x2++) {
        y2 = 400 - c * pow(2, x2 / 20.0);
        if (y2 >= 50) { // Asegurarse de que y esté en el primer cuadrante
            putpixel(x2 + 400, y2, RED); // Desplazar x2 para que esté en el primer cuadrante
        }
    }
    // Etiqueta de la complejidad
    setcolor(RED);
    outtextxy(750, 45, "O(n^2)");
}

void graficarLinealO_n() {
    initwindow(800, 800, "Plano Cartesiano", 200, 100);
    // Dibujar ejes x e y
    setcolor(WHITE);
   line(400, 400, 750, 400); // Eje x
    line(400, 400, 400, 50);  // Eje y
    // Etiquetas de los ejes
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 0);
    outtextxy(770, 400, "x");
    outtextxy(400, 30, "y");
    // Dibujar la línea que representa la complejidad O(n)
    setcolor(RED);
 line(400, 400, 750, 45);
    // Etiqueta de la complejidad
    outtextxy(750, 45, "O(n)");
}
int main() {
    struct timeval inicio, fin;
    int totalOpciones = 3;
    int opcion = 1;

    while (true) {
        system("cls"); // Limpiar la pantalla antes de mostrar las opciones
        cout << " \n\t COMPLEJIDAD ALGORITMICA? " << endl;
        for (int i = 1; i <= totalOpciones; i++) {
            if (i == opcion) {
                cout << "   ";
                if (i == 1) cout << ">> ";
            } else {
                cout << "      ";
            }
            switch (i) {
                case 1:
                    cout << "1:  Lineal O(n)" << endl;
                    break;
                case 2:
                    cout << "2: Cuadratica O(n^2)" << endl;
                    break;
                case 3:
                    cout << "3: Salir" << endl;
                    break;
            }
        }
        int tecla = _getch(); // Utilizamos getch() en lugar de _getch()
        if (tecla == 224) { // Tecla de flecha
            tecla = _getch(); // Obtenemos la segunda parte del código de la tecla de flecha
            switch (tecla) {
                case 72: // Flecha arriba
                    opcion = (opcion > 1) ? opcion - 1 : totalOpciones;
                    break;
                case 80: // Flecha abajo
                    opcion = (opcion < totalOpciones) ? opcion + 1 : 1; // Mover la opción hacia abajo, volver al inicio si está en la parte inferior
                    break;
            }
        } else if (tecla == 13) { // Tecla Enter
            if (opcion == 3) {
                system("cls");
                cout << "Saliendo del programa..." << endl;
                break;
            } else if (opcion == 1) {
                system("cls");
                gettimeofday(&inicio, NULL);
                ios_base::sync_with_stdio(false);
                vector<int> resultado = sumandos_version1({6, 1, 4, 2, 9, 7, 3, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}, 3);
                cout << "Los sumandos son: ";
                for (int num : resultado) {
                    cout << num << " ";
                }
                cout << endl;
                gettimeofday(&fin, NULL);
                double tiempo_ejecucion = (fin.tv_sec - inicio.tv_sec) * 1e6;
                tiempo_ejecucion = (tiempo_ejecucion + (fin.tv_usec - inicio.tv_usec)) * 1e-6;
                cout << "Tiempo de ejecucion de la version 1, complejidad O(n): " << fixed << tiempo_ejecucion << endl;
                graficarLinealO_n(); // Supongo que esta función la tienes definida en otro lugar
                system("pause");
            } else if (opcion == 2) {
                system("cls");
                gettimeofday(&inicio, NULL);
                vector<int> resultado = sumandos_version2({6, 1, 4, 2, 9, 7, 3, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}, 3);
                cout << "Los sumandos son: ";
                for (int num : resultado) {
                    cout << num << " ";
                }
                cout << endl;
                gettimeofday(&fin, NULL);
                double tiempo_ejecucion = (fin.tv_sec - inicio.tv_sec) * 1e6;
                tiempo_ejecucion = (tiempo_ejecucion + (fin.tv_usec - inicio.tv_usec)) * 1e-6;
                cout << "Tiempo de ejecucion de la version 2, complejidad O(n^2): " << fixed << tiempo_ejecucion << endl;
                graficarCuadraticaO_n2();
                system("pause");
            }
        }
    }
    cout << "Presione cualquier tecla para continuar...";
    _getch();
    return 0;
}


