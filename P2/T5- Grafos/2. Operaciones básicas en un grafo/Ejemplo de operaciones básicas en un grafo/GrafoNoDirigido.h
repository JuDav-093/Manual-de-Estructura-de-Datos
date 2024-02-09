#ifndef GRAFONODIRIGIDO_H
#define GRAFONODIRIGIDO_H

#include <vector>
#include <stack>

class GrafoNoDirigido {
private:
    int numNodos;
    std::vector<std::vector<int>> adyacencia;

public:
    GrafoNoDirigido(int n);
    void agregarNodo();
    void eliminarNodo(int nodo);
    void agregarArista(int nodoA, int nodoB);
    void eliminarArista(int nodoA, int nodoB);
    void imprimirGrafo();
    void busquedaDFS(int nodoInicial);
};

#endif // GRAFONODIRIGIDO_H
