
#include "Nodo.h"

Nodo::Nodo(Estudiante* _valor, Nodo* _siguiente, Nodo* _anterior)
{
    valor = _valor;
    siguiente = _siguiente;
    anterior = _anterior;
}

Nodo::Nodo()
{
}

Nodo::~Nodo()
{

}

Estudiante* Nodo::get_valor()
{
   return valor;
}

void Nodo::set_valor(Estudiante* new_valor)
{
   valor = new_valor;
}

Nodo* Nodo::get_siguiente()
{
   return siguiente;
}

void Nodo::set_siguiente(Nodo* new_siguiente)
{
   siguiente = new_siguiente;
}

Nodo* Nodo::get_anterior()
{
   return anterior;
}

void Nodo::set_anterior(Nodo* new_anterior)
{
   anterior = new_anterior;
}
