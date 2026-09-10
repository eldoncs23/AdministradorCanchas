#include "Menu.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include "Espera.h"
#include "Clientes.h"
#include "Canchas.h"
#include "Reservas.h"
using namespace std;
class App {

private:
	Espera* listaCanchas;
	Cliente* listaClientes;
	Reserva* listaReservas;
	int cantC;
	int cantCl;
public:
	App()
	{
		// Constructor
		listaCanchas = new Espera();
		listaClientes = new Cliente();
		listaReservas = new Reserva();
		cantC = 0;
		cantCl = 0;
	}
	void setCantC(int c) {//el set de CantC
		cantC = c;
	}
	void setCantCl(int c) {//el set de CantCl
		cantCl = c;
	}

	void toString() {
		cout << "Cantidad de Canchas: " << cantC << endl;
		cout << "Cantidad de Clientes: " << cantCl << endl;
	}

	bool menu() {
		system("cls");
		int cantCanchas = 0;
		int opcion = 0;

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

		while (opcion > 6 || opcion < 1) {
			cout << "Ingrese una opción válida: ";
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
			while (cantCanchas > 3 || i < cantCanchas) {
				cout << "Ingrese una opción válida: ";
				cin >> opcion;
			}
			break;
		case 2:
			// Agregar Clientes
			system("cls");
			cout << endl << endl;
			cout << "  -------------------------------------------------------" << endl;
			cout << "    Agregar Clientes" << endl;
			cout << "  -------------------------------------------------------" << endl;
			break;
		case 3:

			break;

		case 4:


			break;

		case 5:


			break;
		case 6: {
			cout << "Ha salido del programa correctamente!!!" << endl;
			system("pause");
			return false;
		}break;

		}

		return true;
	}
//Prueba-Test 

};