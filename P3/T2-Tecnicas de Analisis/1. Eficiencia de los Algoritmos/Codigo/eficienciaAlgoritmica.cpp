#include <iostream>
#include <list>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Función para buscar un elemento en una lista usando búsqueda lineal
// Función para buscar un elemento en una lista usando búsqueda lineal
list<int>::iterator linearSearch(const list<int>& lst, int target) {
    auto it = find(lst.begin(), lst.end(), target);
    return it != lst.end() ? lst.erase(it) : lst.end();
}


// Función para buscar un elemento en una lista usando búsqueda binaria
list<int>::iterator binarySearch(const list<int>& lst, int target) {
    // Utilizamos const_iterator porque lower_bound devuelve un const_iterator
    list<int>::const_iterator it = lower_bound(lst.begin(), lst.end(), target);
    if (it != lst.end() && *it == target)
        return lst.erase(it); // Convertimos const_iterator a iterator
    else
        return lst.end();
}

int main() {
    const int size = 1000000;
    list<int> lst;

    // Llenar la lista con números del 1 al 1000000
    for (int i = 1; i <= size; ++i) {
        lst.push_back(i);
    }

    // Buscar un elemento usando búsqueda lineal
    auto startLinear = high_resolution_clock::now();
    list<int>::iterator linearResult = linearSearch(lst, size);
    auto stopLinear = high_resolution_clock::now();
    auto durationLinear = duration_cast<microseconds>(stopLinear - startLinear);

    // Buscar un elemento usando búsqueda binaria
    auto startBinary = high_resolution_clock::now();
    list<int>::iterator binaryResult = binarySearch(lst, size);
    auto stopBinary = high_resolution_clock::now();
    auto durationBinary = duration_cast<microseconds>(stopBinary - startBinary);

    // Mostrar los resultados
    if (linearResult != lst.end()) {
        cout << "Elemento encontrado usando búsqueda lineal." << endl;
    } else {
        cout << "Elemento no encontrado usando búsqueda lineal." << endl;
    }
    cout << "Tiempo tomado por la búsqueda lineal: " << durationLinear.count() << " microsegundos." << endl;

    if (binaryResult != lst.end()) {
        cout << "Elemento encontrado usando búsqueda binaria." << endl;
    } else {
        cout << "Elemento no encontrado usando búsqueda binaria." << endl;
    }
    cout << "Tiempo tomado por la búsqueda binaria: " << durationBinary.count() << " microsegundos." << endl;

    return 0;
}