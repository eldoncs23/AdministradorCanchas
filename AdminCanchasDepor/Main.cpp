/*
	Universidad Nacional de Costa Rica
	Programación 1 - Johny
	Proyecto: Administrador de Canchas Deportivas
	Estudiantes:
	- (charlie ponga su nombre)
	- Eldon Caldwell Salazar 


	(2026)
*/
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include "Menu.h"
using namespace std;

int main() {
	
	Menu* menu = new Menu;
	menu->iniciar();	
	delete menu;

    return 0;
}