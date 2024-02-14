#pragma once
#include <functional>
#include <unordered_map>
#include <iostream>
#include "RedBlackTree.h"


inline NodoArbol* ArbolRojoNegro::obtener_raiz() {
        return raiz;
    }

inline int ArbolRojoNegro::obtener_columna(NodoArbol* nodo) {
    std::unordered_map<NodoArbol*, int> columnas;
    int columna_actual = 1;

    recorrer(raiz, [&](NodoArbol* n) {
        columnas.insert({ n, columna_actual });
        columna_actual++;
    }, DireccionRecorrido::EnOrden);

    return columnas[nodo];
}

inline int ArbolRojoNegro::obtener_fila(NodoArbol* nodo) {
    std::unordered_map<NodoArbol*, int> filas;
    int fila_actual = 1;
    std::function<void(NodoArbol*, int)> recorrer_recursivo;
    recorrer_recursivo = [&](NodoArbol* n, int fila) {
        filas[n] = fila;
        if (n->izquierda() != nodo_nulo) {
            recorrer_recursivo(n->izquierda(), fila + 1);
        }
        if (n->derecha() != nodo_nulo) {
            recorrer_recursivo(n->derecha(), fila + 1);
        }
    };
    recorrer_recursivo(raiz, fila_actual);
    return filas[nodo];
}


inline ArbolRojoNegro::ArbolRojoNegro() {
    nodo_nulo = new NodoArbol(0);
    nodo_nulo->izquierda(nullptr);
    nodo_nulo->derecha(nullptr);
    nodo_nulo->padre(nullptr);
    nodo_nulo->color(ColorNodoArbol::Negro);

    raiz = nodo_nulo;
}

inline void ArbolRojoNegro::insertar(int valor) {
    NodoArbol* nodo = new NodoArbol(valor);
    nodo->izquierda(nodo_nulo);
    nodo->derecha(nodo_nulo);
    nodo->color(ColorNodoArbol::Rojo);

    NodoArbol* y = nodo_nulo;
    NodoArbol* x = raiz;

    while (x != nodo_nulo) {
        y = x;

        if (nodo->valor() < x->valor()) {
            x = x->izquierda();
        } else {
            x = x->derecha();
        }
    }

    nodo->padre(y);

    if (y == nodo_nulo) {
        raiz = nodo;
    } else if (nodo->valor() < y->valor()) {
        y->izquierda(nodo);
    } else {
        y->derecha(nodo);
    }

    if (nodo->padre() == nodo_nulo) {
        nodo->color(ColorNodoArbol::Negro);
        return;
    }

    if (nodo->padre()->padre() == nodo_nulo) {
        return;
    }

    corregir_insertar(nodo);
}

inline void ArbolRojoNegro::eliminar(int valor) {
    eliminar(raiz, valor);
}

inline int ArbolRojoNegro::encontrar(int valor) {
    return encontrar(raiz, valor);
}

inline int ArbolRojoNegro::buscar(int valor) {
    return buscar(raiz, valor);
}

inline void ArbolRojoNegro::recorrer(std::function<void(int)> callback, DireccionRecorrido direccion) {
    if (raiz) {
        recorrer(raiz, callback, direccion);
    }
}

inline void ArbolRojoNegro::recorrer(std::function<void(NodoArbol*)> callback, DireccionRecorrido direccion) {
    if (raiz) {
        recorrer(raiz, callback, direccion);
    }
}

inline void ArbolRojoNegro::eliminar(NodoArbol* nodo, int valor) {
    NodoArbol* z = nodo_nulo;
    NodoArbol* x;
    NodoArbol* y;
    NodoArbol* encontrado = nodo_nulo;

    recorrer([&](NodoArbol* n) {
        if (n->valor() == valor && encontrado == nodo_nulo) {
            encontrado = n;
        }
    }, DireccionRecorrido::PreOrden);

    if (encontrado == nodo_nulo) {
        std::cout << "\n\nNo se pudo encontrar la clave en el arbol" << std::endl;
        return;
    }

    z = encontrado;
    y = z;
    ColorNodoArbol color_original_y = y->color();

    if (z->izquierda() == nodo_nulo) {
        x = z->derecha();
        intercambiar(z, z->derecha());
    } else if (z->derecha() == nodo_nulo) {
        x = z->izquierda();
        intercambiar(z, z->izquierda());
    } else {
        y = maximo(z->izquierda());
        color_original_y = y->color();
        x = y->izquierda();

        if (y->padre() == z) {
            x->padre(y);
        } else {
            intercambiar(y, y->izquierda());
            y->izquierda(z->izquierda());
            y->izquierda()->padre(y);
        }

        intercambiar(z, y);
        y->derecha(z->derecha());
        y->derecha()->padre(y);
        y->color(z->color());
    }

    if (color_original_y == ColorNodoArbol::Negro) {
        corregir_eliminar(x);
    }
}

inline int ArbolRojoNegro::encontrar(NodoArbol* nodo, int valor) {
    if (nodo == nodo_nulo || nodo->valor() == valor) {
        if (nodo == nodo_nulo) {
            return 0;
        }

        return nodo->valor();
    }

    if (valor < nodo->valor()) {
        return encontrar(nodo->izquierda(), valor);
    }

    return encontrar(nodo->derecha(), valor);
}

inline int ArbolRojoNegro::buscar(NodoArbol* nodo, int valor) {
    if (nodo == nodo_nulo || nodo->valor() == valor) {
        if (nodo == nodo_nulo) {
            std::cout << "\nNo existe el valor a buscar: " << valor << std::endl;
            return 0;
        }
        else{
        	std::cout << "\nEl valor si existe en el arbol: " << valor << std::endl;
            return 0;
		}

        return nodo->valor();
    }

    if (valor < nodo->valor()) {
        return buscar(nodo->izquierda(), valor);
    }

    return buscar(nodo->derecha(), valor);
}

inline void ArbolRojoNegro::recorrer(NodoArbol* nodo, std::function<void(int)> callback, DireccionRecorrido direccion) {
    if (nodo != nodo_nulo) {
        if (direccion == DireccionRecorrido::EnOrden) {
            recorrer(nodo->izquierda(), callback, direccion);
            callback(nodo->valor());
            recorrer(nodo->derecha(), callback, direccion);
        }
        else if (direccion == DireccionRecorrido::PostOrden) {
            recorrer(nodo->izquierda(), callback, direccion);
            recorrer(nodo->derecha(), callback, direccion);
            callback(nodo->valor());
        }
        else if (direccion == DireccionRecorrido::PreOrden) {
            callback(nodo->valor());
            recorrer(nodo->izquierda(), callback, direccion);
            recorrer(nodo->derecha(), callback, direccion);
        }
    }
}

inline void ArbolRojoNegro::recorrer(NodoArbol* nodo, std::function<void(NodoArbol*)> callback, DireccionRecorrido direccion) {
    if (nodo != nodo_nulo) {
        if (direccion == DireccionRecorrido::EnOrden) {
            recorrer(nodo->izquierda(), callback, direccion);
            callback(nodo);
            recorrer(nodo->derecha(), callback, direccion);
        }
        else if (direccion == DireccionRecorrido::PostOrden) {
            recorrer(nodo->izquierda(), callback, direccion);
            recorrer(nodo->derecha(), callback, direccion);
            callback(nodo);
        }
        else if (direccion == DireccionRecorrido::PreOrden) {
            callback(nodo);
            recorrer(nodo->izquierda(), callback, direccion);
            recorrer(nodo->derecha(), callback, direccion);
        }
    }
}

inline void ArbolRojoNegro::corregir_insertar(NodoArbol* k) {
    NodoArbol* u;

    while (k->padre()->color() == ColorNodoArbol::Rojo) {
        if (k->padre() == k->padre()->padre()->derecha()) {
            u = k->padre()->padre()->izquierda();

            if (u != nodo_nulo && u->color() == ColorNodoArbol::Rojo) {
                u->color(ColorNodoArbol::Negro);
                k->padre()->color(ColorNodoArbol::Negro);
                k->padre()->padre()->color(ColorNodoArbol::Rojo);
                k = k->padre()->padre();
            } else {
                if (k == k->padre()->izquierda()) {
                    k = k->padre();
                    rotar_derecha(k);
                }

                k->padre()->color(ColorNodoArbol::Negro);
                k->padre()->padre()->color(ColorNodoArbol::Rojo);
                rotar_izquierda(k->padre()->padre());
            }
        } else {
            u = k->padre()->padre()->derecha();

            if (u->color() == ColorNodoArbol::Rojo) {
                u->color(ColorNodoArbol::Negro);
                k->padre()->color(ColorNodoArbol::Negro);
                k->padre()->padre()->color(ColorNodoArbol::Rojo);
                k = k->padre()->padre();
            } else {
                if (k == k->padre()->derecha()) {
                    k = k->padre();
                    rotar_izquierda(k);
                }

                k->padre()->color(ColorNodoArbol::Negro);
                k->padre()->padre()->color(ColorNodoArbol::Rojo);
                rotar_derecha(k->padre()->padre());
            }
        }

        if (k == raiz) {
            break;
        }
    }

    raiz->color(ColorNodoArbol::Negro);
}

inline void ArbolRojoNegro::corregir_eliminar(NodoArbol* x) {
    NodoArbol* s;

    while (x != raiz && x->color() == ColorNodoArbol::Negro) {
        if (x == x->padre()->izquierda()) {
            s = x->padre()->derecha();

            if (s->color() == ColorNodoArbol::Rojo) {
                s->color(ColorNodoArbol::Negro);
                x->padre()->color(ColorNodoArbol::Rojo);
                rotar_izquierda(x->padre());
                s = x->padre()->derecha();
            }

            if (s->izquierda()->color() == ColorNodoArbol::Negro && s->derecha()->color() == ColorNodoArbol::Negro) {
                s->color(ColorNodoArbol::Rojo);
                x = x->padre();
            } else {
                if (s->derecha()->color() == ColorNodoArbol::Negro) {
                    s->izquierda()->color(ColorNodoArbol::Negro);
                    s->color(ColorNodoArbol::Rojo);
                    rotar_derecha(s);
                    s = x->padre()->derecha();
                }

                s->color(x->padre()->color());
                x->padre()->color(ColorNodoArbol::Negro);
                s->derecha()->color(ColorNodoArbol::Negro);
                rotar_izquierda(x->padre());
                x = raiz;
            }
        } else {
            s = x->padre()->izquierda();

            if (s->color() == ColorNodoArbol::Rojo) {
                s->color(ColorNodoArbol::Negro);
                x->padre()->color(ColorNodoArbol::Rojo);
                rotar_derecha(x->padre());
                s = x->padre()->izquierda();
            }

            if (s->derecha()->color() == ColorNodoArbol::Negro && s->derecha()->color() == ColorNodoArbol::Negro) {
                s->color(ColorNodoArbol::Rojo);
                x = x->padre();
            } else {
                if (s->izquierda()->color() == ColorNodoArbol::Negro) {
                    s->derecha()->color(ColorNodoArbol::Negro);
                    s->color(ColorNodoArbol::Rojo);
                    rotar_izquierda(s);
                    s = x->padre()->izquierda();
                }

                s->color(x->padre()->color());
                x->padre()->color(ColorNodoArbol::Negro);
                s->izquierda()->color(ColorNodoArbol::Negro);
                rotar_derecha(x->padre());
                x = raiz;
            }
        }
    }

    x->color(ColorNodoArbol::Negro);
}

inline void ArbolRojoNegro::rotar_derecha(NodoArbol* x) {
    NodoArbol* y = x->izquierda();
    x->izquierda(y->derecha());

    if (y->derecha() != nodo_nulo) {
        y->derecha()->padre(x);
    }

    y->padre(x->padre());

    if (x->padre() == nodo_nulo) {
        this->raiz = y;
    } else if (x == x->padre()->derecha()) {
        x->padre()->derecha(y);
    } else {
        x->padre()->izquierda(y);
    }

    y->derecha(x);
    x->padre(y);
}

inline void ArbolRojoNegro::rotar_izquierda(NodoArbol* x) {
    NodoArbol* y = x->derecha();
    x->derecha(y->izquierda());

    if (y->izquierda() != nodo_nulo) {
        y->izquierda()->padre(x);
    }

    y->padre(x->padre());

    if (x->padre() == nodo_nulo) {
        this->raiz = y;
    } else if (x == x->padre()->izquierda()) {
        x->padre()->izquierda(y);
    } else {
        x->padre()->derecha(y);
    }

    y->izquierda(x);
    x->padre(y);
}

inline NodoArbol* ArbolRojoNegro::minimo(NodoArbol* nodo) {
    while (nodo->izquierda() != nodo_nulo) {
        nodo = nodo->izquierda();
    }

    return nodo;
}

inline NodoArbol* ArbolRojoNegro::maximo(NodoArbol* nodo) {
    while (nodo->derecha() != nodo_nulo) {
        nodo = nodo->derecha();
    }

    return nodo;
}

inline NodoArbol* ArbolRojoNegro::sucesor(NodoArbol* nodo) {
	if (nodo == nodo_nulo || nodo->izquierda() == nodo_nulo) return nodo;
	else return sucesor(raiz->izquierda());
}

inline void ArbolRojoNegro::intercambiar(NodoArbol* u, NodoArbol* v) {
	if (u->padre() == nodo_nulo) {
		raiz = v;
	} else if (u == u->padre()->izquierda()) {
		u->padre()->izquierda(v);
	} else {
		u->padre()->derecha(v);
	}

	v->padre(u->padre());
}
