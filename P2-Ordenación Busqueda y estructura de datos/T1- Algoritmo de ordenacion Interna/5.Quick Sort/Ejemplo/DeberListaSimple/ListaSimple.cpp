#include <iostream>
#include "ListaSimple.h"
#include "Nodo.h"

ListaSimple::ListaSimple()
{
    cabeza = nullptr;
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
    if (cabeza == nullptr) {
        cabeza = nodo_nuevo;
    } else {
        Nodo* aux = cabeza;

        while (aux->get_siguiente() != nullptr) {
            aux = aux->get_siguiente();
        }

        aux->set_siguiente(nodo_nuevo);
    }
}


void ListaSimple::imprimir_desde_la_cabeza(){
    Nodo* aux = cabeza;
    printf("\nImprimir desde la cabeza:\n");
    while(!(aux==nullptr)){
        printf("%d", aux->get_valor());
        aux = aux->get_siguiente();
        printf("\t", 4);
    }
    printf("\n");
}

void ListaSimple::imprimir_desde_la_cola(){
    printf("\nImprimir desde la cola:\n");
    imprimir_desde_la_cola_recursiva(cabeza);
    printf("\n");
}

void ListaSimple::imprimir_desde_la_cola_recursiva(Nodo* nodo_actual){
    if(nodo_actual==nullptr){
        return;
    }
    imprimir_desde_la_cola_recursiva(nodo_actual->get_siguiente());
    printf("%d\t",nodo_actual->get_valor());

}

bool ListaSimple::buscar(int valor_buscado) {
    Nodo* aux = cabeza;
    int posicion = 1;
    while (aux != nullptr) {
        if (aux->get_valor() == valor_buscado) {
            printf("El valor %d fue encontrado en la posición %d\n", valor_buscado, posicion);
            return true;
        }
        aux = aux->get_siguiente();
        posicion++;
    }
    printf("El valor %d no se encontró en la lista.\n", valor_buscado);
    return false;
}

void ListaSimple::eliminar_por_la_cabeza(){
    lista_vacia();
    Nodo* elminar_nodo=cabeza;
    cabeza=cabeza->get_siguiente();
    delete elminar_nodo;
}

void ListaSimple::eliminar_por_la_cola(){
    lista_vacia();
    //mmm no se si sea necesario pero esto es si existe solo un elemento
    if(cabeza->get_siguiente()==nullptr){
        delete cabeza;
        cabeza=nullptr;
        return;
    }
    Nodo* aux = cabeza;
    while (aux->get_siguiente()->get_siguiente() != nullptr) {
        aux = aux->get_siguiente();
    }
    
    delete aux->get_siguiente();
    aux->set_siguiente(nullptr);

}

void ListaSimple::lista_vacia(){
    if(cabeza==nullptr){
        printf("La lista esta vacia no se puede borrar ningun elementos");
    }
}

//OPERACIONES CON LOS ELEMENTOS PARES E IMPARES

int ListaSimple::suma_de_elementos_pares(){
    Nodo* aux=cabeza;
    int suma=0;
    while (aux!=nullptr)
    {
        //Para impares aux->get_valor()%2!=0
        if(aux->get_valor()%2==0){
            suma += aux->get_valor();
        }
        aux=aux->get_siguiente();
    }
    return suma;
    
}

int ListaSimple::resta_de_elementos_pares(){
    Nodo* aux=cabeza;
    int resta=0;
    while (aux!=nullptr){
        //Para impares aux->get_valor()%2!=0
        if(aux->get_valor()%2==0){
            resta -= aux->get_valor();
        }
        aux=aux->get_siguiente();
    }
}

int ListaSimple::multiplicacion_de_elementos_pares(){
    Nodo* aux=cabeza;
    int multiplicacion=1;
    while (aux!=nullptr)
    {
        //Para impares aux->get_valor()%2!=0
        if(aux->get_valor()%2==0){
            multiplicacion *= aux->get_valor();
        }
        aux=aux->get_siguiente();
    }
    return multiplicacion;
}

double ListaSimple::division_de_elementos_pares(){
    Nodo* aux=cabeza;
    double division=1.0;
    while (aux!=nullptr)
    {
        //Para impares aux->get_valor()%2!=0
        if(aux->get_valor()%2==0){
            if(aux->get_valor()!=0){
                division /= aux->get_valor();
            }else{
                std::cout << "Error: División por cero." << std::endl;
                return 0.0;
            }
        }
        aux=aux->get_siguiente();
    }
    return division;
    
}

//OPERACIONES CON LOS ELEMNTOS PRIMOS
bool ListaSimple::es_primo(int valor_lista){
    if(valor_lista<=1){
        return false;
    }
    for(int i=2;i*i<=valor_lista;i++){
        if(valor_lista%i==0){
            return false;
        }
    }
    return true;
}

int ListaSimple::suma_elementos_primos() {
    Nodo* aux = cabeza;
    int suma = 0;

    while (aux != nullptr) {
        if (es_primo(aux->get_valor())) { 
            suma += aux->get_valor(); 
        }
        aux = aux->get_siguiente();
    }

    return suma;
}

/*int ListaSimple::suma_de_digitos_de_un_numero_en_posiciones_pares(){
    Nodo* aux = cabeza;
    int suma = 0;
    int posicion = 1;

    while(aux != nullptr){
        if(posicion % 2 == 0){
            int numero = aux->get_valor();
            int suma_parcial = 0;

            while(numero != 0){
                suma_parcial += numero % 10;
                numero /= 10;
            }

            suma += suma_parcial;
            std::cout << "Suma parcial en posición " << posicion << ": " << suma_parcial << std::endl;
        }
        aux = aux->get_siguiente();
        posicion++;
    }
    
    return suma;
}*/

int ListaSimple::suma_de_digitos_de_un_numero_en_posiciones_pares(Nodo* nodo, int posicion){
    if(nodo == nullptr) {
        return 0;
    }
    if(posicion % 2 == 0){ 
        int numero = nodo->get_valor();
        int suma_parcial_de_digitos = 0;
        while(numero != 0){
            suma_parcial_de_digitos += numero % 10; 
            numero /= 10;
        }
        std::cout << "Suma parcial en posicion " << posicion << ": " << suma_parcial_de_digitos << std::endl;
        return suma_parcial_de_digitos + suma_de_digitos_de_un_numero_en_posiciones_pares(nodo->get_siguiente(), posicion + 1);
    }

    return suma_de_digitos_de_un_numero_en_posiciones_pares(nodo->get_siguiente(), posicion + 1);
}

int ListaSimple::suma_de_digitos_de_un_numero_en_posiciones_pares(){
    return suma_de_digitos_de_un_numero_en_posiciones_pares(cabeza, 1);
}



ListaSimple::~ListaSimple()
{
    //dtor
}

void ListaSimple::ordenarLista(){
    Nodo* aux=cabeza;
    Nodo* pivote=cabeza;
    int temp;
    while(pivote!=nullptr){
        aux=cabeza;
        while(aux!=nullptr){

            if (aux->get_valor()>pivote->get_valor()){

                temp=pivote->get_valor();
                pivote->set_valor(aux->get_valor());
                aux->set_valor(temp);

            }
            aux = aux->get_siguiente();

        }
        pivote =pivote->get_siguiente();
    }  
}