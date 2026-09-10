#include "Reservas.h"
#include "Canchas.h"
#include "Clientes.h"

Reserva::Reserva() {
    numeroReserva = 0;
    franjaInicial = 0;
    cantidadFranjas = 0;
    monto = 0.0;
    activa = false;
}

Reserva::Reserva(int numeroReserva, int franjaInicial, int cantidadFranjas, float monto, bool activa) {
    this->numeroReserva = numeroReserva;
    this->franjaInicial = franjaInicial;
    this->cantidadFranjas = cantidadFranjas;
    this->monto = monto;
    this->activa = activa;
}

Reserva::~Reserva() {}

int Reserva::getNumeroReserva() {
    return numeroReserva;
}

int Reserva::getFranjaInicial() {
    return franjaInicial;
}

int Reserva::getCantidadFranjas() {
    return cantidadFranjas;
}

float Reserva::getMonto() {
    return monto;
}

bool Reserva::getActiva() {
    return activa;
}

void Reserva::setNumeroReserva(int numeroReserva) {
    this->numeroReserva = numeroReserva;
}

void Reserva::setFranjaInicial(int franjaInicial) {
    this->franjaInicial = franjaInicial;
}

void Reserva::setCantidadFranjas(int cantidadFranjas) {
    this->cantidadFranjas = cantidadFranjas;
}

void Reserva::setMonto(float monto) {
    this->monto = monto;
}

void Reserva::setActiva(bool activa) {
    this->activa = activa;
}

void Reserva::registrar(int num, Cliente* c, Cancha* ca, int fi, int cf) {
    this->numeroReserva = num;
    this->cliente = c;
    this->cancha = ca;
    this->franjaInicial = fi;
    this->cantidadFranjas = cf;
    this->monto = cf * cancha->getPrecioHora();
    this->activa = true;
}

void Reserva::mostrar() {
    cout << "Reserva #" << this->numeroReserva << " | Cliente: " << this->cliente->getId()
        << " | Cancha: " << this->cancha->getCodigo()
        << " | Franjas: " << this->cantidadFranjas
        << " | Monto: " << this->monto
        << " | Estado: " << (this->activa ? "Activa" : "Cancelada") << endl;
}