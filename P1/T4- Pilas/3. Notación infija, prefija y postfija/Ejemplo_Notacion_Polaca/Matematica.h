/***********************************************************************
 * Module:  Matematica.h
 * Author:  david
 * Modified: viernes, 30 de junio de 2023 12:28:28
 * Purpose: Declaration of the class Matematica
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Matematica_h)
#define __Class_Diagram_1_Matematica_h

class Matematica
{
public:
	int redondear(double numero);
	bool isNaN(double valor);
    double abs(double valor);
    double normalizaRadian(double radian);
    double sin(double operando);
    double cos(double operando);
    double tan(double operando);
    double log(double operando);
    double pow(double base, double exponente);
    double sqrt(double operando);
    double getPI();
    double getEPSILON();
    Matematica();
    ~Matematica();

private:
    double EPSILON;
    double PI;
};

#endif
