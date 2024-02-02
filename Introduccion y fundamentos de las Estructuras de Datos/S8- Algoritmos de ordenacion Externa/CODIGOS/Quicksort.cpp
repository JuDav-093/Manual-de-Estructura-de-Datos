#include <iostream>
#include <algorithm>
using namespace std;
 
// Partición usando el esquema de partición de Lomuto
int partition(int a[], int start, int end)
{
    // Elija el elemento más a la derecha como un pivote de la array
    int pivot = a[end];
 
    // los elementos menores que el pivote serán empujados a la izquierda de `pIndex`
    // elementos más que el pivote serán empujados a la derecha de `pIndex`
    // elementos iguales pueden ir en cualquier dirección
    int pIndex = start;
 
    // cada vez que encontramos un elemento menor o igual que el pivote, `pIndex`
    // se incrementa, y ese elemento se colocaría antes del pivote.
    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
 
    // intercambiar `pIndex` con pivote
    swap (a[pIndex], a[end]);
 
    // devuelve `pIndex` (índice del elemento pivote)
    return pIndex;
}
 
// Rutina de clasificación rápida
void quicksort(int a[], int start, int end)
{
    // condición base
    if (start >= end) {
        return;
    }
 
    // reorganizar los elementos a través del pivote
    int pivot = partition(a, start, end);
 
    // recurre en un subarray que contiene elementos que son menores que el pivote
    quicksort(a, start, pivot - 1);
 
    // se repite en el subarray que contiene elementos que son más que el pivote
    quicksort(a, pivot + 1, end);
}
 
// Implementación en C++ del algoritmo Quicksort
int main()
{
    int a[] = { 9, -3, 5, 2, 6, 8, -6, 1, 3 };
    int n = sizeof(a)/sizeof(a[0]);
 
    quicksort(a, 0, n - 1);
 
    // imprime la array ordenada
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
 
    return 0;
}