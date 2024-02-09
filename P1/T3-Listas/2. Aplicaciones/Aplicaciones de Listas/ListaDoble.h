#pragma once

#include "Nodo.h"

class ListaDoble
{
public:
    ListaDoble(Nodo* _cabeza, Nodo* _cola);
    ListaDoble();
    Nodo* get_cabeza();
    void set_cabeza(Nodo* _cabeza);
    Nodo* get_cola();
    void set_cola(Nodo* _cola);
    void insertar_cabeza(Estudiante* valor);
    void insertar_cola(Estudiante* valor);
    void insertar_entre(std::string valor_buscado, Estudiante* valor, int opcion);
    void eliminar(std::string valor);
    Estudiante* buscar(std::string valor_buscado);
    void imprimir();
    bool esta_vacia();
protected:
private:
    Nodo* cabeza;
    Nodo* cola;
};

