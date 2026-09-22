#include "RegistroEspera.h"
int RegistroEspera::siguienteConsecutivo = 1; //inicializar la variable estática para llevar el control del siguiente número consecutivo de espera
//constructor por defecto
RegistroEspera::RegistroEspera(){
	// Constructor por defecto
	this->numeroConsecutivo = numeroConsecutivo++;
	this->Posicionfranja = 0;
	this->estado = 'E';
	this->cliente = nullptr;
	this->cancha = nullptr;
}
RegistroEspera::RegistroEspera(Cliente* cliente, Cancha* cancha, int posicionFranja) : numeroConsecutivo(numeroConsecutivo++), Posicionfranja(posicionFranja), estado('E'), cliente(cliente), cancha(cancha) {
	//constructor con parámetros
}

RegistroEspera::~RegistroEspera() {
	// Destructor, no destruye los punteros cliente ni cancha
}

//gets
int RegistroEspera::getNumeroConsecutivo() const{
    return numeroConsecutivo;
}

int RegistroEspera::getPosicionFranja()const {
    return Posicionfranja;
}

char RegistroEspera::getEstado() const{
    return estado;
}
Cliente* RegistroEspera::getCliente() const{
    return cliente;
}

Cancha* RegistroEspera::getCancha() const{
    return cancha;
}

//setts

void RegistroEspera::setEstado(char estado) {
    this->estado = estado;
}

void RegistroEspera::mostrar() const {
    cout << "Espera #" << numeroEspera
        << " | Cliente: " << (cliente != nullptr ? cliente->getId() : "Sin cliente")
        << " | Cancha: " << (cancha != nullptr ? cancha->getCodigo() : "Sin cancha")
        << " | Franja: " << franja
        << " | Estado: " << estado << endl;
}
