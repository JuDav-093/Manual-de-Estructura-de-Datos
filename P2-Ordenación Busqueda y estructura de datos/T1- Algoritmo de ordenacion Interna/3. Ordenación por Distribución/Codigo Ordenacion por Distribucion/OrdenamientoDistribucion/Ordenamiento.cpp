#include "ordenamiento.h"
#include <vector>
#include <iostream>

void Ordenamiento::distribucionRecursiva(std::vector<int> &arr, int exp) {
    if (exp <= 0) {
        return;
    }

    // Creamos 10 "buckets" para los dígitos del 0 al 9
    std::vector<std::vector<int>> buckets(10); 

    // Distribuimos los números en los "buckets" basados en el dígito actual
    for (int num : arr) {
        int digit = (num / exp) % 10;
        buckets[digit].push_back(num); 
    }

    // Combinamos los números de los "buckets" en el arreglo original
    int index = 0;
    for (int i = 0; i < 10; ++i) {
        for (int num : buckets[i]) {
            arr[index++] = num;
        }
    }

    // Llamada recursiva para el siguiente dígito
    distribucionRecursiva(arr, exp * 10);
}


void Ordenamiento::ordenamientoPorDistribucion(std::vector<int> &arr) {
    // Llamada inicial a la función de distribución recursiva
    int exp = 1;
    distribucionRecursiva(arr, exp);
}
