#pragma once
#ifndef MENU_H
#define MENU_H
#include "ColeccionCanchas.h"
#include "ColeccionClientes.h"
#include "ColeccionReservas.h"
#include "ColeccionEspera.h"
#include "Reportes.h"

#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Menu {
private:
	ColeccionCanchas* coleccionCanchas;
	ColeccionClientes* coleccionClientes;
	ColeccionReservas* coleccionReservas;
	ColeccionEspera* coleccionEspera;

	void menuCanchas();
	void menuClientes();
	void menuReservas();
	void menuEsperas();
	void menuReportes();

public:
	// constructor y destructor
	Menu();
	~Menu();
	//setters y getters
	void iniciar();
	bool mostrarMenuPrincipal();
};
#endif