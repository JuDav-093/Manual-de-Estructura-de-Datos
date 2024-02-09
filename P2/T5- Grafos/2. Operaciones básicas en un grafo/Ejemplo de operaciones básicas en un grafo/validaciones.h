#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <cctype>

int ingresar_enteros(const char* msj);
int borrar(char* datos, int& i);
float ingresar_reales(const char* msj);
std::string ingresar_alfabetico(const char* msj);
std::string ingresar_cedula(const char* msj);
std::string ingresar_nombre(const char* msj);

int ingresar_enteros(const char* msj) {
    char* datos = new char[10];
    char c;
    int i = 0;

    printf("%s", msj);
    printf("\n");
    while ((c = getch()) != 13 && i < 9) {
        if ((c >= '0' && c <= '9')|| c == 8) {
            if(c == 8){
                i = borrar(datos,i);
            }else{
                printf("%c", c);
                datos[i++] = c;
            }

        }
    }
    datos[i] = '\0';
    return atoi(datos);
}

int ingresar_enteros_1_al_4(const char* msj) {
    char* datos = new char[10];
    char c;
    int i = 0;

    printf("%s", msj);
    printf("\n");
    while ((c = getch()) != 13 && i < 9) {
        if ((c >= '1' && c <= '4')|| c == 8) {
            if(c == 8){
                i = borrar(datos,i);
            }else{
                printf("%c", c);
                datos[i++] = c;
            }

        }
    }
    datos[i] = '\0';
    return atoi(datos);
}

float ingresar_reales(const char* msj) {
    char* datos = new char[12];
    char c;
    int i = 0;
    bool hay_punto = false;
    int posicion_punto;

    printf("%s", msj);
    printf("\n");
    while ((c = getch()) != 13 && i < 11) {
        if ((c >= '0' && c <= '9') || (c == '.' && !hay_punto)|| c == 8 || c == '-') {
            if(!((c == '.')&& i == 0)){
                if(!((c == '-') && i != 0)){
                    if (c == 8) {
                        i = borrar(datos, i);
                        if((i+1) == posicion_punto){
                            hay_punto = false;
                        }
                    }
                    else {
                        printf("%c", c);
                        datos[i++] = c;

                        if (c == '.') {
                            posicion_punto = i;
                            hay_punto = true;
                        }
                    }
                }
            }
        }
    }
    datos[i] = '\0';
    return atof(datos);
}

std::string ingresar_alfabetico(const char* msj) {
    char datos[21];
    char c;
    int i = 0;

    printf("%s", msj);
    printf("\n");
    while ((c = getch()) != 13 && i < 20) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')|| c == 32||c == 8) {
            if (c == 8) {
                i = borrar(datos, i);
            } else {
                printf("%c", c);
                datos[i++] = c;
            }
        }
    }
    datos[i] = '\0';
    return std::string(datos);
}


int calcular_digito_verificador(const char* cedula) {
    int impares[5];
    int pares[4];
    int suma_impares = 0;
    int suma_pares = 0;

    for (int i = 0; i < 9; i++) {
        int digito = cedula[i] - '0';

        if (i % 2 == 0) {
            impares[i / 2] = digito * 2;
            if (impares[i / 2] > 9) {
                impares[i / 2] -= 9;
            }
            suma_impares += impares[i / 2];
        } else {
            pares[i / 2] = digito;
            suma_pares += pares[i / 2];
        }
    }

    int suma_total = suma_impares + suma_pares;
    int digito_verificador_calculado = suma_total % 10;

    if (digito_verificador_calculado != 0) {
        digito_verificador_calculado = 10 - digito_verificador_calculado;
    }

    return digito_verificador_calculado;
}

bool verificar_primeros_digitos(const char* cedula) {

    int primeros_digitos = (cedula[0] - '0') * 10 + (cedula[1] - '0');
    return ((primeros_digitos > 0 && primeros_digitos < 25) || primeros_digitos == 30);
}

std::string ingresar_cedula(const char* msj) {
    char cedula[10];
    char ch;
    int i = 0;
    std::cout<<msj<<std::endl;
    while (i<10 && (ch = getch()) != 13) {
        if (ch == 8) {
                i = borrar(cedula, i);
            } else if (isdigit(ch)) {
            cedula[i]= ch;
            std::cout << ch;
        }
        i++;
    }
    cedula[i] = '\0';
    int digito_verificador_calculado = calcular_digito_verificador(cedula);
    if (i != 10) {
        std::cout << "\nError! La cedula debe tener 10 caracteres." << std::endl;
        ingresar_cedula(msj);
    }else if(!verificar_primeros_digitos(cedula)){
        std::cout << "\nError! Los primeros digitos de la cedula no coinciden con ninguna provincia valida." << std::endl;
        ingresar_cedula(msj);

    }else if
        ((cedula[9] - '0') != digito_verificador_calculado){
        std::cout << "\nError! El decimo digito no es valido." << std::endl;
        ingresar_cedula(msj);
    }
    return std::string(cedula);



}

std::string ingresar_nombre(const char* msj) {
    char nombre[21];
    char c;
    int i = 0;

    printf("%s", msj);
    printf("\n");

    while ((c = getch()) != 13 && i < 20) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == 8) {
            if (c == 8) {
                i = borrar(nombre, i);
            } else {
                printf("%c", c);
                nombre[i++] = c;
            }
        }
    }

    nombre[i] = '\0';

 for (int j=0;j<21;j++){
        if (j ==0) {
        nombre[0] = std::toupper(nombre[0]);
    }else{
        nombre[j] = std::tolower(nombre[j]);
    }

}
return std::string(nombre);
}


std::string generarEtiqueta() {
    static int contador = 0; // Variable est�tica para mantener el estado entre llamadas
    std::string etiqueta = "L";

    if (contador < 10) {
        etiqueta += "000" + std::to_string(contador);
    } else if (contador < 100) {
        etiqueta += "00" + std::to_string(contador);
    } else if (contador < 1000) {
        etiqueta += "0" + std::to_string(contador);
    } else {
        etiqueta += std::to_string(contador);
    }

    contador++;
    if (contador >= 10000) {
        contador = 0; // Reiniciar el contador si llega a 10000
    } else if (contador == 10000 - 1) {
        contador = 0; // Reiniciar el contador si llega a L9999
    }

    printf("Id generado.\n");
    return etiqueta;
}

int borrar(char* datos, int& i) {
    if (i > 0) {
        printf("\b \b");
        i--;
        datos[i] = '\0';
        return i;
    }
    return 0;
}

int calcular_digito_verificador_cuenta(const std::string& cuenta) {
    int impares[5];
    int pares[4];
    int suma_impares = 0;
    int suma_pares = 0;

    for (int i = 0; i < 9; i++) {
        int digito = cuenta[i] - '0';

        if (i % 2 == 0) {
            impares[i / 2] = digito * 2;
            if (impares[i / 2] > 9) {
                impares[i / 2] -= 9;
            }
            suma_impares += impares[i / 2];
        } else {
            pares[i / 2] = digito;
            suma_pares += pares[i / 2];
        }
    }

    int suma_total = suma_impares + suma_pares;
    int digito_verificador_calculado = suma_total % 10;

    if (digito_verificador_calculado != 0) {
        digito_verificador_calculado = 10 - digito_verificador_calculado;
    }

    return digito_verificador_calculado;
}

std::string generarNumeroSecuencialCuenta() {
    static int ultimoNumero = 1;
    ultimoNumero = (ultimoNumero % 999999999);
    std::string numero = "22";
    numero += std::to_string(ultimoNumero);
    numero.insert(numero.begin() + 2, 8 - numero.length(), '0');
    int digitoVerificador = calcular_digito_verificador_cuenta(numero);
    numero += std::to_string(digitoVerificador);
    ultimoNumero++;
    return numero;
}

int ingresarPositivos(const char* msj) {
    char* datos = new char[10];
    char c;
    int i = 0;

    printf("%s", msj);
    printf("\n");
    while ((c = getch()) != 13 && i < 9) {
        if ((c >= '0' && c <= '9') || c == 8) {
            if (c == 8) {
                i = borrar(datos, i);
            } else {
                printf("%c", c);
                datos[i++] = c;
            }
        }
    }
    datos[i] = '\0';
    int numero = atoi(datos);
    delete[] datos;

    if (numero < 0) {
        printf("\nDebe ingresar un número entero positivo.\n");
        return ingresarPositivos(msj); // Llama recursivamente a la función si se ingresa un número negativo
    }

    return numero;
}

float ingresar_decimal_positivo(const char* msj) {
    char* datos = new char[12];
    char c;
    int i = 0;
    bool hay_punto = false;
    int posicion_punto;

    printf("%s", msj);
    printf("\n");
    while ((c = getch()) != 13 && i < 11) {
        if ((c >= '0' && c <= '9') || (c == '.' && !hay_punto)|| c == 8) {
            if(!((c == '.')&& i == 0)){
                if(!((c == '-') && i != 0)){
                    if (c == 8) {
                        i = borrar(datos, i);
                        if((i+1) == posicion_punto){
                            hay_punto = false;
                        }
                    }
                    else {
                        printf("%c", c);
                        datos[i++] = c;

                        if (c == '.') {
                            posicion_punto = i;
                            hay_punto = true;
                        }
                    }
                }
            }
        }
    }
    datos[i] = '\0';
    return atof(datos);
}

#endif // VALIDACIONES_H_INCLUDED
