#include <iostream>
#include "ListaSimple.h"
#include "Nodo.h"

ListaSimple::ListaSimple()
{
    cabeza = nullptr;
    cola=nullptr;
}

void ListaSimple::insertar_cabeza(int valor){
    Nodo* nodo_nuevo = new Nodo(valor, nullptr);
    if(cabeza == nullptr){
        cabeza = nodo_nuevo;
    }
    else{
        Nodo* aux = cabeza;
        cabeza = nodo_nuevo;
        cabeza->set_siguiente(aux);
    }
}

void ListaSimple::insertar_cola(int valor) {
    Nodo* nodo_nuevo = new Nodo(valor, nullptr);

    if (cola == nullptr) {
        // Si la lista está vacía, el nuevo nodo será tanto la cabeza como la cola
        cola = nodo_nuevo;
    } else {
        // Si la lista no está vacía, necesitamos encontrar el último nodo y enlazar el nuevo nodo al final
        Nodo* aux = cola;
        while (aux->get_siguiente() != nullptr) {
            aux = aux->get_siguiente();
        }
        aux->set_siguiente(nodo_nuevo);
    }
}

void ListaSimple::imprimir_cabeza(){
    Nodo* aux = cabeza;
    printf("\n");
    while(!(aux==nullptr)){
        printf("%d", aux->get_valor());
        aux = aux->get_siguiente();
        printf("\t", 4);
    }
    printf("\n");
}

void ListaSimple::eliminar_cabeza(){
    if(cabeza != nullptr){
        Nodo* temp = cabeza;
        cabeza = cabeza->get_siguiente();
        delete temp;
    }
}




void ListaSimple::imprimir_cola() {
    Nodo* aux = cola;
    printf("\n");

    while (aux != nullptr) {
        printf("%d\t", aux->get_valor());
        aux = aux->get_siguiente();
    }

    printf("\n");

}void ListaSimple::eliminar_cola() {
    if (cola == nullptr) {
        // La lista está vacía, no hay nada que eliminar
        return;
    } else if (cola->get_siguiente() == nullptr) {
        // Si solo hay un elemento en la lista, eliminarlo y establecer la cola como nullptr
        delete cola;
        cola = nullptr;
    } else {
        // Si hay más de un elemento, encontrar el nodo anterior al último nodo (la cola)
        Nodo* aux = cola;
        while (aux->get_siguiente()->get_siguiente() != nullptr) {
            aux = aux->get_siguiente();
        }

        // Eliminar el último nodo y establecer el siguiente del nodo anterior como nullptr
        delete aux->get_siguiente();
        aux->set_siguiente(nullptr);
    }
}



ListaSimple::~ListaSimple()
{
    //dtor
}
