#include <iostream>
#include "Nodo.h"
#include "ListaDoble.h"
#include "windows.h"
#include "validaciones.h"

void mostrar_menu_principal(int opcion){
    system("cls");
    std::cout << "\n--------------LISTADO ESTUDIANTIL-----------------\n";
    std::cout << "\nSeleccione una opcion:\n\n";
    std::cout << (opcion == 1 ? "> " : "  ") << "Anadir estudiantes\n";
    std::cout << (opcion == 2 ? "> " : "  ") << "Eliminar estudiantes\n";
    std::cout << (opcion == 3 ? "> " : "  ") << "Buscar estudiantes\n";
    std::cout << (opcion == 4 ? "> " : "  ") << "Mostrar estudiantes\n";
    std::cout << (opcion == 5 ? "> " : "  ") << "Salir\n";
}

int main()
{
    Estudiante* nuevo_estudiante;
    ListaDoble lista_estudiantes;
    int parametro;
    bool hallado;
    std::string dato;
    std::string aparametro;
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
                if (opcion < 5) opcion++;
                break;
            case 13: // Enter
                if(opcion == 1){
                    cursorInfo.bVisible = true;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                    nuevo_estudiante = new Estudiante();

                    dato = ingresar_nombre("Ingrese el primer nombre del estudiante:");
                    nuevo_estudiante->set_primer_nombre(dato);

                    printf("\n");
                    dato = ingresar_nombre("Ingrese el segundo nombre del estudiante (si no tiene, escriba 'ninguno'):");
                    nuevo_estudiante->set_segundo_nombre(dato);

                    printf("\n");
                    dato = ingresar_nombre("Ingrese el primer apellido del estudiante:");
                    nuevo_estudiante->set_primer_apellido(dato);

                    printf("\n");
                    dato = ingresar_nombre("Ingrese el segundo apellido del estudiante (si no tiene, escriba 'ninguno'):");
                    nuevo_estudiante->set_segundo_apellido(dato);

                    printf("\n");
                    nuevo_estudiante->set_id(generarEtiqueta());

                    lista_estudiantes.insertar_cola(nuevo_estudiante);

                    printf("\n");
					system("pause");
					cursorInfo.bVisible = false;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
                }
                else if(opcion == 2){
                    cursorInfo.bVisible = true;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                    lista_estudiantes.imprimir();
                    printf("Ingrese el ID del estudiante:\n");
                    std::cin >> dato;
                    lista_estudiantes.eliminar(dato);

                    printf("\n");
					system("pause");
					cursorInfo.bVisible = false;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
                }
                else if(opcion == 3){
                    cursorInfo.bVisible = true;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                    printf("Ingrese el ID del estudiante:\n");
                    std::cin >> dato;

                    nuevo_estudiante = lista_estudiantes.buscar(dato);

                    if(nuevo_estudiante != nullptr){
                            printf("Se encontro el estudiante.\n");
                            printf("Con la informacion: %s %s %s %s\n", nuevo_estudiante->get_primer_nombre().c_str(),
                                                                        nuevo_estudiante->get_segundo_nombre().c_str(),
                                                                        nuevo_estudiante->get_primer_apellido().c_str(),
                                                                        nuevo_estudiante->get_segundo_apellido().c_str());

                    }else{
                        printf("No se hallo dicho estudiante.\n");
                    }

					system("pause");
					cursorInfo.bVisible = false;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
                }
                else if(opcion == 4){
                    lista_estudiantes.imprimir();
                    system("pause");
                }
                else if(opcion == 5){
                    system("cls");
   					std::cout << "Saliendo del programa." << std::endl;
   					exit(0);
                }
                break;
            default:
                break;
        }

    }while(true);
    printf("\n");
    system("pause");
	cursorInfo.bVisible = true;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

