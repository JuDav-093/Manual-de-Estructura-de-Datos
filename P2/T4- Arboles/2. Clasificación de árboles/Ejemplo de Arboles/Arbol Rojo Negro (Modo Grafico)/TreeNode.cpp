#include "TreeNode.h"

NodoArbol::NodoArbol(int valor) : valor_(valor) {}

int NodoArbol::valor() {
    return valor_;
}

void NodoArbol::valor(int valor) {
    valor_ = valor;
}

NodoArbol*& NodoArbol::izquierda() {
    return izquierda_;
}

void NodoArbol::izquierda(NodoArbol* izquierda) {
    izquierda_ = izquierda;
}

NodoArbol*& NodoArbol::derecha() {
    return derecha_;
}

void NodoArbol::derecha(NodoArbol* derecha) {
    derecha_ = derecha;
}

NodoArbol*& NodoArbol::padre() {
    return padre_;
}

void NodoArbol::padre(NodoArbol* padre) {
    padre_ = padre;
}

ColorNodoArbol NodoArbol::color() {
    return color_;
}

void NodoArbol::color(ColorNodoArbol color) {
    color_ = color;
}
