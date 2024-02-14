#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
class Nodo {
public:
    int dato;
    int altura; // Altura del sub�rbol enraizado en este nodo
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int valor);
};

#endif // NODO_H_INCLUDED
