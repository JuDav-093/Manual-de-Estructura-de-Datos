#include <iostream>
#include "graph.h"
#include "graph.cpp"
int main(){
    std::cout << "Ejecutando el algoritmo de Kruskal..." << std::endl;
    // vector de los bordes del grafo según el diagrama anterior.
    std::vector<Edge> edges = {
        // (u, v, w) el triplete representa el borde no dirigido desde
        // vértice `u` a vértice `v` con peso `w`
        {0, 1, 7}, {1, 2, 8}, {0, 3, 5}, {1, 3, 9}, {1, 4, 7}, {2, 4, 5},
        {3, 4, 15}, {3, 5, 6}, {4, 5, 8}, {4, 6, 9}, {5, 6, 11}
    };
    // numero total de nodos en el grafo (etiquetados de 0 a 6)
    int n = 7;
    // construir grafo
    std::vector<Edge> e = runKruskalAlgorithm(edges, n);
    std::cout << " Arbol de expansion minima por Kruskal:" << std::endl;
    for (Edge &edge: e) {
        std::cout << "(" << edge.src << ", " << edge.dest << ", "
                  << edge.weight << ")" << std::endl;
    }


    return 0;
}
