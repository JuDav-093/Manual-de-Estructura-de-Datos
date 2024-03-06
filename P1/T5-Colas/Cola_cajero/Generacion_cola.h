#pragma once
#include "Cola.h"
#include "Nodo.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <string>
#include <cstdlib>

int calc_tiempo_no_trabaja(int t_llegada, int t_salida_prev) {
	return ((t_llegada > t_salida_prev) ? t_llegada : t_salida_prev) - t_salida_prev;
}

int calc_tiempo_espera(int t_llegada, int t_salida_prev) {
	return ((t_llegada > t_salida_prev) ? t_llegada: t_salida_prev) - t_llegada;
}

int calc_tiempo_salida(int t_llegada, int t_espera, int t_servicio) {
	return t_llegada + t_espera + t_servicio;
}

int calc_tiempo_servicio() {
	int t_servicio = 1 + std::rand() % 16;
	return t_servicio;
}

int calc_tiempo_llegada(int t_previo) {
	int t_llegada = t_previo + 1 + std::rand()%25;
	return t_llegada;
}

int generar_ID(int id_prev) {
	return id_prev + 1;
}

bool guardar_cola(Cola* cola, std::string nombre_archivo) {
    int dimension = 8;
    std::string ruta;
    char tmp[256];

    _getcwd(tmp, 256);
    ruta = std::string(tmp);

    std::string nombre_original = ruta + "//" + nombre_archivo;
    std::ofstream archivo_original(nombre_original, std::ios::trunc);
	Nodo* nodo_cliente = cola->getCabeza();

    if (!archivo_original)
    {
        return false;
    }
    else
    {
		archivo_original << "CLIENTE" <<"," << "TIEMPO DE LLEGADA" << "," << 
			"TIEMPO DE ESPERA" << "," << "TIEMPO NO TRABAJA EL CAJERO" << ","
			<< "TIEMPO DE SERVICIO" << "," << "TIEMPO DE SALIDA" << "," << "TIEMPO ENTRE LLEGADAS" << "\n";
		
		while (nodo_cliente != nullptr) {
			archivo_original << nodo_cliente->get_ID() << "," << nodo_cliente->get_t_llegada() << "," 
							<< nodo_cliente->get_t_espera() << "," << nodo_cliente->get_t_no_trabaja() << "," 
							<< nodo_cliente->get_t_servicio() << "," << nodo_cliente->get_t_salida() << "," 
							<< nodo_cliente->get_t_entre_llegadas() << "\n";
			nodo_cliente = nodo_cliente->getSiguiente();
		}
    }

    archivo_original.close();

    return true;
}

Cola* generar_cola(int num_clientes) {
	Cola* cola_clientes = new Cola();
	Nodo* nodo_cliente;
	int t_llegada;
	int t_espera;
	int t_servicio;

	for (int i = 0; i < num_clientes; i++) {
		if (cola_clientes->getCabeza() != nullptr) {
			nodo_cliente = cola_clientes->getCola();

			t_llegada = calc_tiempo_llegada(nodo_cliente->get_t_llegada());
			t_espera = calc_tiempo_espera(t_llegada, nodo_cliente->get_t_salida());
			t_servicio = calc_tiempo_servicio();
			cola_clientes->insertar(generar_ID(nodo_cliente->get_ID()), t_llegada, t_espera,
				calc_tiempo_no_trabaja(t_llegada, nodo_cliente->get_t_salida()),
				t_servicio, calc_tiempo_salida(t_llegada, t_espera, t_servicio),
				t_llegada - nodo_cliente->get_t_llegada());
		}
		else {
			t_llegada = calc_tiempo_llegada(0);
			t_servicio = calc_tiempo_servicio();
			t_espera = 0;

			cola_clientes->insertar(generar_ID(0), t_llegada, t_espera, 0, t_servicio, calc_tiempo_salida(t_llegada, t_espera, t_servicio), t_llegada);
		}
	}
	return cola_clientes;
}