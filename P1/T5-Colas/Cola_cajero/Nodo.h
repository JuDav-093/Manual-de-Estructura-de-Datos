#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

class Nodo{
private:
    int ID;
    int t_llegada;
    int t_espera;
    int t_no_trabaja;
    int t_servicio;
    int t_salida;
    int t_entre_llegadas;
    Nodo* siguiente;
public:
    Nodo(int ID, int t_llegada, int t_espera, int t_no_trabaja, int t_servicio, int t_salida, int t_entre_llegadas, Nodo* siguiente);
    Nodo* getSiguiente();
    void setSiguiente(Nodo*);

    int get_ID(void);
    int get_t_llegada(void);
    int get_t_espera(void);
    int get_t_no_trabaja(void);
    int get_t_servicio(void);
    int get_t_salida(void);
    int get_t_entre_llegadas(void);

    void setValor(int);
    ~Nodo();
};

#endif // NODO_H_INCLUDED
