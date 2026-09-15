#pragma once
#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H

#include <iostream>
#include <string>
using namespace std;

class Cancha;
class Cliente;
class Reserva;
class Estadisticas{
private:
	static const int CANT_FRANJAS = 12; // Atributo constante para la cantidad de franjas horarias, ya que son 12 franjas de 1 hora cada una
public:
	Estadisticas();
	~Estadisticas();

	//reportes
	void reporteCanchaMasReservada(Cancha* canchas[], int cantCanchas, Reserva* reservas[], int cantReservas)const;
	void reporteClienteMasReservas(Cliente* clientes[], int cantClientes, Reserva* reservas[], int cantReservas)const;
	void reporteIngresoTotal(Reserva* reservas[], int cantReservas)const;
	void reportePorcentajeOcupacion(Cancha* canchas[], int cantCanchas, Reserva* reservas[], int cantReservas)const;
	void reporteHorasExtremas(Reserva* reservas[], int cantReservas)const;

	//menu
	void menuEstadisticas(Cancha* canchas[], int cantCanchas, Cliente* clientes[], int cantClientes, Reserva* reservas[], int cantReservas)const;
};

#endif