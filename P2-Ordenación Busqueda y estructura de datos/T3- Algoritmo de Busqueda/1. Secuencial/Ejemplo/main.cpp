#include <iostream>
#include "busqueda.cpp"
int main() {
    std::cout<<"Lista"<<std::endl;
     std::list<int> miLista = {1, 2, 9, 3, 1, 4, 5,8};

     for (auto it = miLista.begin(); it != miLista.end(); ++it) {
    std::cout << *it << " ";
  }
   std::cout << std::endl;
    int elementoBuscado;
    std::cout<<"Ingrese el elemento a buscar"<<std::endl;
    std::cin>>elementoBuscado;
    auto resultado = busquedaSecuencial(miLista, elementoBuscado);
    // Verificar si se encontró el elemento
    if (resultado != miLista.end()) {
        std::cout << "Elemento encontrado en la lista." << std::endl;
    } else {
        std::cout << "Elemento no encontrado en la lista." << std::endl;
    }
    return 0;
}
