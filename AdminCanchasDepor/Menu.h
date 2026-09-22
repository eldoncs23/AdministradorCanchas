#pragma once
#ifndef MENU_H
#define MENU_H
#include "Espera.h"
#include "Cliente.h"
#include "Reserva.h"
#include "Cancha.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>

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
	void iniciar();
};
#endif