#include "graph.h"
#include <algorithm>
// Realizar la operación MakeSet
void DisjointSet::makeSet(int n){
    // crea "n" conjuntos disjuntos (uno para cada vertice)
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}
// Encuentra la raíz del conjunto al que pertenece el elemento "k"
int DisjointSet::Find(int k){
    // si "k" es root
    if (parent[k] == k) {
        return k;
    }
    // recurre para el padre hasta que encontramos la raíz
    return Find(parent[k]);
}
// Realizar Unión de dos subconjuntos
void DisjointSet::Union(int a, int b){
  // encuentra la raíz de los conjuntos en los que se encuentran los elementos
    // Pertenece `x` e `y`
    int x = Find(a);
    int y = Find(b);
    parent[x] = y;
}
// Función para construir MST usando el algoritmo de Kruskal
std::vector<Edge> runKruskalAlgorithm(std::vector<Edge>& edges, int n){
    std::vector<Edge> MST;
    // inicializa la clase `DisjointSet`
    DisjointSet ds;
    // crea un conjunto singleton para cada elemento del universo
    ds.makeSet(n);
    // ordena los bordes aumentando el peso
    std::sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.weight > b.weight;
    });


    // MST contiene exactamente los bordes "V-1"
    while (MST.size() != n - 1){
        // considera el siguiente borde con peso mínimo del grafo
        Edge next_edge = edges.back();
        edges.pop_back();
       // encuentra la raíz de los conjuntos a los que pertenecen dos extremos
        // los vértices de la siguiente arista pertenecen
        int x = ds.Find(next_edge.src);
        int y = ds.Find(next_edge.dest);
        // si ambos extremos tienen diferentes padres, pertenecen a
        // diferentes componentes conectados y se pueden incluir en MST
        if (x != y){
            MST.push_back(next_edge);
            ds.Union(x, y);
        }
    }
    return MST;
}
