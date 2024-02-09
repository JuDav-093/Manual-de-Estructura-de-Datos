#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include "Nodo.h"

class ListaSimple
{
    public:
        void insertar_cabeza(int);
        void insertar_cola(int);
        void imprimir_desde_la_cabeza();
        void imprimir_desde_la_cola();
        void imprimir_desde_la_cola_recursiva(Nodo*);
        bool buscar(int);
        void eliminar_por_la_cabeza();
        void eliminar_por_la_cola();
        void lista_vacia();
        int suma_de_elementos_pares();
        int resta_de_elementos_pares();
        int multiplicacion_de_elementos_pares();
        double division_de_elementos_pares();
        bool es_primo(int);
        int suma_elementos_primos();
        int suma_de_digitos_de_un_numero_en_posiciones_pares(Nodo*,int);
        int suma_de_digitos_de_un_numero_en_posiciones_pares();
        void ordenarLista();
        ListaSimple();
        ~ListaSimple();
    protected:

    private:
        Nodo* cabeza;
};

#endif // LISTASIMPLE_H
