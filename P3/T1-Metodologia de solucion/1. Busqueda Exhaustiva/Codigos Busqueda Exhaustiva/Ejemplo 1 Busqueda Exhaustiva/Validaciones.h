#if !defined(Validaciones_h)
#define Validaciones_h

#include <string>
using namespace std;

class Validaciones
{
public:

	int validarEnteros();
	double validarDoubles();
	int validarEnterosMonto();
	int validarEnterosCuotas();
	int LongitudCadena(const std::string& cedula);
	char* validarStrings();
	bool verificarLongitud(std::string &p);
	char* validarEnterosCedula();
	bool esCedulaVacia(std::string &cedula);
	bool validateName(const std::string &name);
	bool isNamePatternValid(const std::string &name);
	int* splitNumber(const std::string& number);
	bool verificacion1(const std::string& numCedula);
	bool verificacion2(const std::string& numCedula);
	bool verificacion3(const std::string& numCedula);
	bool verificacionCedula(std::string &numCedula);
	int validarDia(int mes);
	Validaciones();
	~Validaciones();

private:

};

#endif