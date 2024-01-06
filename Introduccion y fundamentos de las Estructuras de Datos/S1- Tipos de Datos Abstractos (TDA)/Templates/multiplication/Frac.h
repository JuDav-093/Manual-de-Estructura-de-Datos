/*************************
 * Module:  Frac.h
 * Author:  JoseSanmartin, Ruben Benavidez
 * Modified: miercoles, 23 de noviembre de 2023
 * Purpose: Exercise of Overide
 *************************/

 //Iniciamos la creacion de nuestro Template ocnstruyendo la clase Fracc
template <typename T>
class Frac{
    //Se declaran los atributos privados con atributo T
    private:
        T a;
        T b;
    //Declaramos nuestras funciones publicas
    public:
        Frac() : a(0), b(0){}
        void in();
        Frac operator*(const Frac<T> &obj);
        void out();
};
