#include <iostream>
#include "ListaDoble.h"
#include <iomanip>

ListaDoble::ListaDoble(Nodo* _cabeza, Nodo* _cola){
    cabeza = _cabeza;
    cola = _cola;
}

ListaDoble::ListaDoble(){
    cabeza = nullptr;
    cola = nullptr;
}

Nodo* ListaDoble::get_cabeza(){
    return cabeza;
}

void ListaDoble::set_cabeza(Nodo* nueva_cabeza){
    cabeza = nueva_cabeza;
}

Nodo* ListaDoble::get_cola(){
    return cola;
}

void ListaDoble::set_cola(Nodo* nueva_cola){
    cola = nueva_cola;
}

void ListaDoble::insertar_cabeza(Estudiante* valor){
    Nodo* nuevo_nodo;
    if(esta_vacia()){
        nuevo_nodo = new Nodo(valor, nullptr, nullptr);
        cola = nuevo_nodo;
    }
    else{
        nuevo_nodo = new Nodo(valor, cabeza, nullptr);
        cabeza->set_anterior(nuevo_nodo);
    }
    cabeza = nuevo_nodo;

}

void ListaDoble::insertar_cola(Estudiante* valor){
    Nodo* nuevo_nodo;
    if(esta_vacia()){
        nuevo_nodo = new Nodo(valor, nullptr, nullptr);
        cabeza = nuevo_nodo;
    }
    else{
        nuevo_nodo = new Nodo(valor, nullptr, cola);
        cola->set_siguiente(nuevo_nodo);
    }
    cola = nuevo_nodo;
}

void ListaDoble::insertar_entre(std::string valor_buscado, Estudiante* valor, int opcion){
    Nodo* aux = cabeza;
    while(aux!=nullptr){
        if(valor_buscado == aux->get_valor()->getter_general(opcion)){
            Nodo* nuevo = new Nodo(valor,aux->get_siguiente(), aux);
            if(aux != cola && aux->get_siguiente()!= nullptr){
                aux->get_siguiente()->set_anterior(nuevo);
            }else{
                cola = nuevo;
            }
            aux->set_siguiente(nuevo);
            break;
        }
        aux = aux->get_siguiente();
    }

}

void ListaDoble::imprimir(){
    Nodo* aux = cabeza;
    std::cout << std::setw(10) << "ID" << "  " <<
    std::setw(20) << "Primer Nombre" << "  " <<
    std::setw(20) << "Segundo Nombre" << "  " <<
    std::setw(20) << "Primer Apellido" << "  " <<
    std::setw(20) << "Segundo Apellido" << std::endl;
    while(aux!=nullptr){
        aux->get_valor()->to_string();
        aux = aux->get_siguiente();
    }
}

void ListaDoble::eliminar(std::string valor){
    Nodo* aux = cabeza;
    Nodo* temp;
    while(aux!=nullptr){
        if( valor == aux->get_valor()->get_id() ){
            if(cabeza == cola){
                cabeza = nullptr;
                cola = nullptr;
            }
            else{
                if(aux->get_anterior() == nullptr){
                    temp = aux->get_siguiente();
                    aux->set_siguiente(nullptr);
                    cabeza = temp;
                    cabeza->set_anterior(nullptr);
                }
                else if(aux->get_siguiente() == nullptr){

                    temp = aux->get_anterior();
                    aux->set_anterior(nullptr);
                    cola = temp;
                    cola->set_siguiente(nullptr);
                }
                else{
                    aux->get_anterior()->set_siguiente(aux->get_siguiente());
                    aux->get_siguiente()->set_anterior(aux->get_anterior());
                }
            }
            delete aux;
            break;
        }
        aux = aux->get_siguiente();
    }
    if(aux == nullptr){
        printf("ID de estudiante no encontrado.");
    }
}

Estudiante* ListaDoble::buscar(std::string valor_buscado){
    Nodo* aux = cabeza;
    while(aux!=nullptr){
        if( valor_buscado == aux->get_valor()->get_id() ){
            return aux->get_valor();
        }
        aux = aux->get_siguiente();
    }
    if(aux == nullptr){
        return nullptr;
    }
}

bool ListaDoble::esta_vacia(){
    return (cabeza == nullptr);
}
