#include "Estudiante.h"
#include <iomanip>

Estudiante::Estudiante(){

}

Estudiante::Estudiante(std::string p_nombre, std::string s_nombre, std::string p_apellido, std::string s_apellido, std::string _ID){
    primer_nombre = p_nombre;
    segundo_nombre = s_nombre;
    primer_apellido = p_apellido;
    segundo_apellido = s_apellido;
    id = _ID;
}

void Estudiante::set_primer_nombre(std::string p_nombre){
    primer_nombre = p_nombre;
}

std::string Estudiante::get_primer_nombre(){
    return primer_nombre;
}

void Estudiante::set_segundo_nombre(std::string s_nombre){
    segundo_nombre = s_nombre;
}

std::string Estudiante::get_segundo_nombre(){
    return segundo_nombre;
}

void Estudiante::set_primer_apellido(std::string p_apellido){
    primer_apellido = p_apellido;
}

std::string Estudiante::get_primer_apellido(){
    return primer_apellido;
}

void Estudiante::set_segundo_apellido(std::string s_apellido){
    segundo_apellido = s_apellido;
}

std::string Estudiante::get_segundo_apellido(){
    return segundo_apellido;
}

void Estudiante::set_id(std::string _id){
    id = _id;
}

std::string Estudiante::get_id(){
    return id;
}

std::string Estudiante::getter_general(int opcion){
    if(opcion == 1){
        get_primer_nombre();
    }
    else if(opcion == 2){
        get_segundo_nombre();
    }
    else if(opcion == 3){
        get_primer_apellido();
    }
    else if(opcion == 4){
        get_segundo_apellido();
    }
    else if(opcion == 5){
        get_id();
    }

}



void Estudiante::to_string(){
    std::cout << std::setw(10) << id.c_str() << "  " <<
    std::setw(20) << primer_nombre.c_str() << "  " <<
    std::setw(20) << segundo_nombre.c_str() << "  " <<
    std::setw(20) << primer_apellido.c_str() << "  " <<
    std::setw(20) << segundo_apellido.c_str() << std::endl;
}
