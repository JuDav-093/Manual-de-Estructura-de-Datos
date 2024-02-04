#include <iostream>
#include "Fecha.h"

int main() {
    // Crear una fecha inicial (por ejemplo, 1 de enero de 2022)
    Fecha fechaInicial(1, 1, 2022);

    // Imprimir el mes de la fecha inicial
    std::cout << "Mes de la fecha inicial: " << fechaInicial.obtenerMes() << std::endl;

    // Incrementar la fecha inicial en 10 días
    Fecha fechaIncrementada = fechaInicial.incrementar(10);
    std::cout << "Fecha incrementada en 10 días: " << fechaIncrementada.obtenerMes() << std::endl;

    // Crear una fecha final (por ejemplo, 15 de enero de 2022)
    Fecha fechaFinal(15, 1, 2022);

    // Calcular la distancia en días entre la fecha inicial y la fecha final
    int distanciaDias = fechaInicial.distancia(fechaFinal);
    std::cout << "Distancia en días entre las fechas: " << distanciaDias << " días" << std::endl;

    return 0;
}
