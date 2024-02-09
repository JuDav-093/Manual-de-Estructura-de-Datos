#include "Grafo.h"
#include "ListaDoble.cpp"

Grafo::Grafo()
{
    aristas = new ListaDoble<Arista*>();
    vertices = new ListaDoble<Vertice*>();
}

ListaDoble<Arista*>* Grafo::get_aristas(){
    return aristas;
}

ListaDoble<Vertice*>* Grafo::get_vertices(){
    return vertices;
}

void Grafo::resetear_dist_est(){
    Nodo<Vertice*>* vertice_nodo = vertices->get_cabeza();

    while(vertice_nodo!=nullptr){
        vertice_nodo->get_valor()->set_distancia_estim(std::numeric_limits<double>::infinity());
        vertice_nodo = vertice_nodo->get_siguiente();
    }

}

bool Grafo::existe_arista(Vertice* previo, Vertice* siguiente){
    Nodo<Arista*>* arista_nodo = aristas->get_cabeza();

    while(arista_nodo!=nullptr){
        if(  (arista_nodo->get_valor()->get_previo() == previo || arista_nodo->get_valor()->get_previo() == siguiente)
             && (arista_nodo->get_valor()->get_siguiente() == previo || arista_nodo->get_valor()->get_siguiente() == siguiente))
        {
             break;
        }

        arista_nodo = arista_nodo->get_siguiente();
    }

    return (arista_nodo!=nullptr);
}

void Grafo::imprimir_aristas(){
    Arista* arista;
    Nodo<Arista*>* arista_nodo = aristas->get_cabeza();
    while (arista_nodo!=nullptr){
        arista = arista_nodo->get_valor();
        printf("%c - %.2f - %c\n", arista->get_previo()->get_id(), arista->get_peso(), arista->get_siguiente()->get_id());
        arista_nodo = arista_nodo->get_siguiente();
    }

}

Arista* obtener_menor(ListaDoble<Arista*>* posibilidades, double recorrido, Vertice* vertice_act){
    Nodo<Arista*>* arista_aux1 = posibilidades->get_cabeza();
    Nodo<Arista*>* arista_aux2 = arista_aux1->get_siguiente();
    Vertice* a_mover1;
    Vertice* a_mover2;
    while (arista_aux2 != nullptr){
        a_mover1 = (arista_aux1->get_valor()->get_siguiente() == vertice_act) ? arista_aux1->get_valor()->get_previo() : arista_aux1->get_valor()->get_siguiente();
        a_mover2 = (arista_aux2->get_valor()->get_siguiente() == vertice_act) ? arista_aux2->get_valor()->get_previo() : arista_aux2->get_valor()->get_siguiente();

        if(a_mover2->get_distancia_estim() < a_mover1->get_distancia_estim()){
            arista_aux1 = arista_aux2;
        }

        arista_aux2 = arista_aux2->get_siguiente();
    }

    return arista_aux1->get_valor();
}

bool es_arista_posible(Arista* arista, Vertice* vertice_act, Vertice* vertice_prov, ListaDoble<Vertice*>* camino){

    Nodo<Vertice*>* camino_nodo = camino->get_cabeza();
    Vertice* vertice_caminado;
    if(camino_nodo!=nullptr){
        while(camino_nodo->get_siguiente()!=nullptr){
            vertice_caminado = camino_nodo->get_valor();
            if(((arista->get_previo() == vertice_caminado)&& arista->get_previo()!= vertice_act)
                                                        ||
                ((arista->get_siguiente() == vertice_caminado) && arista->get_siguiente()!= vertice_act))
            {
                return false;
            }
            camino_nodo = camino_nodo->get_siguiente();
        }
    }


    return ((arista->get_previo() == vertice_act || arista->get_siguiente() == vertice_act)
                                                &&
            (arista->get_previo() != vertice_prov && arista->get_siguiente() != vertice_prov));


}

Vertice* regresar_ultimo_distinto(ListaDoble<Vertice*>* camino, ListaDoble<Vertice*>* regresados, Vertice* vertice_act){
    Nodo<Vertice*>* caminado = camino->get_cola();
    Nodo<Vertice*>* regresado;

    while(caminado!=nullptr){
        if(caminado->get_valor() != vertice_act){
            regresado = regresados->get_cabeza();
            while(regresado!=nullptr){
                if(regresado->get_valor() == caminado->get_valor()){
                    break;
                }
                regresado = regresado->get_siguiente();
            }
            if(regresado==nullptr){
                break;
            }
        }
        caminado = caminado->get_anterior();
    }

    return caminado->get_valor();

}

double Grafo::dijkstra(Vertice* inicio, Vertice* fin){

    ListaDoble<Vertice*>* ruta = new ListaDoble<Vertice*>();

    ListaDoble<Vertice*>* camino = new ListaDoble<Vertice*>();
    ListaDoble<Vertice*>* regresados = new ListaDoble<Vertice*>();
    ListaDoble<Arista*>* posibilidades;
    Nodo<Arista*>* arista_nodo;

    Arista* arista;
    Vertice* vertice_act = inicio;
    Vertice* vertice_expl;
    Vertice* vertice_prov = nullptr;
    double recorrido = 0;
    resetear_dist_est();
    vertice_act->set_distancia_estim(0);
    camino->insertar_cola(inicio);

    while (vertice_act != fin){

        ruta->insertar_cola(vertice_act);

        posibilidades = new ListaDoble<Arista*>();
        arista_nodo = aristas->get_cabeza();
        vertice_expl = vertice_act;

        printf("\nRecorrido %.4f\nPosibilidades:\n", recorrido);

        while(arista_nodo!=nullptr){

            if(es_arista_posible(arista_nodo->get_valor(), vertice_act, vertice_prov, camino))
            {

                arista = arista_nodo->get_valor();

                if(vertice_act == arista->get_siguiente()){
                    vertice_expl = arista->get_previo();
                }
                else{
                    vertice_expl = arista->get_siguiente();
                }

                if(vertice_expl->get_distancia_estim() > recorrido+arista->get_peso()){

                    vertice_expl->set_distancia_estim(recorrido+arista->get_peso());

                }
                printf("Id: %c\n", vertice_expl->get_id());
                printf("Distancia: %f\n", vertice_expl->get_distancia_estim());

                posibilidades->insertar_cola(arista);

            }

            arista_nodo = arista_nodo->get_siguiente();

        }
        if(posibilidades->esta_vacia()){

            ruta->eliminar_cola();
            printf("\nRegresando\n");

            vertice_prov = vertice_act;
            vertice_act = regresar_ultimo_distinto(camino, regresados, vertice_act);

            regresados->insertar_cola(vertice_prov);


            printf("\nMoviendose a\n");
            printf("%c\n", vertice_act->get_id());

            recorrido = vertice_act->get_distancia_estim();
        }
        else{

            vertice_prov = vertice_act;

            arista = obtener_menor(posibilidades, recorrido ,vertice_act);

            if(vertice_act == arista->get_siguiente()){
                vertice_act = arista->get_previo();
            }
            else{
                vertice_act = arista->get_siguiente();
            }

            printf("\nMoviendose a\n");
            printf("%c\n", vertice_act->get_id());

            if((vertice_act->get_distancia_estim() < recorrido+arista->get_peso()))
            {
                ruta->eliminar_cola();
                printf("\nReasignando ruta\n");
            }

            recorrido = vertice_act->get_distancia_estim();

            camino->insertar_cola(vertice_act);
        }
    }

    ruta->insertar_cola(fin);
    Nodo<Vertice*>* ruta_nodo = ruta->get_cabeza();
    printf("\nRuta\n");
    while(ruta_nodo!=nullptr){
        printf("%c\t", ruta_nodo->get_valor()->get_id());
        ruta_nodo = ruta_nodo->get_siguiente();
    }

    return recorrido;
}


Grafo::~Grafo()
{
    //dtor
}
