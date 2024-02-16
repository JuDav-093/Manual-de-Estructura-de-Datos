/***********************************************************************
 * Module:  Matematica.cpp
 * Author:  david
 * Modified: viernes, 30 de junio de 2023 12:28:28
 * Purpose: Implementation of the class Matematica
 ***********************************************************************/

#include "Matematica.h"

////////////////////////////////////////////////////////////////////////
// Name:       Matematica::Matematica()
// Purpose:    Implementation of Matematica::Matematica()
// Return:
////////////////////////////////////////////////////////////////////////

Matematica::Matematica()
{
    this->EPSILON = 1e-10;
    this->PI = 3.14159265358979323846;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matematica::~Matematica()
// Purpose:    Implementation of Matematica::~Matematica()
// Return:
////////////////////////////////////////////////////////////////////////

Matematica::~Matematica()
{
    // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Matematica::getPI()
// Purpose:    Implementation of Matematica::getPI()
// Return:	   double
////////////////////////////////////////////////////////////////////////

double Matematica::getPI()
{
    return PI;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matematica::getEPSILON()
// Purpose:    Implementation of Matematica::getEPSILON()
// Return:     double
////////////////////////////////////////////////////////////////////////

double Matematica::getEPSILON()
{
    return EPSILON;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matematica::isNaN()
// Purpose:    Implementation of Matematica::isNaN()
// Return:     bool
////////////////////////////////////////////////////////////////////////


bool Matematica::isNaN(double valor) {
    // Verificar si el valor cumple las propiedades de un NaN
    return valor != valor;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matematica::abs(double valor)
// Purpose:    Implementation of Matematica::abs()
// Parameters:
// - valor
// Return:     double
////////////////////////////////////////////////////////////////////////

double Matematica::abs(double valor)
{
    if (valor < 0.0)
    {
        return -valor;
    }
    return valor;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matematica::normalizaRadian(double radian)
// Purpose:    Implementation of normalizaRadian::normalizaRadian()
// Parameters:
// - radian
// Return:     double
////////////////////////////////////////////////////////////////////////

double Matematica::normalizaRadian(double radian){
	while (radian <= -2 * PI) {
        radian += 2 * PI;
    }

    while (radian > 2 * PI) {
        radian -= 2 * PI;
    }

    return radian;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matematica::redondear(double numero)
// Purpose:    Implementation of normalizaRadian::redondear()
// Parameters:
// - numero
// Return:     double
////////////////////////////////////////////////////////////////////////

int Matematica::redondear(double numero)
{
    int numeroEntero = (int)numero;
    double diferencia = numero - numeroEntero;

    if (abs(diferencia) <= 0.5)
    {
        return numeroEntero;
    }
    else
    {
    	if (numeroEntero > 0) {
    		return numeroEntero + 1;
		} else {
			return numeroEntero - 1;
		}
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       Matematica::sin(double operando)
// Purpose:    Implementation of Matematica::sin()
// Parameters:
// - operando
// Return:     double
////////////////////////////////////////////////////////////////////////

double Matematica::sin(double operando)
{
	operando = normalizaRadian(operando);

    double resultado = 0.0;
    double termino = operando;
    double contador = 1.0;

    while (abs(termino) > EPSILON)
    {
        resultado += termino;
        termino *= -(operando * operando) / ((contador + 1) * (contador + 2));
        contador += 2;
    }

    if ((abs(resultado - redondear(resultado)) < EPSILON * 1e+2)) {
    	return redondear(resultado);
	}

    return resultado;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matematica::cos(double operando)
// Purpose:    Implementation of Matematica::cos()
// Parameters:
// - operando
// Return:     double
////////////////////////////////////////////////////////////////////////

double Matematica::cos(double operando)
{
	operando = normalizaRadian(operando);

    double resultado = 0.0;
    double termino = 1.0;
    double contador = 0.0;

    while (abs(termino) > EPSILON)
    {
        resultado += termino;
        termino *= -(operando * operando) / ((contador + 1) * (contador + 2));
        contador += 2;
    }

    if ((abs(resultado - redondear(resultado)) < EPSILON * 1e+2)) {
    	return redondear(resultado);
	}

    return resultado;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matematica::tan(double operando)
// Purpose:    Implementation of Matematica::tan()
// Parameters:
// - operando
// Return:     double
////////////////////////////////////////////////////////////////////////

double Matematica::tan(double operando)
{
	operando = normalizaRadian(operando);
    return sin(operando) / cos(operando);
}

////////////////////////////////////////////////////////////////////////
// Name:       Matematica::log(double operando)
// Purpose:    Implementation of Matematica::log()
// Parameters:
// - operando
// Return:     double
////////////////////////////////////////////////////////////////////////

double Matematica::log(double operando) {
	if (operando <= 0) {
        // Manejo de casos especiales: logaritmo indefinido o no válido
        return 0.0/0.0; // O devuelve NaN, dependiendo de tus necesidades
    }

    double resultado = 0.0;
    double termino = (operando - 1) / (operando + 1);
    double exponente = termino;
    int n = 1;

    // Calcula el logaritmo utilizando la serie de Taylor del logaritmo natural
    while (abs(exponente) > EPSILON) {
        resultado += exponente;
        n += 2;
        termino *= (operando - 1) * (operando - 1) / (operando + 1) / (operando + 1);
        exponente = termino / n;
    }

    return 2 * resultado;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matematica::pow(double base, double exponente)
// Purpose:    Implementation of Matematica::pow()
// Parameters:
// - base
// - exponente
// Return:     double
////////////////////////////////////////////////////////////////////////

double Matematica::pow(double base, double exponente)
{
	if (exponente == 0) {
		if (base == 0) {
			return 0.0/0.0;
		}
		return 1;
	}

	if (base == 0) {
		return 0;
	}

    double resultado = 1;
    double termino = 1;
    int numeroIteraciones = 100;
    double logBase = log(base);
    for (int i = 1; i <= numeroIteraciones; i++) {
        termino *= exponente * logBase / i;
        resultado += termino;
    }
    return resultado;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matematica::sqrt(int operando)
// Purpose:    Implementation of Matematica::sqrt()
// Parameters:
// - operando
// Return:     double
////////////////////////////////////////////////////////////////////////

double Matematica::sqrt(double operando)
{
    if (operando < 0)
    {
        return 0.0 / 0.0; // Retorna NaN para raíces negativas
    }

    double resultado = operando;
    double anterior = 0.0;

    while (abs(resultado - anterior) > EPSILON)
    {
        anterior = resultado;
        resultado = 0.5 * (resultado + operando / resultado);
    }

    return resultado;
}
