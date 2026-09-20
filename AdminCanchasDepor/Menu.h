#pragma once
#include "Espera.h"
#include "Clientes.h"
#include "Reservas.h"
#include "Canchas.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>

class Menu {
	Espera* listaCanchas;
	Cliente* listaClientes;
	Reserva* listaReservas;
	int cantC;
	int cantCl;

public:
	// constructor y destructor
	Menu();
	~Menu();
	//setters y getters
	void setCantC(int c);
	void setCantCl(int c);
	void tostring();
	bool mostrarMenu();
	void menuClientes();
	void menuCanchas();
	void menuReservas();
	void menuEspera();
	void menuEstadisticas();
	void iniciar();
};
