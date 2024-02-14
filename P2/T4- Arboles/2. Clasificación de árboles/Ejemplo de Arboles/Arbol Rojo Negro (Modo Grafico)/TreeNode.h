#pragma once

enum class ColorNodoArbol {
    Negro,
    Rojo
};

class NodoArbol {
public:
    NodoArbol() = default;
    explicit NodoArbol(int valor);

    int valor();
    void valor(int valor);

    NodoArbol*& izquierda();
    void izquierda(NodoArbol* izquierda);

    NodoArbol*& derecha();
    void derecha(NodoArbol* derecha);

    NodoArbol*& padre();
    void padre(NodoArbol* padre);

    ColorNodoArbol color();
    void color(ColorNodoArbol color);

private:
    int valor_;
    NodoArbol* izquierda_ = nullptr;
    NodoArbol* derecha_ = nullptr;
    NodoArbol* padre_ = nullptr;
    ColorNodoArbol color_ = ColorNodoArbol::Negro;
};
