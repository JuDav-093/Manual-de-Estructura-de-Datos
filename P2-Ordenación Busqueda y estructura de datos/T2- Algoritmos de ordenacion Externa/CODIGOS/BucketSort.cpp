#include <iostream> 
#include <vector> 
#include <algorithm> 
 
using namespace std; 
 
void bucketSort(vector<float>& arr) { 
    int n = arr.size(); 
 
    // Crear un vector de buckets 
    vector<vector<float>> buckets(n); 
 
    // Colocar los elementos en los buckets 
    for (int i = 0; i < n; i++) { 
        int bucketIndex = n * arr[i]; 
        buckets[bucketIndex].push_back(arr[i]); 
    } 
 
    // Ordenar individualmente cada bucket usando cualquier algoritmo de ordenación (aquí se utiliza sort de la STL) 
    for (int i = 0; i < n; i++) { 
        sort(buckets[i].begin(), buckets[i].end()); 
    } 
 
    // Concatenar los buckets ordenados en el arreglo final 
    int index = 0; 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < buckets[i].size(); j++) { 
            arr[index++] = buckets[i][j]; 
        } 
    } 
} 
 
int main() { 
    vector<float> arr = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51}; 
    int n = arr.size(); 
 
    cout << "Arreglo original: "; 
    for (int i = 0; i < n; i++) { 
        cout << arr[i] << " "; 
    } 
    cout << endl; 
 
    bucketSort(arr); 
 
    cout << "Arreglo ordenado: "; 
    for (int i = 0; i < n; i++) { 
        cout << arr[i] << " "; 
    } 
    cout << endl; 
 
    return 0; 
} 