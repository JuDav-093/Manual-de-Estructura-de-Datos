#include "Nodo.h"

Nodo* Nodo::getSiguiente(){
    return siguiente;
}

void Nodo::setSiguiente(Nodo* newNodo)
{
   siguiente = newNodo;
}

int Nodo::getValor(void)
{
   return valor;
}

void Nodo::setValor(int newValor)
{
   valor = newValor;
}

Nodo::Nodo(int valor, Nodo* siguiente)
{
	this->valor = valor;
	this->siguiente = siguiente;
}

Nodo::~Nodo()
{
   // TODO : implement
}

