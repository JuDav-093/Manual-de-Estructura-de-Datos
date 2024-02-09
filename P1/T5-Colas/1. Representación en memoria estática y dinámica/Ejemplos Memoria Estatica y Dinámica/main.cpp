#include <iostream>

const int MAX_SIZE = 100;

class StaticQueue {
private:
    int data[MAX_SIZE];
    int frente;
    int final;

public:
    StaticQueue() {
        frente = -1;
        final = -1;
    }

    bool estaVacia() {
        return frente == -1;
    }

    bool estaLlena() {
        return (final + 1) % MAX_SIZE == frente;
    }

    void encolar(int elemento) {
        if (estaLlena()) {
            std::cout << "La cola está llena. No se puede encolar más elementos.\n";
            return;
        }
        if (estaVacia()) {
            frente = 0;
        }
        final = (final + 1) % MAX_SIZE;
        data[final] = elemento;
        std::cout << "Elemento " << elemento << " encolado con éxito.\n";
    }

    void desencolar() {
        if (estaVacia()) {
            std::cout << "La cola está vacía. No se puede desencolar.\n";
            return;
        }
        std::cout << "Desencolando elemento " << data[frente] << ".\n";
        if (frente == final) {
            frente = -1;
            final = -1;
        } else {
            frente = (frente + 1) % MAX_SIZE;
        }
    }

    void imprimir() {
        if (estaVacia()) {
            std::cout << "La cola está vacía.\n";
            return;
        }
        std::cout << "Contenido de la cola estática: ";
        int indice = frente;
        while (indice != final) {
            std::cout << data[indice] << " ";
            indice = (indice + 1) % MAX_SIZE;
        }
        std::cout << data[final] << std::endl;
    }
};

class Nodo {
public:
    int dato;
    Nodo* siguiente;

    Nodo(int d) {
        dato = d;
        siguiente = nullptr;
    }
};

class DynamicQueue {
private:
    Nodo* frente;
    Nodo* final;

public:
    DynamicQueue() {
        frente = nullptr;
        final = nullptr;
    }

    bool estaVacia() {
        return frente == nullptr;
    }

    void encolar(int elemento) {
        Nodo* nuevoNodo = new Nodo(elemento);
        if (estaVacia()) {
            frente = nuevoNodo;
        } else {
            final->siguiente = nuevoNodo;
        }
        final = nuevoNodo;
        std::cout << "Elemento " << elemento << " encolado con éxito.\n";
    }

    void desencolar() {
        if (estaVacia()) {
            std::cout << "La cola está vacía. No se puede desencolar.\n";
            return;
        }
        Nodo* temp = frente;
        frente = frente->siguiente;
        std::cout << "Desencolando elemento " << temp->dato << ".\n";
        delete temp;
        if (frente == nullptr) {
            final = nullptr;
        }
    }

    void imprimir() {
        if (estaVacia()) {
            std::cout << "La cola está vacía.\n";
            return;
        }
        std::cout << "Contenido de la cola dinámica: ";
        Nodo* actual = frente;
        while (actual != nullptr) {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }
};

int main() {
    int opcion;
    StaticQueue cola_estatica;
    DynamicQueue cola_dinamica;

    do {
        std::cout << "\nSeleccione una opción:\n";
        std::cout << "1. Utilizar cola estática\n";
        std::cout << "2. Utilizar cola dinámica\n";
        std::cout << "3. Salir\n";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int sub_opcion;
                do {
                    std::cout << "\nSeleccione una operación:\n";
                    std::cout << "1. Encolar elemento\n";
                    std::cout << "2. Desencolar elemento\n";
                    std::cout << "3. Imprimir cola\n";
                    std::cout << "4. Regresar al menú principal\n";
                    std::cin >> sub_opcion;

                    switch (sub_opcion) {
                        case 1: {
                            int elemento;
                            std::cout << "Ingrese el elemento a encolar: ";
                            std::cin >> elemento;
                            cola_estatica.encolar(elemento);
                            break;
                        }
                        case 2:
                            cola_estatica.desencolar();
                            break;
                        case 3:
                            cola_estatica.imprimir();
                            break;
                        case 4:
                            std::cout << "Regresando al menú principal.\n";
                            break;
                        default:
                            std::cout << "Opción inválida. Por favor, seleccione una opción válida.\n";
                            break;
                    }
                } while (sub_opcion != 4);
                break;
            }
            case 2: {
                int sub_opcion;
                do {
                    std::cout << "\nSeleccione una operación:\n";
                    std::cout << "1. Encolar elemento\n";
                    std::cout << "2. Desencolar elemento\n";
                    std::cout << "3. Imprimir cola\n";
                    std::cout << "4. Regresar al menú principal\n";
                    std::cin >> sub_opcion;

                    switch (sub_opcion) {
                        case 1: {
                            int elemento;
                            std::cout << "Ingrese el elemento a encolar: ";
                            std::cin >> elemento;
                            cola_dinamica.encolar(elemento);
                            break;
                        }
                        case 2:
                            cola_dinamica.desencolar();
                            break;
                        case 3:
                            cola_dinamica.imprimir();
                            break;
                        case 4:
                            std::cout << "Regresando al menú principal.\n";
                            break;
                        default:
                            std::cout << "Opción inválida. Por favor, seleccione una opción válida.\n";
                            break;
                    }
                } while (sub_opcion != 4);
                break;
            }
            case 3:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción inválida. Por favor, seleccione una opción válida.\n";
                break;
        }
    } while (opcion != 3);

    return 0;
}
