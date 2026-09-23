#ifndef GESTORREPORTES_H
#define GESTORREPORTES_H
#include "ColeccionReservas.h"
#include "ColeccionCanchas.h"
#include "ColeccionClientes.h"
#include <iostream>
#include <string>

using namespace std;

class Reportes{
public:
    
    //estadisticas
	static void clienteConMasReservasActivas(const ColeccionClientes& clientes, const ColeccionReservas& reservas);
	static void canchaConMasReservasActivas(const ColeccionCanchas& coleccionCanchas, const ColeccionReservas& coleccionReservas);
	static void ingresoTotalReservasActivas(const ColeccionReservas& reservas);
	static void porcentajeOcupacionPorCancha(const ColeccionCanchas& canchas, const ColeccionReservas& reservas);
	static void horasMayorYMenorDemanda(const ColeccionReservas& reservas, int totalFranjasDia = 24);
};
#endif

