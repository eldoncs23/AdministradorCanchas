/*
	Universidad Nacional de Costa Rica
	Programación 1 - Johny
	Proyecto: Administrador de Canchas Deportivas
	Estudiantes:
	- (charlie ponga su nombre)
	- Eldon Caldwell Salazar 


	(2026)
*/
#pragma once
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include "Menu.h"
using namespace std;

int main() {
	
	App* iniciar = new App;
	bool continuar; 
	do { continuar = iniciar->menu(); } while (continuar);

    return 0;
}