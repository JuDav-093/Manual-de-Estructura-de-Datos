#include <iostream> 
using namespace std; 
 
void shellSort(int arr[], int n) {     

// Empieza con un gran intervalo y lo reduce gradualmente     

for (int gap = n / 2; gap > 0; gap /= 2) { 
        // Realiza el ordenamiento de inserción dentro del intervalo actual 
        for (int i = gap; i < n; i++) { 
            int temp = arr[i]; 
            int j; 
             
            // Mueve los elementos anteriores al elemento seleccionado 
            // hasta que se encuentra la posición adecuada para insertar el elemento 
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) { 
                arr[j] = arr[j - gap]; 
            } 
             
            // Inserta el elemento en su posición correcta 
            arr[j] = temp; 
        } 
    } 
} 
 
// Función para imprimir un arreglo 
void printArray(int arr[], int size) { 
    for (int i = 0; i < size; i++) { 
        cout << arr[i] << " "; 
    } 
    cout << endl; 
} 
 
int main() { 
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
 
    cout << "Arreglo original: "; 
    printArray(arr, n); 
 
    shellSort(arr, n); 
 
    cout << "Arreglo ordenado: "; 
    printArray(arr, n); 
 
    return 0; 
} 