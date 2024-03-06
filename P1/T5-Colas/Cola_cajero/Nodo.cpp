#include "Nodo.h"
/***********************************************************************
 * Module:  Nodo.cpp
 * Author:  DARIO BENAVIDES
 * Modified: jueves, 30 de noviembre de 2023 10:00:16:PM
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/

Nodo* Nodo::getSiguiente(){
    return siguiente;
}

void Nodo::setSiguiente(Nodo* newNodo)
{
   siguiente = newNodo;
}

int Nodo::get_ID(void) {
	return ID;
}

int Nodo::get_t_llegada(void) {
	return t_llegada;
}

int Nodo::get_t_espera(void) {
	return t_espera;
}

int Nodo::get_t_no_trabaja(void) {
	return t_no_trabaja;
}

int Nodo::get_t_servicio(void) {
	return t_servicio;
}

int Nodo::get_t_salida(void) {
	return t_salida;
}

int Nodo::get_t_entre_llegadas(void) {
	return t_entre_llegadas;
}


Nodo::Nodo(int ID, int t_llegada, int t_espera, int t_no_trabaja, int t_servicio, int t_salida, int t_entre_llegadas, Nodo* siguiente)
{	
	this->ID = ID;
	this->t_llegada = t_llegada;
	this->t_espera = t_espera;
	this->t_no_trabaja = t_no_trabaja;
	this->t_servicio = t_servicio;
	this->t_salida = t_salida;
	this->t_entre_llegadas = t_entre_llegadas;

	this->siguiente = siguiente;
}

Nodo::~Nodo()
{
   // TODO : implement
}

