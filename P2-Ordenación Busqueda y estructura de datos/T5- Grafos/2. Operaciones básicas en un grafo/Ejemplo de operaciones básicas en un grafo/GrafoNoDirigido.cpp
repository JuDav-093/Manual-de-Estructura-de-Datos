#include "GrafoNoDirigido.h"
#include <iostream>
#include <algorithm> // Necesario para std::find

GrafoNoDirigido::GrafoNoDirigido(int n) : numNodos(n), adyacencia(n, std::vector<int>()) {}

void GrafoNoDirigido::agregarNodo() {
    ++numNodos;
    adyacencia.resize(numNodos);
}

void GrafoNoDirigido::eliminarNodo(int nodo) {
    nodo--;

    if (nodo >= 0 && nodo < numNodos) {
        // Creamos un nuevo vector de adyacencia sin las conexiones asociadas al nodo que queremos eliminar
        std::vector<std::vector<int>> nuevoAdyacencia(numNodos - 1, std::vector<int>());

        // Copiamos las conexiones del vector de adyacencia original al nuevo vector, excluyendo las conexiones asociadas al nodo que queremos eliminar
        int nuevoIndice = 0;
        for (int i = 0; i < numNodos; ++i) {
            if (i != nodo) {
                for (int vecino : adyacencia[i]) {
                    if (vecino != nodo + 1) {
                        nuevoAdyacencia[nuevoIndice].push_back(vecino > nodo + 1 ? vecino - 1 : vecino);
                    }
                }
                nuevoIndice++;
            }
        }

        // Actualizamos el vector de adyacencia con el nuevo vector creado
        adyacencia = nuevoAdyacencia;
        numNodos--;

        std::cout << "\nNodo " << nodo + 1 << " eliminado correctamente.\n" << std::endl;
    } else {
        std::cerr << "\nError: El nodo a eliminar está fuera del rango del grafo.\n" << std::endl;
    }
}





void GrafoNoDirigido::agregarArista(int nodoA, int nodoB) {
    nodoA--;
    nodoB--;

    if (nodoA >= 0 && nodoA < numNodos && nodoB >= 0 && nodoB < numNodos) {
        // Verificamos si los nodos existen en el grafo
        if (adyacencia.size() >= nodoA && adyacencia.size() >= nodoB) {
            adyacencia[nodoA].push_back(nodoB);
            adyacencia[nodoB].push_back(nodoA);
            std::cout << "\nArista entre " << nodoA + 1 << " y " << nodoB + 1 << " agregada correctamente.\n" << std::endl;
        } else {
            std::cerr << "\nError: Al menos uno de los nodos ingresados no existe en el grafo.\n" << std::endl;
        }
    } else {
        std::cerr << "\nError: Al menos uno de los nodos ingresados esta fuera del rango del grafo. \n" << std::endl;
    }
}

void GrafoNoDirigido::eliminarArista(int nodoA, int nodoB) {
    nodoA--;
    nodoB--;

    if (nodoA >= 0 && nodoA < numNodos && nodoB >= 0 && nodoB < numNodos) {
        // Verificamos si los nodos existen en el grafo
        if (adyacencia.size() >= nodoA && adyacencia.size() >= nodoB) {
            // Verificamos si hay una arista entre los nodos ingresados
            auto itA = std::find(adyacencia[nodoA].begin(), adyacencia[nodoA].end(), nodoB);
            auto itB = std::find(adyacencia[nodoB].begin(), adyacencia[nodoB].end(), nodoA);

            if (itA != adyacencia[nodoA].end() && itB != adyacencia[nodoB].end()) {
                adyacencia[nodoA].erase(itA);
                adyacencia[nodoB].erase(itB);
                std::cout << "\nArista entre " << nodoA + 1 << " y " << nodoB + 1 << " eliminada correctamente.\n" << std::endl;
            } else {
                std::cerr << "\nError: No hay una arista entre los nodos ingresados.\n" << std::endl;
            }
        } else {
            std::cerr << "\nError: Al menos uno de los nodos ingresados no existe en el grafo.\n" << std::endl;
        }
    } else {
        std::cerr << "\nError: Al menos uno de los nodos ingresados esta fuera del rango del grafo.\n" << std::endl;
    }
}


void GrafoNoDirigido::imprimirGrafo() {
    std::cout << "Lista de adyacencia del grafo:" << std::endl;
    for (int i = 0; i < numNodos; ++i) {
        std::cout << "Nodo " << i + 1 << " esta conectado con:";
        for (int vecino : adyacencia[i]) {
            std::cout << " " << vecino + 1;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void GrafoNoDirigido::busquedaDFS(int nodoInicial) {
    std::vector<bool> visitado(numNodos, false);
    std::stack<int> pila;

    pila.push(nodoInicial);

    std::cout << "Recorrido DFS desde el nodo " << nodoInicial << ": ";

    while (!pila.empty()) {
        int nodoActual = pila.top();
        pila.pop();

        if (!visitado[nodoActual]) {
            std::cout << nodoActual << " ";
            visitado[nodoActual] = true;

            for (int vecino : adyacencia[nodoActual]) {
                if (!visitado[vecino]) {
                    pila.push(vecino);
                }
            }
        }
    }

    std::cout << std::endl;
}
