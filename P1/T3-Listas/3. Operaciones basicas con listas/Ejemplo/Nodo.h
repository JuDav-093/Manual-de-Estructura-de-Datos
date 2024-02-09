#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

class Nodo
{
public:
   int get_valor();
   void set_valor(int new_valor);
   Nodo* get_siguiente();
   void set_siguiente(Nodo* new_siguiente);
   Nodo();
   Nodo(int _valor, Nodo* _siguiente);
   ~Nodo();

protected:
private:
   int valor;
   Nodo* siguiente;

};

#endif // NODO_H_INCLUDED
