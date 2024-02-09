#pragma once

#include "Estudiante.h"

class Nodo
{
public:
    Nodo(Estudiante* _valor, Nodo* _siguiente, Nodo* _anterior);
    Nodo();
    ~Nodo();
    Estudiante* get_valor();
    void set_valor(Estudiante* new_valor);
    Nodo* get_siguiente();
    void set_siguiente(Nodo* new_siguiente);
    Nodo* get_anterior();
    void set_anterior(Nodo* new_anterior);

protected:
private:
   Estudiante* valor;
   Nodo* siguiente;
   Nodo* anterior;

};
