#include "Menu.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
using namespace std;
Menu::Menu() {
	listaCanchas = new Espera();
	listaClientes = new Cliente();
	listaReservas = new Reserva();
	cantC = 0;
	cantCl = 0;
}
Menu::~Menu() {
	delete listaCanchas;
	delete listaClientes;
	delete listaReservas;
}


void Menu::setCantC(int c) {
	cantC = c;
}
void Menu::setCantCl(int c) {
	cantCl = c;
}
void Menu::tostring() {
	cout << "Cantidad de Canchas: " << cantC << endl;
	cout << "Cantidad de Clientes: " << cantCl << endl;
}
void Menu::iniciar() {
	bool continuar = true;
	do {
		continuar = this->mostrarMenu();
	} while (continuar);
}
bool Menu::mostrarMenu() {
	system("cls");
	int opcion =0;

	//----------------------------------------------------------------------------------------------------
	cout << endl << endl;
	cout << "==============================" << endl;
	cout << "      MENU PRINCIPAL" << endl;
	cout << "==============================" << endl;
	cout << "1. Gestion de canchas" << endl;
	cout << "2. Gestion de reservas" << endl;
	cout << "3. Gestion de esperas" << endl;
	cout << "4. Gestion y listado de espera" << endl;
	cout << "5. Reportes y Estadisticas" << endl;
	cout << "6. Salir" << endl;
	cout << "==============================" << endl;
	cout << "Digite una opcion: ";
	cin >> opcion;
	//validar que la opcion sea correcta
	while (opcion < 1 || opcion > 6) {
		cout << "Ingrese una opción válida (1-6): ";
		cin >> opcion;
	}

	switch (opcion) {
	case 1:
		// Agregar Cancha
		system("cls");
		cout << endl << endl;
		cout << "  -------------------------------------------------------" << endl;
		cout << "    Agregar Cancha" << endl;
		cout << "  -------------------------------------------------------" << endl;
		system ("pause");
		break;
	case 2:
		// Agregar Clientes
		system("cls");
		cout << endl << endl;
		cout << "  -------------------------------------------------------" << endl;
		cout << "    Gestion de reservas" << endl;
		cout << "  -------------------------------------------------------" << endl;
		system("pause");
		break;
	case 3:
		cout << endl << endl;
		cout << "  -------------------------------------------------------" << endl;
		cout << "    Gestion de esperas" << endl;
		cout << "  -------------------------------------------------------" << endl;
		system("pause");
		break;

	case 4:
		cout << endl << endl;
		cout << "  -------------------------------------------------------" << endl;
		cout << "    Gestion de lista de esperas" << endl;
		cout << "  -------------------------------------------------------" << endl;
		system("pause");
		break;

	case 5:
		cout << endl << endl;
		cout << "  -------------------------------------------------------" << endl;
		cout << "    Reportes y Estadisticas" << endl;
		cout << "  -------------------------------------------------------" << endl;
		system("pause");
		break;
	case 6: {
		cout << endl << endl;
		cout << "Ha salido del programa correctamente!!!" << endl;
		system("pause");
		return false;
	}break;

	}

	return true;
}
//Prueba-Test 

	//esto es una prubea de commit1
	//esto es una prubea de draft pr

	//esto es una prueba eldon 2
	//prueba borrador incompleta aun no esta lista para merge
	//prueba3