#ifndef FECHA_H
#define FECHA_H

class Fecha {
    private:
        int dia, mes, anio;
    public:
        Fecha(int d, int m, int a);
        Fecha incrementar(int numDias);
        int distancia(Fecha fin); // cambiar la variable periodo de tiempo.
        int obtenerMes();
    private:
        int diasEnMes(int m, int a);
        int diasDesde1900(int d, int m, int a);
};

#endif