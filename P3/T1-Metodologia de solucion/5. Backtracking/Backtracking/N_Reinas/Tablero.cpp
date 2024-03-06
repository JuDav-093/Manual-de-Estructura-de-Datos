#include <iostream>

#include "Tablero.h"
#include <iomanip>

Tablero::Tablero() {
    TAM = 0;
    piezas_strings = nullptr;
}

Tablero::Tablero(int _TAM) {

    //ENCERO MI MATRIZ DE PUNTEROS A strings CON DIRECCIONES NULAS

	TAM = _TAM;

    piezas_strings = (std::string***)malloc(TAM * sizeof(std::string**));
    if (piezas_strings != nullptr) {
        for (int i = 0; i < TAM; i++) {
            *(piezas_strings + i) = (std::string**)malloc(TAM * sizeof(std::string*));
        }
        for (int i = 0; i < TAM; i++) {
            if (*(piezas_strings + i) != nullptr) {
                for (int j = 0; j < TAM; j++) {
                    *(*(piezas_strings + i) + j) = new std::string("-");
                }
            }
        }
    }

}

void Tablero::set_TAM(int _TAM) {
	TAM = _TAM;
}

int Tablero::get_TAM() {
	return TAM;
}

void Tablero::set_piezas_strings(std::string*** _piezas_strings) {
    piezas_strings = _piezas_strings;
}

std::string*** Tablero::get_piezas_strings() {
    return piezas_strings;
}

bool Tablero::esta_ocupado(int _x, int _y) {
    if (*(*(piezas_strings +_x)+_y) != nullptr) {
        return true;
    }
    return false;
}

void Tablero::mostrar_tablero() {

    if (piezas_strings != nullptr) {
        for (int i = 0; i < TAM; i++) {
            if (*(piezas_strings + i) != nullptr) {
                for (int j = 0; j < TAM; j++) {
                    std::cout << std::setw(10) << *(*(*(piezas_strings + i) + j)) << std::setw(10);
                }
            }
            printf("\n");
        }
    }
}

Tablero::~Tablero() {
}
