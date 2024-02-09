#include "colasCirculares.h"

CircularQueue::CircularQueue(int size) {
    capacidad = size + 1;  // El tamaño real es uno más para diferenciar entre frente y final.
    array = new int[capacidad];
    frente = final = 0;
}

CircularQueue::~CircularQueue() {
    delete[] array;
}

bool CircularQueue::estaVacia() {
    return frente == final;
}

bool CircularQueue::estaLlena() {
    return (final + 1) % capacidad == frente;
}

void CircularQueue::encolar(int elemento) {
    if (!estaLlena()) {
        array[final] = elemento;
        final = (final + 1) % capacidad;
        std::cout << "Elemento " << elemento << " encolado.\n";
    } else {
        std::cout << "La cola está llena. No se puede encolar.\n";
    }
}

void CircularQueue::desencolar() {
    if (!estaVacia()) {
        int elemento = array[frente];
        frente = (frente + 1) % capacidad;
        std::cout << "Elemento " << elemento << " desencolado.\n";
    } else {
        std::cout << "La cola está vacía. No se puede desencolar.\n";
    }
}

void CircularQueue::mostrarContenido() {
    if (!estaVacia()) {
        std::cout << "Contenido de la cola: ";
        int i = frente;
        while (i != final) {
            std::cout << array[i] << " ";
            i = (i + 1) % capacidad;
        }
        std::cout << "\n";
    } else {
        std::cout << "La cola esta vacía.\n";
    }
}
