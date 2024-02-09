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

void Cola::insertar(int valor){
    Nodo* nuevo_nodo = new Nodo(valor, nullptr);
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
            printf("%d", aux->getValor());
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

int Cola::sumaDeCola(){
    int resultado = 0;
    if(estaVacia()){
        printf("No existen nodos en la cola.\n");
    }else{
        Nodo* aux = cabeza;
        while(aux!=nullptr){
            resultado = resultado + aux->getValor();
            aux = aux->getSiguiente();
        }
    }
    return resultado;
}


void Cola::retornarColaPar(Cola* cola_par){
    if(estaVacia()){
        printf("No existen nodos en la cola.\n");
    }else{
        Nodo* aux = cabeza;
        while(aux!=nullptr){
            if(aux->getValor()%2 == 0){
                cola_par->insertar(aux->getValor());
            }
            aux = aux->getSiguiente();
        }
    }
}

Cola Cola::extraerNumerosImpares(Cola& cola) {
    Cola colaImpares;  // Cola para almacenar números impares
    Nodo* aux = cola.getCabeza();

    while (aux != nullptr) {
        if (aux->getValor() % 2 != 0) {
            colaImpares.insertar(aux->getValor());
        }
        aux = aux->getSiguiente();
    }

    return colaImpares;
}

bool Cola::esPrimo(int numero) {
    if (numero <= 1) {
        return false;
    }

    int limite = static_cast<int>(std::sqrt(numero));
    for (int i = 2; i <= limite; ++i) {
        if (numero % i == 0) {
            return false;
        }
    }

    return true;
}

Cola Cola::extraerNumerosPrimos(Cola& cola) {
    Cola colaPrimos;
    Nodo* aux = cola.getCabeza();

    while (aux != nullptr) {
        if (esPrimo(aux->getValor())) {
            colaPrimos.insertar(aux->getValor());
        }
        aux = aux->getSiguiente();
    }

    return colaPrimos;
}

int Cola::sumarValoresCola(Cola& cola) {
    Nodo* aux = cola.getCabeza();
    int suma = 0;

    while (aux != nullptr) {
        suma += aux->getValor();
        aux = aux->getSiguiente();
    }

    return suma;
}
