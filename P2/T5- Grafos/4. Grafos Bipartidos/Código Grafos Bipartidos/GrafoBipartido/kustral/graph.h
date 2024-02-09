#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <unordered_map>
// Estructura de datos para almacenar un borde del grafo
struct Edge {
    int src, dest, weight;
};
// Una clase para representar un conjunto disjunto
class DisjointSet
{
    std::unordered_map<int, int> parent;
public:
    // Realizar la operación MakeSet
    void makeSet(int n);
    // Encuentra la raíz del conjunto al que pertenece el elemento `k`
    int Find(int k);
    // Realizar Unión de dos subconjuntos
    void Union(int a, int b);
};
#endif