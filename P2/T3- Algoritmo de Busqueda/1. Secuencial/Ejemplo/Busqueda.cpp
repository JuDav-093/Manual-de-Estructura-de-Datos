// Archivo de implementación (busqueda.cpp)
#include "busqueda.h"
std::list<int>::iterator busquedaSecuencial(std::list<int>& lista, int elemento) {
    for (auto it = lista.begin(); it != lista.end(); ++it) {
        if (*it == elemento) {
            return it;  // Devuelve un iterador apuntando al elemento encontrado
        }
    }
    return lista.end();  // Devuelve el iterador al final si el elemento no se encuentra
}
