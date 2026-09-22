#include "Reserva.h"
Reserva::Reserva() {
    numeroReserva = siguienteNumeroReserva++;
    this->cliente = nullptr;
    this->cancha = nullptr;
    this->franjaInicio = 0;
    this->cantidadFranjas = 0;
	montoTotal = 0.0;
    this->activa = false;
}
Reserva::Reserva(Cliente* cliente, Cancha* cancha, int franjaInicio, int cantidadFranjas) {
    numeroReserva = siguienteNumeroReserva++;
    this->cliente = cliente;
    this->cancha = cancha;
    this->franjaInicio = franjaInicio;
    this->cantidadFranjas = cantidadFranjas;
    this->activa = true;
    if (cancha != nullptr) {
        this->montoTotal = cancha->getPrecioPorHora() * cantidadFranjas;
    }
    else {
        this->montoTotal = 0.0;
    }
}
Reserva::~Reserva() {
    // No es necesario liberar memoria aquí porque los punteros son gestionados por otras clases
	cliente = nullptr; //pero si es recomendable ponerlos en nullptr
    cancha = nullptr;
}
const Cliente* Reserva::getCliente() const {
    return cliente;
}
const Cancha* Reserva::getCancha() const {
    return cancha;
}
//getters
int Reserva::getNumeroReserva() const {
	return numeroReserva;
}
int Reserva::getFranjaInicio() const {
	return franjaInicio;
}
int Reserva::getCantidadFranjas() const {
	return cantidadFranjas;
}
double Reserva::getMontoTotal() const {
	return montoTotal;
}
bool Reserva::isActiva() const {
	return activa;
}

// no hay setters para numeroReserva, cliente y cancha porque son constantes y no deben modificarse después de la creación de la reserva

//metodos
bool Reserva::cancelarReserva() {
	this->activa = false;
	if (cancha != nullptr) {
        int inicio = this->getFranjaInicio();
		int duracion = this->getCantidadFranjas();
        for (int i = inicio; i < inicio + duracion; i++) {
            cancha->liberarFranja(i);
        }
	}
}
void Reserva::mostrar() const {
    cout << "========================================" << endl;
    cout << "RESERVA #" << numeroReserva << " - Estado: " << (activa ? "ACTIVA" : "CANCELADA") << endl;
    cout << "----------------------------------------" << endl;
    if (cliente != nullptr) {
        cout << "Cliente: " << cliente->getNombre() << " (" << cliente->getIdentificacion() << ")" << endl;
    }
    if (cancha != nullptr) {
        cout << "Cancha:  " << cancha->getCodigo() << " [" << cancha->getDeporte() << "]" << endl;
    }
    int horaInicio = 8 + franjaInicio;
    int horaFin = horaInicio + cantidadFranjas;
    cout << "Horario: " << horaInicio << ":00 a " << horaFin << ":00 (" << cantidadFranjas << " hora/s)" << endl;
    cout << "Monto:   Colones" << montoTotal << endl;
    cout << "========================================" << endl;
}