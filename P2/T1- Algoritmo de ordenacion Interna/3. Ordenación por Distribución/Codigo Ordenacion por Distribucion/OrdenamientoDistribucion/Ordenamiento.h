#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <vector>

class Ordenamiento {
public:
    static void ordenamientoPorDistribucion(std::vector<int> &arr);
private:
    static void distribucionRecursiva(std::vector<int> &arr, int exp);
};

#endif
