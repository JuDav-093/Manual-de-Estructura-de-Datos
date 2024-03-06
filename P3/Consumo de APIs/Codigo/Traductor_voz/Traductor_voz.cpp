// Traductor_voz.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <clocale>
#include <speechapi_cxx.h>

#include "menus.h"
#include "validaciones.h"
#include "Voz.h"
#include "Nodo.h"
#include "ClienteHTTP.h"

int main() {

    setlocale(LC_ALL, "es_ES.UTF-8");
    const int NUM_OPCIONES = 2;
    const char* opciones[NUM_OPCIONES] = {"Traducir","Salir"};
    int opcion;

    const int NUM_SUBOPCIONES = 3;
    const char* subopciones[NUM_SUBOPCIONES] = {"Texto","Microfono","Salir"};
    int subopcion;

    std::string a_traducir, traduccion;

    do {
        system("cls");
        opcion = desplegar_menu(opciones,NUM_OPCIONES);
        system("cls");

        visibilidad_cursor(false);

        if (opcion == 1) {
            do {
                system("cls");
                subopcion = desplegar_menu(subopciones, NUM_SUBOPCIONES);
                system("cls");
                if (subopcion == 1) {
                    a_traducir = ingresar_alfabetico("Ingrese la palabra en español a traducir");
                    break;
                }
                else if (subopcion == 2) {
                    a_traducir = capturar_voz();
                    break;
                }
               
            }while (subopcion!=NUM_SUBOPCIONES);
            if (subopcion != 3) {
                if (!a_traducir.empty()) {

                    if (subopcion == 2)a_traducir.pop_back();

                    try {
                        traduccion = traducir(a_traducir, "ES", "EN");
                        std::cout << "\nTraduccion:\n" << traduccion << "\n";
                        generar_voz(traduccion);
                        buscar_imagen(formatear_http(traduccion));
                        system("pause");
                    }
                    catch (const std::exception& ex) {
                        std::cerr << "Error: " << ex.what() << std::endl;
                        system("pause");
                    }
                }
                else {
                    std::cout<<"\nNo hay texto para traducir\n";
                    system("pause");
                }
            }
        }
        
    } while (opcion != NUM_OPCIONES);
    
    return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
