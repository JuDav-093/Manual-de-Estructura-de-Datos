#include "Fecha.h"

Fecha::Fecha(int d, int m, int a) {
    dia = d;
    mes = m;
    anio = a;
}

Fecha Fecha::incrementar(int numDias) {
    dia += numDias;
    if (dia > diasEnMes(mes, anio)) {
        dia -= diasEnMes(mes, anio);
        mes++;
        if (mes > 12) {
            mes = 1;
            anio++;
        }
    }
    return Fecha(dia, mes, anio);
}

int Fecha::distancia(Fecha fin) {
    int diasInicio = diasDesde1900(dia, mes, anio);
    int diasFin = diasDesde1900(fin.dia, fin.mes, fin.anio);
    return diasFin - diasInicio;
}

int Fecha::obtenerMes() {
    return mes;
}

int Fecha::diasEnMes(int m, int a) {
    if (m == 2) {
        if (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0)) {
            return 29;
        } else {
            return 28;
        }
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    } else {
        return 31;
    }
}

int Fecha::diasDesde1900(int d, int m, int a) {
    int dias = 0;
    for (int i = 1900; i < a; i++) {
        if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
            dias += 366;
        } else {
            dias += 365;
        }
    }
    for (int i = 1; i < m; i++) {
        dias += diasEnMes(i, a);
    }
    dias += d - 1;
    return dias;
}