#include <iostream>
#include <list>

using namespace std;

// Tamaño de la tabla hash
const int tableSize = 10;

// Clase para el hash table
class HashTable {
private:
    // Array de listas para la tabla hash
    list<int> table[tableSize];
    
    // Función de hash
    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    // Insertar un elemento en la tabla hash
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Buscar un elemento en la tabla hash
    bool search(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == key) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    HashTable hash;

    // Insertar elementos en la tabla hash
    hash.insert(5);
    hash.insert(15);
    hash.insert(25);
    hash.insert(7);

    // Buscar elementos en la tabla hash
    cout << "Buscando 15: " << (hash.search(15) ? "Encontrado" : "No encontrado") << endl;
    cout << "Buscando 25: " << (hash.search(25) ? "Encontrado" : "No encontrado") << endl;
    cout << "Buscando 10: " << (hash.search(10) ? "Encontrado" : "No encontrado") << endl;

    return 0;
}
