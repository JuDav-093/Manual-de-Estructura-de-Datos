/*

El codigo implementa un algoritmo que realiza una serie de operaciones en funcion del tamaño de 
entrada proporcionado. La metrica del tiempo de ejecucion se evalúa en terminos de la complejidad 
del algoritmo, donde se considera cómo el tiempo de ejecución cambia con respecto al tamaño de 
entrada. En este caso, la cantidad de operaciones realizadas aumenta linealmente con el tamaño de 
entrada, lo que sugiere una complejidad temporal de O(n), donde "n" representa el tamaño de entrada. 
Esta métrica proporciona una idea de cómo el rendimiento del algoritmo puede verse afectado por un 
aumento en el tamaño de los datos de entrada.

*/

#include "ListaSimple.cpp"
#include "Validaciones.cpp"
#include <iostream>
#include <chrono>

using namespace std;

int main() {
	Validaciones validador;
    ListaSimple lista;

    int cantidad;
    cout << "   **** TIEMPO DE EJECUCION DE UN ALGORITMO ***** \n"<<endl;
    cout << "           ** Ordenamiento Burbuja ** \n"<<endl;
    cout << "- Ingresa la cantidad de elementos en la lista: ";
    cantidad = validador.validarEnteros();
    cout << "\n";

    if (cantidad <= 0) {
        cout << "La cantidad de elementos debe ser mayor que 0." << endl;
        return 1;
    }

    cout << ">> Ingresa " << cantidad << " numeros:" << endl;
    for (int i = 0; i < cantidad; i++) {
        int valor;
        valor = validador.validarEnteros();
    	cout << "\n";
        lista.agregarElemento(valor);
    }
    
    auto inicio = std::chrono::high_resolution_clock::now();

    cout << "\nLista original: ";
    lista.mostrarLista();

    lista.ordenarBurbuja();
    
    auto fin = std::chrono::high_resolution_clock::now();

	cout << "Lista ordenada: ";
    lista.mostrarLista();
    
    std::chrono::duration<double> tiempo = fin - inicio;
    std::cout << "\n\n====================================================================\n\n";
    std::cout << "- TIEMPO DE EJECUCION DEL ALGORTIMO: " << std::endl;
    std::cout << "  " << tiempo.count() << " segundos\n" << std::endl;
    std::cout << "======================================================================\n\n";

    return 0;
}

