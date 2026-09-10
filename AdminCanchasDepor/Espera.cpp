#include "Espera.h"
#include "Clientes.h"
#include "Canchas.h"

#include <iostream>
#include <string>
#include <sstream>

Espera::Espera() {
    numeroEspera = 0;
    franja = 0;
    estado = "";
    cliente = nullptr;
    cancha = nullptr;
}

Espera::Espera(int numeroReserva, int franja, string estado) {
    this->numeroEspera = numeroReserva;
    this->franja = franja;
    this->estado = estado;
    this->cliente = nullptr;
    this->cancha = nullptr;
}

Espera::~Espera() {}

int Espera::getNumeroEspera() {
    return numeroEspera;
}

int Espera::getFranja() {
    return franja;
}

string Espera::getEstado() {
    return estado;
}

void Espera::setNumeroEspera(int numeroEspera) {
    this->numeroEspera = numeroEspera;
}

void Espera::setFranja(int franja) {
    this->franja = franja;
}

void Espera::setEstado(string estado) {
    this->estado = estado;
}

void Espera::registrar(int num, Cliente* c, Cancha* ca, int f) {
    numeroEspera = num;
    cliente = c;
    cancha = ca;
    franja = f;
    estado = "esperando";
}

void Espera::mostrar() {
    std::cout << "Espera #" << numeroEspera << " | Cliente: " << cliente->getId()
        << " | Cancha: " << cancha->getCodigo()
        << " | Franja: " << franja
        << " | Estado: " << estado << std::endl;
}
