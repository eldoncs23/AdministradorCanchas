#include "RegistroEspera.h"

//hay que iinicar la variable estatica
int RegistroEspera::siguienteConsecutivo = 1;

RegistroEspera::RegistroEspera(){
	//constructor por defecto
	numeroConsecutivo = siguienteConsecutivo++;
	cliente = nullptr;
	cancha = nullptr;
	this->posicionFranja = 0;
	estado = 'E'; // por defecto, el estado es "Esperando"
}

RegistroEspera::RegistroEspera(Cliente* cliente, Cancha* cancha, int posicionFranja){
	//constructor con parámetros
	numeroConsecutivo = siguienteConsecutivo++;
	this->cliente = cliente;
	this->cancha = cancha;
	this->posicionFranja = posicionFranja;
	this->estado = 'E'; // por defecto, el estado es "Esperando"
}

RegistroEspera::~RegistroEspera() {
	// Destructor, no destruye los punteros cliente ni cancha
	cliente = nullptr;
	cancha = nullptr;
}

//gets
int RegistroEspera::getNumeroConsecutivo() const{
    return numeroConsecutivo;
}

int RegistroEspera::getPosicionFranja()const {
    return posicionFranja;
}
const Cliente* RegistroEspera::getCliente() const{
    return cliente;
}

const Cancha* RegistroEspera::getCancha() const{
    return cancha;
}
char RegistroEspera::getEstado() const {
	return estado;
}
string RegistroEspera::getEstadoTexto() const {
	switch (estado) {
	case 'E':
		return "ESPERANDO";
	case 'A':
		return "ASIGNADO";
	case 'C':
		return "CANCELADO";
	default:
		return "DESCONOCIDO";
	}
}

//setts

void RegistroEspera::setEstado(char estado) {
    this->estado = estado;
}

void RegistroEspera::mostrar() const {
	cout << "----------------------------------------" << endl;
	cout << " REGISTRO DE ESPERA #" << numeroConsecutivo << endl;
	if (cliente != nullptr) {
		cout << " Cliente: " << cliente->getNombre() << " (" << cliente->getIdentificacion() << ")" << endl;
	}
	if (cancha != nullptr) {
		cout << " Cancha:  " << cancha->getCodigo() << endl;
	}
	int horaInicio = 8 + posicionFranja;
	int horaFin = 9 + posicionFranja;
	cout << " Franja:  " << (horaInicio < 10 ? "0" : "") << horaInicio << ":00 a " << (horaFin < 10 ? "0" : "") << horaFin << ":00 (Franja " << posicionFranja << ")" << endl;
	cout << " Estado:  " << getEstadoTexto() << endl;
}