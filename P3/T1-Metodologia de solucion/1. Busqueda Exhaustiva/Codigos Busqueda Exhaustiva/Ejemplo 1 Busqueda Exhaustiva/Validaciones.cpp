/*******************************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Nombres: Elkin Pabon, Alexis Chimba, Cesar Loor
 * NRC: 14675
 * Fecha de creacion: 09/12/23 
 * Fecha de modificacion: 04/01/24 
 * PROYECTO UNIDAD 2: Prestamos Bancarios
 * ****************************************************************************/

#pragma once
#include <string>
#include <set>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cctype>
#include <conio.h>
#include <cctype>
#include "Validaciones.h"

using namespace std;
/*
@Constructor
*/
Validaciones::Validaciones() {

}

Validaciones::~Validaciones() {

}
/*
@name function: validarEnteros
@return varible type: int
@parameters: void

	-valida la entrada solo de numeros enteros desde teclado.
*/
int Validaciones::validarEnteros() {
    char* dato = new char[10];
    int i = 0;
    int numero;
    char c;
    bool hayNumeros = false; // Variable para verificar si se ha ingresado al menos un número

    while ((c = _getch()) != 13) {
        if (c >= '0' && c <= '9') {
            dato[i++] = c;
            printf("%c", c);
            numero = atoi(dato);
            hayNumeros = true; // Se ha ingresado al menos un número
        }
        else if (c == 8 && i != 0) {
            dato[i - 1] = 0;
            i--;
            putchar(8);
            putchar(32);
            putchar(8);
        }
    }

    // Si no se ha ingresado ningún número, no se permite presionar Enter
    if (!hayNumeros) {
        return validarEnteros(); // Llamada recursiva para volver a solicitar la entrada
    }

    dato[i] = '\0';
    return numero;
}


// pa validar que en el monto se ingresen los valores que el banco de pichincha usa
int Validaciones::validarEnterosMonto() {
    int numero;
    bool primerIntento = true;

    do {
        char* dato = new char[10];
        int i = 0;
        char c;

        if (!primerIntento) {
        	system("cls");
        	cout << "---------- P R E S T A M O S ----------\n";
            std::cout << "- Ingrese un monto valido: ";
    		cout << "\n  (Monto minimo: $300 - Monto maximo: $25000):  $";
        }

        while ((c = _getch()) != 13 || i == 0) {
            if (c >= '0' && c <= '9' && i < 9) {

                dato[i++] = c;
                printf("%c", c);
            }
            else if (c == 8 && i != 0) {

                dato[i - 1] = 0;
                i--;

                putchar(8);
                putchar(32);
                putchar(8);
            }
        }

        dato[i] = '\0';

        numero = atoi(dato);
        if (numero < 300 || numero > 25000) {
            delete[] dato; 
        } else {
            std::cout << "\n"; 
            delete[] dato;
        }

        primerIntento = false;

    } while (numero < 300 || numero > 25000);

    return numero;
}

// pa validar las cuotas
int Validaciones::validarEnterosCuotas() {
    int numero;
    bool primerIntento = true;

    do {
        char* dato = new char[10];
        int i = 0;
        char c;

        if (!primerIntento) {
        	system("cls");
			cout << "---------- P R E S T A M O S ----------\n";
            std::cout << "- Ingrese una cantidad valida: ";
		    cout << "\n  (Cuotas (3, 6, 9, 12, 18, 24, 32, o 36 meses):  ";
        }

        while ((c = _getch()) != 13 || i == 0) {
            if (c >= '0' && c <= '9' && i < 9) {

                dato[i++] = c;
                printf("%c", c);
            }
            else if (c == 8 && i != 0) {

                dato[i - 1] = 0;
                i--;

                putchar(8);
                putchar(32);
                putchar(8);
            }
        }

        dato[i] = '\0';

        numero = atoi(dato);

        if (!(numero == 3 || numero == 6 || numero == 9 || numero == 12 || 
              numero == 18 || numero == 24 || numero == 32 || numero == 36)) {
            delete[] dato; 
        } else {
            std::cout << "\n"; 
            delete[] dato;
        }

        primerIntento = false;

    } while (!(numero == 3 || numero == 6 || numero == 9 || numero == 12 || 
               numero == 18 || numero == 24 || numero == 32 || numero == 36));

    return numero;
}




/*
@name function: validarDoubles
@return varible type: double
@parameters: void

	-valida la entrada solo de numeros enteros y flotantes desde teclado.
*/
double Validaciones::validarDoubles() {
	char* dato = new char[10];
	int i = 0;
	double numero;
	int cont = 0;
	char c;
	while ((c = _getch()) != 13) {

		if (c >= '0' && c <= '9') {

			dato[i++] = c;
			printf("%c", c);
			numero = atof(dato);
		}
		else if (c == '.' && cont < 1) {
			printf("%c", c);
			dato[i++] = c;
			cont++;
			numero = atof(dato);
		}
		else if (c == 8 && i != 0) {

			dato[i - 1] = 0;
			i--;
			putchar(8);
			putchar(32);
			putchar(8);
		}
	}
	dato[i] = '\0';
	return numero;
}



char* Validaciones::validarStrings() {
    char* dato = new char[0];
    char c;
    int i = 0;

    while (true) {
        c = _getch();

        // Verificar si el campo está vacío y el caracter es Enter
        if (i == 0 && c == 13) {
            continue; // Ignorar Enter mientras el campo está vacío
        }

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            dato[i++] = toupper(c);
            printf("%c", c);
        } else if (c == 8 && i != 0) {
            dato[--i] = '\0';

            putchar(8);
            putchar(32);
            putchar(8);
        } else if (c == 13) {
            dato[i] = '\0';
            break;
        }
    }

    return dato;
}


bool Validaciones::isNamePatternValid(const std::string &name) {
    std::string vowels = "aeiou";
    int consecutiveConsonants = 0;
    int consecutiveVowels = 0;

    bool hasConsonant = false;
    bool hasVowel = false;

    for (size_t i = 0; i < name.length(); i++) {
        if (vowels.find(tolower(name[i])) != std::string::npos) {
            consecutiveConsonants = 0;
            consecutiveVowels++;
            hasVowel = true;
        } else {
            consecutiveVowels = 0;
            consecutiveConsonants++;
            hasConsonant = true;
        }

        if (consecutiveConsonants > 3 || consecutiveVowels > 2) {
            return false;
        }
    }

    // Devolver false si contiene solo consonantes o solo vocales
    return hasConsonant && hasVowel;
}


bool Validaciones::validateName(const std::string &name) {
    std::set<char> validLetters {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for (char c : name) {
        if (isalpha(c)) {
            c = tolower(c);
        } else {
            return false;
        }

        if (validLetters.find(c) == validLetters.end()) {
            return false;
        }
    }

    if (!isNamePatternValid(name)) {
        return false;
    }

    return true;
}


/*
@name function: validarEnterosCedula()
@return varible type: char*
@parameters: void

	-valida la entrada solo de numeros enteros de la cedula con un rango de 10 desde teclado.
*/
char* Validaciones::validarEnterosCedula() {
    const int maxDigitos = 10;
    char* dato = new char[maxDigitos + 1]; // +1 para el carácter nulo '\0'
    int i = 0;
    char c;

    while (true) {
        c = _getch();

        // Verificar si el campo está vacío y el caracter es Enter
        if (i == 0 && c == 13) {
            continue; // Ignorar Enter mientras el campo está vacío
        }

        if ((c >= '0' && c <= '9') && i < maxDigitos) { // Verificar límite de dígitos
            dato[i++] = c;
            printf("%c", c);
        } else if (c == 8 && i != 0) {
            dato[--i] = '\0';

            putchar(8);
            putchar(32);
            putchar(8);
        } else if (c == 13) {
            dato[i] = '\0';
            break;
        }
    }

    return dato;
}



bool Validaciones::esCedulaVacia(std::string &cedula) {
    return (cedula[0] == '\0');
}


/*
@name function: splitNumber
@return varible type: int*
@parameters: char* number

	-valida posicion por posicion la cedula que se ingresa
*/

int* Validaciones::splitNumber(const std::string& number) {
    int* digit = new int[10];

    for (int i = 0; i < 10; i++) {
        digit[i] = number[i] - '0';
    }

    return digit;
}

/*
@name function: verificacion1
@return varible type: bool
@parameters: char* numCedula

	-se verifican los dos primeros numeros de la cedula
*/
bool Validaciones::verificacion1(const std::string& numCedula) {
    int* cedula = splitNumber(numCedula);
    int digitos12 = cedula[0] * 10 + cedula[1];

    delete[] cedula;

    return (digitos12 < 24 && digitos12 > 0);
}


/*
@name function: verificacion2
@return varible type: bool
@parameters: char* numCedula

	-se verifica el tercer numero de la cedula
*/

bool Validaciones::verificacion2(const std::string& numCedula) {
    int* cedula = splitNumber(numCedula);
    int digito3 = cedula[2];

    delete[] cedula;

    return (digito3 < 6 && digito3 >= 0);
}

/*
@name function: verificacion3
@return varible type: bool
@parameters: char* numCedula

	-se verifica el ultimo digito de la cedula
*/
bool Validaciones::verificacion3(const std::string& numCedula) {
    int* cedula = splitNumber(numCedula);
    int digValidador;
    int coef;
    int mult;
    int sum = 0;
    int decSuperior;

    for (int i = 0; i < 9; i++) {
        coef = (i % 2 == 0) ? 2 : 1;
        mult = cedula[i] * coef;

        if (mult > 9) {
            mult -= 9;
        }
        sum += mult;
    }

    delete[] cedula;

    decSuperior = ((sum / 10) + 1) * 10;
    digValidador = decSuperior - sum;

    if (digValidador == 10) {
        digValidador = 0;
    }

    return (digValidador == (numCedula[9] - '0'));
}
/*
@name function: verificacionCedula
@return varible type: bool
@parameters: char* numCedula

	-se verifica que el numero de cedula cumpla las tres validaciones
*/
bool Validaciones::verificacionCedula(std::string &numCedula) {
	bool bandera1 = false;
	bool bandera2 = false;
	bool bandera3 = false;

	if (verificarLongitud(numCedula) == true) {
		bandera1 = verificacion1(numCedula);
		bandera2 = verificacion2(numCedula);
		bandera3 = verificacion3(numCedula);
	}

	if (bandera1 && bandera2 && bandera3) {
		return true;
	}

	return false;
}

/*
@name function: LongitudCadena
@return varible type: int
@parameters: char *cedula

	-Saca la longitud de la cedula
*/

int Validaciones::LongitudCadena(const std::string& cedula) {
    return cedula.length();
}
/*
@name function: verificarLongitud
@return varible type: bool
@parameters: char *p

	-Verifica si la longitud de la cedula es de 10 para hacerlo valida
*/
bool Validaciones::verificarLongitud(std::string &p) {

	if (LongitudCadena(p) == 10) {
		return true;
	}
	else {
		return false;
	}
}