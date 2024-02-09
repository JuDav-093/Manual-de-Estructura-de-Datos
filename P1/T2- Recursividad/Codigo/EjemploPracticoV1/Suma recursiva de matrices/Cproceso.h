#ifndef CPROCESO_H
#define CPROCESO_H
#include <iostream>
using namespace std;

class Cproceso{
    public:

        void sumaRecursivaMatrices( int **, int **, int **, int, int); //arreglo dinamico
		void encerarMatriz(); //arreglo dinamico
		void llenarMatriz(); //arreglo dinamico
		void imprimirMatriz(int**,char*); //arreglo dinamico

        int** getMat1();
		int** getMat2();
		int** getMatR();

		void setMat1(int**);
		void setMat2(int**);
		void setMatR(int**);
        Cproceso(); //Constructor

    private:
        int **mat1,**mat2,**matR; //Uso para funcion por datos randomicos
};
#endif
