//Macros establecidas por defecto.
#ifndef OPERACIONESFRACCION_H_INCLUDED 
#define OPERACIONESFRACCION_H_INCLUDED

#include <iostream>
#include "Fraccion.h" //Linkeo a la clase Fraccion para poder ser usada en esta libreria.

Fraccion calculo(Fraccion& obj1, Fraccion& obj2);    //Paso por referencia, para no consumir memoria y acceder directamente a los datos de las fracciones pasadas como argumentos.
                                                     //Retorna un nuevo objeto de tipo Fraccion.

Fraccion calculo(Fraccion& obj1, Fraccion& obj2) {
    int sum_num = (obj1.getNumerador() * obj2.getDenominador()) + (obj2.getNumerador() * obj1.getDenominador()); 
    int sum_den = obj1.getDenominador() * obj2.getDenominador();
    return Fraccion(sum_num, sum_den); 
}

#endif // OPERACIONESFRACCION_H_INCLUDED
