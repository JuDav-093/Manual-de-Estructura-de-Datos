#pragma once

#include "RedBlackTree.cpp"

class Menu {
public:
    void dibujar_arbol(ArbolRojoNegro& arbol, int x, int y, int radio_nodo);
    void setColor(int textColor, int bgColor);
    void menuBase();
    
};