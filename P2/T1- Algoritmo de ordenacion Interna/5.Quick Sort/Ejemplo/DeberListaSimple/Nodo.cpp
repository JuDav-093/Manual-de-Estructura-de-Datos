/***********************************************************************
 * Module:  Nodo.cpp
 * Author:  Joan Cobe�a
 * Modified: viernes, 1 de diciembre de 2023 12:05:38 a. m.
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/

#include "Nodo.h"

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getValor()
// Purpose:    Implementation of Nodo::getValor()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Nodo::get_valor()
{
   return valor;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setValor(int newValor)
// Purpose:    Implementation of Nodo::setValor()
// Parameters:
// - newValor
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::set_valor(int new_valor)
{
   valor = new_valor;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getSiguiente()
// Purpose:    Implementation of Nodo::getSiguiente()
// Return:     Nodo
////////////////////////////////////////////////////////////////////////

Nodo* Nodo::get_siguiente()
{
   return siguiente;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setSiguiente(Nodo newSiguiente)
// Purpose:    Implementation of Nodo::setSiguiente()
// Parameters:
// - newSiguiente
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::set_siguiente(Nodo* new_siguiente)
{
   siguiente = new_siguiente;
}


Nodo* Nodo::get_anterior(){
   return anterior;

}
void Nodo::set_anterior(Nodo* new_anterior){
   anterior=new_anterior;
}
////////////////////////////////////////////////////////////////////////
// Name:       Nodo::Nodo()
// Purpose:    Implementation of Nodo::Nodo()
// Return:
////////////////////////////////////////////////////////////////////////

Nodo::Nodo()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::Nodo(int valor, Nodo siguiente)
// Purpose:    Implementation of Nodo::Nodo()
// Parameters:
// - valor
// - siguiente
// Return:
////////////////////////////////////////////////////////////////////////

Nodo::Nodo(int _valor, Nodo* _siguiente)
{
   valor = _valor;
   siguiente = _siguiente;
}


Nodo::Nodo(int _valor, Nodo* _siguiente,Nodo* _anterior)
{
   valor = _valor;
   siguiente = _siguiente;
   anterior=_anterior;
}
////////////////////////////////////////////////////////////////////////
// Name:       Nodo::~Nodo()
// Purpose:    Implementation of Nodo::~Nodo()
// Return:
////////////////////////////////////////////////////////////////////////

Nodo::~Nodo()
{
   // TODO : implement
}
