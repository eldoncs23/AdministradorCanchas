/*
	Universidad Nacional de Costa Rica
	Programación 1 - Johnny Flores Araya
	Proyecto: Administrador de Canchas Deportivas
	Estudiantes:
	- Carlos Brenes Lopez
	- Eldon Caldwell Salazar 


	(2026)
*/
#include "Menu.h"
int main() {
	
	Menu* menu = new Menu;
	menu->iniciar();	
	delete menu;

    return 0;
}