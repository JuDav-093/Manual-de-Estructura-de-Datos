/***********************************************************************
 UFA - ESPE
 * Module:  Nodo.h
 * Author:  Joan Cobeña, Edison Verdesoto
 * Modified: jueves, 7 de diciembre de 2023 01:11:27 p. m.
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Nodo_h)
#define __Class_Diagram_1_Nodo_h

template <typename T>
class Nodo
{
public:
    Nodo<T>(T _valor, Nodo* _siguiente, Nodo* _anterior);
    Nodo<T>(T _valor, Nodo* _siguiente);
    Nodo<T>();
    ~Nodo<T>();
    T get_valor();
    void set_valor(T new_valor);
    Nodo<T>* get_siguiente();
    void set_siguiente(Nodo<T>* new_siguiente);
    Nodo<T>* get_anterior();
    void set_anterior(Nodo<T>* new_anterior);

protected:
private:
   T valor;
   Nodo<T>* siguiente;
   Nodo<T>* anterior;

};

#endif
