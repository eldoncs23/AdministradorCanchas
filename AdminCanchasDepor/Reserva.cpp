#include "Reserva.h"

//hay que iinicar la variable estatica
int Reserva::siguienteNumeroReserva = 1;

Reserva::Reserva(){
	numeroReserva = siguienteNumeroReserva++; // Asignar un número de reserva único y luego incrementar el contador
	cliente = nullptr;
	cancha = nullptr;
	franjaInicio = 0;
	cantidadFranjas = 0;
	montoTotal = 0.0;
	activa = false;
}

Reserva::Reserva(Cliente* cliente, Cancha* cancha, int franjaInicial, int cantidadFranjas){
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
	// No se eliminan los punteros cliente y cancha porque no se sabe si fueron creados en otro lugar, para evitar errores de doble liberación de memoria.
	cliente = nullptr;
	cancha = nullptr; // Se establece a nullptr para indicar que ya no se está utilizando
}

//getts
int Reserva::getNumeroReserva() const{
    return numeroReserva;
}
const Cliente* Reserva::getCliente() const {
	return cliente;
}
const Cancha* Reserva::getCancha() const {
	return cancha;
}
int Reserva::getFranjaInicio()const{
    return franjaInicio;
}

int Reserva::getCantidadFranjas()const{
    return cantidadFranjas;
}

double Reserva::getMontoTotal() const {
    return montoTotal;
}

bool Reserva::isActiva()const{
    return activa;
}

// no hay setters para numeroReserva, cliente y cancha porque son constantes y no deben modificarse después de la creación de la reserva
bool Reserva::cancelarReserva() {
	if (activa) { //verifica si la reserva está activa antes de cancelarla
		activa = false;
		return true; // La reserva se canceló exitosamente
	}
	return false; // La reserva ya estaba cancelada
}

void Reserva::mostrar() const {
	cout << "========================================" << endl;
	cout << "RESERVA #" << numeroReserva << " - Estado: " << (activa ? "ACTIVA" : "CANCELADA") << endl;
	cout << "----------------------------------------" << endl;
	if (cliente != nullptr) {
		cout << "Cliente: " << cliente->getNombre() << " (" << cliente->getIdentificacion() << ")" << endl;
	}
	if (cancha != nullptr) {
		cout << "Cancha: " << cancha->getCodigo() << " (" << cancha->getDeporte() << ")" << endl;
	}
	int horaInicio = 8 + franjaInicio; // Suponiendo que la primera franja corresponde a las 8:00 AM
	int horaFin = horaInicio + cantidadFranjas; // Calcular la hora de finalización sumando la cantidad de franjas
	cout << "Horario: " << horaInicio << ":00 - " << horaFin << ":00 (" << cantidadFranjas << " hora/s)" << endl;
	cout << "Monto Total: " << montoTotal << "Colones" << endl;
	cout << "========================================" << endl;
}