#ifndef VALIDACION_H
#define VALIDACION_H

#include <iostream>
#include <string>

class Validacion {
public:
    char* ingresoNumerico(const char* msj);
    char* ingresoDecimal(const char* msj);
    std::string ingresoAlfabetico(const char* msj);

private:
    void backSpace(char* datos, int& i);
};

#endif // VALIDACION_H
