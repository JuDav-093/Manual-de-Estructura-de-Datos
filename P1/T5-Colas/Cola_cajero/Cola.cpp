#include "Cola.h"

Cola::Cola(){
    cabeza = nullptr;
    cola = nullptr;
}

Nodo* Cola::getCabeza(){
    return cabeza;
}

void Cola::setCabeza(Nodo* cabeza){
    this->cabeza = cabeza;
}

Nodo* Cola::getCola(){
    return cola;
}

void Cola::setCola(Nodo* cola){
    this->cola = cola;
}

void Cola::insertar(int ID, int t_llegada, int t_espera, int t_no_trabaja, int t_servicio, int t_salida, int t_entre_llegadas){
    Nodo* nuevo_nodo = new Nodo(ID, t_llegada, t_espera, t_no_trabaja, t_servicio, t_salida, t_entre_llegadas, nullptr);
    if(cabeza == nullptr){
        cabeza = nuevo_nodo;
        cola = nuevo_nodo;
    }else{
        cola->setSiguiente(nuevo_nodo);
        cola = nuevo_nodo;
    }
}

void Cola::eliminar(){
    if(estaVacia()){
        printf("No existen nodos en la cola.\n");
    }else{
        Nodo* aux = cabeza->getSiguiente();
        cabeza->setSiguiente(nullptr);
        delete cabeza;
        cabeza = aux;
    }
}

void Cola::imprimir(){
    if(estaVacia()){
        printf("No existen nodos en la cola.\n");
    }else{
        Nodo* aux = cabeza;
        while(aux != nullptr){
            //printf("%d", aux->getValor());
            printf("\t", 3);
            aux = aux->getSiguiente();
        }
    }
}

bool Cola::estaVacia(){
    if(cabeza == nullptr){
        return 1;
    }else{
        return 0;
    }
}

Nodo* Cola::extraer_cabeza(){
    Nodo* aux = cabeza;
    if(aux!=nullptr){
        cabeza = cabeza->getSiguiente();
        aux->setSiguiente(nullptr);
    }
    return aux;
}

int Cola::actSize(){
    Nodo* aux = cabeza;
    int tamano = 0;
    while(aux!=nullptr){
        aux = aux->getSiguiente();
        tamano++;
    }
    return tamano;
}
