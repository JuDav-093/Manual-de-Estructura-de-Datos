#include <iostream>
#include "Algoritmos.h"
using namespace std;

int main()
{
    int n;
    std::cout << "Ingrese un valor de n para los ejemplos: ";
    std::cin >> n;

    ejemploTheta1();
    ejemploThetaLog2n(n);
    ejemploThetaN(n);
    ejemploThetaNlog2n(n);
    ejemploThetaN2(n);
    ejemploThetaN2log2n(n);
    ejemploThetaN3(n);
    ejemploTheta2N(n);
    ejemploThetaNFact(n);
    return 0;
}
