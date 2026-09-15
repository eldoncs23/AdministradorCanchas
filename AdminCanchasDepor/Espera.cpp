#include "Espera.h"
#include "Clientes.h"
#include "Canchas.h"
#include <iostream>
int Espera::contadorSecuencia = 1; //inicializar el contador de secuencia para generar IDs de espera únicos
//constructor por defecto
Espera::Espera() : numeroEspera(contadorSecuencia++), franja(0), estado("esperando"), cliente(nullptr), cancha(nullptr) {
	// Constructor por defecto
	// cliente y cancha se inicializan como punteros nulos
	// no se puede usar this->numeroEspera = numeroEspera; porque numeroEspera es constante y se asigna en el constructor
}
Espera::Espera(Cliente* c, Cancha* ca, int franja, string estado): numeroEspera(contadorSecuencia++),
franja(franja), estado(estado), cliente(c), cancha(ca) {
	//constructor con parámetros
}

Espera::~Espera() {
	// Destructor, no destruye los punteros cliente ni cancha
}

//gets
int Espera::getNumeroEspera() const{
    return numeroEspera;
}

int Espera::getFranja()const {
    return franja;
}

string Espera::getEstado() const{
    return estado;
}
Cliente* Espera::getCliente() const{
    return cliente;
}

Cancha* Espera::getCancha() const{
    return cancha;
}

//setts

void Espera::setFranja(int franja) {
    this->franja = franja;
}

void Espera::setEstado(string estado) {
    this->estado = estado;
}

void Espera::registrar(Cliente* c, Cancha* ca, int f) {
    this->cliente = c;
    this->cancha = ca;
    this->franja = f;
    this->estado = "esperando";
}

void Espera::mostrar() const {
    cout << "Espera #" << numeroEspera
        << " | Cliente: " << (cliente != nullptr ? cliente->getId() : "Sin cliente")
        << " | Cancha: " << (cancha != nullptr ? cancha->getCodigo() : "Sin cancha")
        << " | Franja: " << franja
        << " | Estado: " << estado << endl;
}
