#pragma once

#include "Tablero.h"

bool validar_posiciones(int, int*, int, int*, int);
void fun(Tablero& tablero, int x, int* _x, int, int*, int&);

bool validar_posiciones(int x, int* _x, int y, int* _y, int TAM) {
	for (int i = 0; i < TAM; i++) {
		if (y == *(_y + i) || std::abs((x - *(_x + i)) == std::abs(y - *(_y + i)))) {
			return false;
		}
	}
	return true;
}

void fun(Tablero& tablero, int x, int* _x, int y, int* _y, int& contador) {

	if (x != tablero.get_TAM() && y != tablero.get_TAM()) {

		if (validar_posiciones(x, _x, y, _y, tablero.get_TAM())) {
			*(*(*(tablero.get_piezas_strings() + x) + y)) = "Reina";
			*(_x + x) = x;
			*(_y + x) = y;
			fun(tablero, x + 1, _x, 0, _y, contador);
			if ((x+1 != tablero.get_TAM() && *(_y + tablero.get_TAM() - 1) == 10)){
				*(*(*(tablero.get_piezas_strings() + x) + y)) = "-";
			}
			else {
				contador++;
			}
		}

		fun(tablero, x, _x, y + 1, _y, contador);

		if (*(_y + tablero.get_TAM()-1) != 10) {

			tablero.mostrar_tablero();
			printf("SOL: %i, ------------------------------------------------------------------\n", contador);
		}

		*(*(*(tablero.get_piezas_strings() + x) + y)) = "-";
		*(_y + x) = 10;
		*(_x + x) = 20;
	}

}

