#include <iostream>
#include "Stack.cpp"
#include "validacionesNEW.h"
#include "stacks_movements.h"
#include "stack_operations.h"
#include <string>
#include <algorithm>
#include <cmath>
#include "windows.h"

void mostrarMenu(int opcion) {
    system("cls");
    std::cout << "\n--------------POLACA INVERSA-----------------\n";
    std::cout << "\nSeleccione una opcion:\n\n";
    std::cout << (opcion == 1 ? "> " : "  ") << "Inserte una expresion matematica\n";
    std::cout << (opcion == 2 ? "> " : "  ") << "Transformar a notacion prefija y posfija\n";
    std::cout << (opcion == 3 ? "> " : "  ") << "Salir\n";
}


int main()
{
    Stack<char> my_stack;
    char tecla;
    char key;
    Stack<std::string> aux_string_stack;
    Stack<std::string> string_infix_stack;
    Stack<std::string> string_polish_stack;
    Stack<std::string> string_reverse_polish_stack;
    int opcion = 1;

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

    do {
        mostrarMenu(opcion);
        key = _getch();

        switch (key) {
            case 72: // Flecha arriba
                if (opcion > 1) opcion--;
                break;
            case 80: // Flecha abajo
                if (opcion < 3) opcion++;
                break;
            case 13: // Enter
                if (opcion == 1) {
                    cursorInfo.bVisible = true;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                    my_stack.remove_all();
                    string_infix_stack.remove_all();
                    aux_string_stack.remove_all();
                    ingresar_expresion(&my_stack, tecla);
                    my_stack = upgrade_char_stack(my_stack);
                    string_infix_stack = convert_to_infix_string_stack(my_stack);
                    aux_string_stack = convert_to_infix_string_stack(my_stack);

                    printf("\nExpresion Guardada\n");
                    system("pause");
                    cursorInfo.bVisible = false;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
                } else if (opcion == 2) {

                    string_polish_stack.remove_all();
                    string_reverse_polish_stack.remove_all();
                    printf("\n");
                    printf("INFIJA:    ");
                    string_infix_stack.print_lineal_stack();
                    invert_stack(my_stack);
                    printf("PREFIJA:   ");
                    getPolishNotation(string_infix_stack, string_polish_stack);
                    invert_stack(my_stack);
                    printf("POSFIJA:   ");
                    getReversePolishNotation(string_infix_stack, string_reverse_polish_stack);
                    invert_stack(string_infix_stack);

                    system("pause");

                } else if (opcion == 3) {
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
