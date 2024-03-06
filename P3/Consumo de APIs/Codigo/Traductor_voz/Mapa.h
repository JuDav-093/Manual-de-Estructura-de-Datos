#pragma once

#include <iostream>

class Mapa {
	public:
		Mapa(std::string , std::string);
		std::string get_traducir();
		std::string get_traduccion();
	protected:
	private:
		std::string traducir;
		std::string traduccion;
		
};