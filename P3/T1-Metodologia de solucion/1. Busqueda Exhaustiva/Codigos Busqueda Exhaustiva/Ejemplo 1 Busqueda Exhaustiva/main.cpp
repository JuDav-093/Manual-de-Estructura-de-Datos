/*

El código utiliza busqueda exhaustiva para encontrar todas las combinaciones posibles de los elementos 
ingresados que sumen el objetivo especificado por el usuario. Comienza con una lista de elementos y 
explora recursivamente todas las posibles combinaciones, considerando cada elemento como parte de la 
combinación actual o no. Cuando la suma de una combinacion es igual al objetivo, se imprime la combinacion 
y se guarda en el archivo de salida. Este proceso se repite hasta que se exploran todas las combinaciones posibles.

*/

#include <iostream>
#include <fstream>
#include "GeneradorCombinaciones.cpp"

using namespace std;

int main() {
	
    ofstream archivoSalida("combinaciones.txt");
    GeneradorCombinaciones::generarCombinaciones(archivoSalida);
    archivoSalida.close();

    return 0;
}
