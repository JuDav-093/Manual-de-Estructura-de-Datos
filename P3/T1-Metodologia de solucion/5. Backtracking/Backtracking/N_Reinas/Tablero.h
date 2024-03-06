#pragma once

class Tablero {
public:
	Tablero();
	Tablero(int);
	void set_TAM(int);
	int get_TAM();
	void set_piezas_strings(std::string***);
	std::string*** get_piezas_strings();
	void mostrar_tablero();
	bool esta_ocupado(int, int);
	~Tablero();
private:
	int TAM;
	std::string*** piezas_strings;
};