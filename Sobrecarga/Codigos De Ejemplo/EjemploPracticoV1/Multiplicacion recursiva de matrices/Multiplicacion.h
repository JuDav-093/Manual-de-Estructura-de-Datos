/***********************************************************************
 * Module:  Multiplicacion.h
 * Author:  VerdesotoDamian
 * Modified: domingo, 26 de noviembre de 2023 23:44:51
 * Purpose: Multiplicación recursiva de matrices
 ***********************************************************************/
#ifndef MULTIPLICACION_H_INCLUDED
#define MULTIPLICACION_H_INCLUDED
using namespace std;

class Cproceso{
    public:

        void multiplicacionRecursivaMatrices( int **, int **, int **, int, int, int); //arreglo dinamico
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

#endif // MULTIPLICACION_H_INCLUDED
