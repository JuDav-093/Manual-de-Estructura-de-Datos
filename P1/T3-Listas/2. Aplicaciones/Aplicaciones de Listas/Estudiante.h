#pragma once

#include <iostream>

class Estudiante{
private:
    std::string id;
    std::string primer_nombre;
    std::string segundo_nombre;
    std::string primer_apellido;
    std::string segundo_apellido;
public:
    Estudiante();
    Estudiante(std::string, std::string, std::string, std::string, std::string);
    void set_primer_nombre(std::string);
    std::string get_primer_nombre();
    void set_segundo_nombre(std::string);
    std::string get_segundo_nombre();
    void set_primer_apellido(std::string);
    std::string get_primer_apellido();
    void set_segundo_apellido(std::string);
    std::string get_segundo_apellido();
    void set_id(std::string);
    std::string get_id();
    std::string getter_general(int);
    void to_string();
};
