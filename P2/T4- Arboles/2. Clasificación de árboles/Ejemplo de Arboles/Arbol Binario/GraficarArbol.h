#pragma once

void graficarArbol(Nodo* raiz, int x, int y, int dx, int dy);

void graficarArbol(Nodo* raiz, int x, int y, int dx, int dy) {
    if (raiz == NULL) {
        return;
    }

    char buffer[10];
    sprintf_s(buffer, "%d", raiz->valor);
    outtextxy(x, y, buffer);

    setcolor(WHITE);
    circle(x, y, 20);

    if (raiz->izquierdo != NULL) {
        line(x, y, x - dx, y + dy);
        graficarArbol(raiz->izquierdo, x - dx, y + dy, dx / 2, dy);
    }

    if (raiz->derecho != NULL) {
        line(x, y, x + dx, y + dy);
        graficarArbol(raiz->derecho, x + dx, y + dy, dx / 2, dy);
    }
}