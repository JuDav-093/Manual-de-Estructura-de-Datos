#include "Mapa.h"

Mapa::Mapa(std::string _traducir, std::string _traduccion) {
	traducir = _traducir;
	traduccion = _traduccion;
}

std::string Mapa::get_traducir() {
	return traducir;
}
std::string Mapa::get_traduccion() {
	return traduccion;
}