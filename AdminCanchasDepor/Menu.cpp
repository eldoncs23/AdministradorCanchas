#include "Menu.h"

Menu::Menu() {
	coleccionCanchas = new ColeccionCanchas(10);
	coleccionClientes = new ColeccionClientes(100);
	coleccionReservas = new ColeccionReservas(120);
	coleccionEspera = new ColeccionEspera();
}
Menu::~Menu() {
	delete coleccionCanchas;
	delete coleccionClientes;
	delete coleccionReservas;
	delete coleccionEspera;
}

void Menu::iniciar() {
	bool continuar = true;
	do {
		continuar = this->mostrarMenuPrincipal();
	} while (continuar);
}
bool Menu::mostrarMenuPrincipal() {
    system("cls");
    int opcion = 0;

    cout << "\n==============================================" << endl;
    cout << "  SISTEMA DE GESTION DE CANCHAS DEPORTIVAS" << endl;
    cout << "==============================================" << endl;
    cout << "1. Gestion de Canchas" << endl;
    cout << "2. Gestion de Clientes" << endl;
    cout << "3. Gestion de Reservas" << endl;
    cout << "4. Lista de Espera" << endl;
    cout << "5. Reportes y Estadisticas" << endl;
    cout << "6. Salir" << endl;
    cout << "==============================================" << endl;
    cout << "Digite una opcion (1-6): ";
    cin >> opcion;

    while (cin.fail() || opcion < 1 || opcion > 6) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Opcion invalida. Digite un numero entre 1 y 6: ";
        cin >> opcion;
    }

    switch (opcion) {
    case 1:
        menuCanchas();
        break;
    case 2:
        menuClientes();
        break;
    case 3:
        menuReservas();
        break;
    case 4:
        menuEsperas();
        break;
    case 5:
        menuReportes();
        break;
    case 6:
        cout << "\nHa salido del programa correctamente." << endl;
        system("pause");
        return false;
    }

    return true;
}

// submenus
//-------------------------------------------------------------------
void Menu::menuCanchas() {
    system("cls");
    cout << "==============================================" << endl;
    cout << "          GESTION DE CANCHAS" << endl;
    cout << "==============================================" << endl;
    cout << "1. Mostrar todas las canchas" << endl;
    cout << "2. Volver al menu principal" << endl;
    cout << "Digite una opcion: ";
    int op;
    cin >> op;

    if (op == 1) {
        system("cls");
        coleccionCanchas->mostrarCanchas();
        system("pause");
    }
}

void Menu::menuClientes() {
    system("cls");
    cout << "==============================================" << endl;
    cout << "          GESTION DE CLIENTES" << endl;
    cout << "==============================================" << endl;
    cout << "1. Mostrar todos los clientes" << endl;
    cout << "2. Volver al menu principal" << endl;
    cout << "Digite una opcion: ";
    int op;
    cin >> op;

    if (op == 1) {
        system("cls");
        coleccionClientes->mostrarClientes();
        system("pause");
    }
}

void Menu::menuReservas() {
    system("cls");
    cout << "==============================================" << endl;
    cout << "          GESTION DE RESERVAS" << endl;
    cout << "==============================================" << endl;
    cout << "1. Mostrar todas las reservas" << endl;
    cout << "2. Volver al menu principal" << endl;
    cout << "Digite una opcion: ";
    int op;
    cin >> op;

    if (op == 1) {
        system("cls");
        coleccionReservas->mostrarTodasReservas();
        system("pause");
    }
}

void Menu::menuEsperas() {
    system("cls");
    cout << "==============================================" << endl;
    cout << "              LISTA DE ESPERA                 " << endl;
    cout << "==============================================" << endl;
    cout << " ---------------------------------------------" << endl;
    system("pause");
}

void Menu::menuReportes() {
    int opcion = 0;
    do {
        system("cls");
        cout << "==============================================" << endl;
        cout << "        MODULO DE REPORTES Y ESTADISTICAS" << endl;
        cout << "==============================================" << endl;
        cout << "1. Cancha con mayor cantidad de reservas activas" << endl;
        cout << "2. Cliente con mayor cantidad de reservas activas" << endl;
        cout << "3. Ingreso total generado por reservas activas" << endl;
        cout << "4. Porcentaje de ocupacion por cancha" << endl;
        cout << "5. Horas con mayor y menor demanda" << endl;
        cout << "6. Volver al menu principal" << endl;
        cout << "==============================================" << endl;
        cout << "Digite una opcion (1-6): ";
        cin >> opcion;

        while (cin.fail() || opcion < 1 || opcion > 6) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Opcion invalida. Digite entre 1 y 6: ";
            cin >> opcion;
        }

        system("cls");
        switch (opcion) {
        case 1:
            Reportes::canchaConMasReservasActivas(*coleccionCanchas, *coleccionReservas);
            system("pause");
            break;
        case 2:
            Reportes::clienteConMasReservasActivas(*coleccionClientes, *coleccionReservas);
            system("pause");
            break;
        case 3:
            Reportes::ingresoTotalReservasActivas(*coleccionReservas);
            system("pause");
            break;
        case 4:
            Reportes::porcentajeOcupacionPorCancha(*coleccionCanchas, *coleccionReservas);
            system("pause");
            break;
        case 5:
            Reportes::horasMayorYMenorDemanda(*coleccionReservas);
            system("pause");
            break;
        case 6:
            break;
        }
    } while (opcion != 6);
}