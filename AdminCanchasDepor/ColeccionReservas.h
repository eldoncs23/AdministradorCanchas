#ifndef COLECCIONRESERVAS_H
#define COLECCIONRESERVAS_H
#include "Reserva.h"
#include <iostream>
#include <string>

using namespace std;

class ColeccionReservas{
private:
	Reserva** vec;
	int cant;
	int max;
public:
	ColeccionReservas(int capacidad = 120);// el enunciado dice que la capacidad es 120, pero se puede cambiar
	~ColeccionReservas();
	bool registrarReserva(Cliente* cliente, Cancha* cancha, int franjaInicio, int cantidadFranjas);
	Reserva* buscarReserva(int numeroReserva)const;
	bool cancelarReserva(int numeroReserva);

	void mostrarTodasReservas() const;
	void mostrarReservasPorCliente(string identificacion) const;
	void mostrarReservasPorCancha(string codigoCancha) const;

	int getCant()const;
	int getMax()const;
	Reserva* getReservaPorIndice(int indice)const;
	int contarReservasActivasPorCancha(string codigoCancha) const;
	int contarReservasActivasPorCliente(string identificacion) const;

};
#endif

