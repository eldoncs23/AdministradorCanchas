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

    cout << "\n=====================================================" << endl;
    cout << "  SISTEMA DE GESTION DE CANCHAS DEPORTIVAS ZONA ACTIVA " << endl;
    cout << "=======================================================" << endl;
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
    int opcion = 0;
    do {
        system("cls");
        cout << "==============================================" << endl;
        cout << "          GESTION DE CANCHAS" << endl;
        cout << "==============================================" << endl;
        cout << "1. Registrar nueva cancha" << endl;
        cout << "2. Mostrar todas las canchas" << endl;
        cout << "3. Buscar cancha por codigo" << endl;
        cout << "4. Modificar el precio de una cancha" << endl;
        cout << "5. Mostrar disponibilidad de una cancha" << endl;
        cout << "6. Volver al menu principal" << endl;
        cout << "==============================================" << endl;
        cout << "Digite una opcion: ";
        cin >> opcion;

        while (cin.fail() || opcion < 1 || opcion > 6) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Opcion invalida. Digite un numero entre 1 y 6: ";
            cin >> opcion;
        }
        string codigo, deporte;
        float precio;
        switch (opcion) {
        case 1: {
            system("cls");
            cout << "--- Registrar nueva cancha ---" << endl;
            cout << "Digite el codigo de la cancha: ";
            cin >> codigo;
            cout << "Digite el deporte de la cancha: ";
            cin >> deporte;
            cout << "Digite el precio por hora/franja: ";
            cin >> precio;

            if(cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\nFormato invalido. Ingrese solo numeros (ej: 2000)." << endl;
                system("pause");
                break;
            }
            if (coleccionCanchas->agregarCancha(new Cancha(codigo, deporte, precio)))
                cout << "\nCancha registrada correctamente." << endl;
            else
                cout << "\nError al registrar la cancha. Codigo ya existe." << endl;
            system("pause");
            break;
        }
        case 2:
            system("cls");
            cout << "--- Listado de Canchas Registradas ---" << endl;
            coleccionCanchas->mostrarCanchas();
            system("pause");
            break;
        case 3: {
            system("cls");
            cout << "Digite el codigo de la cancha a buscar: ";
            cin >> codigo;
            Cancha* cancha = coleccionCanchas->buscarCancha(codigo);
            if (cancha != nullptr) {
                cout << "\nCancha encontrada." << endl;
                cancha->mostrar();
            }
            else {
                cout << "\nCancha no encontrada." << endl;
            }
            system("pause");
            break;
        }
        case 4:
            system("cls");
            cout << "Digite el codigo de la cancha a modificar: ";
            cin >> codigo;
            cout << "Digite el nuevo precio por hora/franja: ";
            cin >> precio;
            if (coleccionCanchas->modificarPrecio(codigo, precio))
                cout << "\nPrecio de la cancha modificado correctamente." << endl;
            else
                cout << "\nError al modificar el precio. Cancha no encontrada." << endl;
            system("pause");
            break;
        case 5:
            system("cls");
            cout << "Digite el codigo de la cancha: ";
            cin >> codigo;
            coleccionCanchas->mostrarDisponibilidad(codigo);
            system("pause");
            break;
        case 6:
            break; //regresa al menu principal
        }
    } while (opcion != 6);
}

void Menu::menuClientes() {
    int opcion = 0;
    do {
        system("cls");
        cout << "==============================================" << endl;
        cout << "          GESTION DE CLIENTES" << endl;
        cout << "==============================================" << endl;
        cout << "1. Registrar nuevo cliente" << endl;
        cout << "2. Mostrar todos los clientes" << endl;
        cout << "3. Buscar cliente por identificacion" << endl;
        cout << "4. Mostrar reservas de un cliente" << endl;
        cout << "5. Volver al menu principal" << endl;
        cout << "==============================================" << endl;
        cout << "Digite una opcion: ";
        cin >> opcion;

        while (cin.fail() || opcion < 1 || opcion > 5) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Opcion invalida. Digite un numero entre 1 y 5: ";
            cin >> opcion;
        }

        string identificacion, nombre, telefono;

        switch (opcion) {
        case 1:
            system("cls");
            cout << "--- Registrar Nuevo Cliente ---" << endl;
            cout << "Digite la identificacion del cliente: ";
            cin >> identificacion;
            cout << "Digite el nombre del cliente: ";
            cin >> nombre;
            cout << "Digite el telefono del cliente: ";
            cin >> telefono;

            if (coleccionClientes->agregarCliente(new Cliente(identificacion, nombre, telefono)))
                cout << "\nCliente registrado correctamente." << endl;
            else
                cout << "\nError al registrar cliente. Identificacion ya registrada." << endl;
            system("pause");
            break;

        case 2:
            system("cls");
            cout << "--- Listado de Clientes ---" << endl;
            coleccionClientes->mostrarClientes();
            system("pause");
            break;

        case 3: {
            system("cls");
            cout << "Digite la identificacion del cliente a buscar: ";
            cin >> identificacion;
            Cliente* cli = coleccionClientes->buscarCliente(identificacion);
            if (cli != nullptr) {
                cout << "\nCliente encontrado:" << endl;
                cli->mostrar();
            }
            else {
                cout << "\nCliente no encontrado." << endl;
            }
            system("pause");
            break;
        }

        case 4:
            system("cls");
            cout << "Digite la identificacion del cliente: ";
            cin >> identificacion;
            coleccionReservas->mostrarReservasPorCliente(identificacion);
            system("pause");
            break;

        case 5:
            break;
        }
    } while (opcion != 5);
}

void Menu::menuReservas() {
    int opcion = 0;
    do {
        system("cls");
        cout << "==============================================" << endl;
        cout << "          GESTION DE RESERVAS" << endl;
        cout << "==============================================" << endl;
        cout << "1. Registrar reserva" << endl;
        cout << "2. Mostrar todas las reservas" << endl;
        cout << "3. Cambio de disponibilidad de franja" << endl;
        cout << "4. Buscar reserva por numero consecutivo" << endl;
        cout << "5. Mostrar reservas asociadas a una cancha" << endl;
        cout << "6. Cancelar reserva" << endl;
        cout << "7. Volver al menu principal" << endl;
        cout << "==============================================" << endl;
        cout << "Digite una opcion: ";
        cin >> opcion;

        while (cin.fail() || opcion < 1 || opcion > 7) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Opcion invalida. Digite un numero entre 1 y 7: ";
            cin >> opcion;
        }

        string identificacion, codigo;
        char estado;
        int franjaInicio, cantidadFranjas, numeroReserva;

        switch (opcion) {
        case 1: {
            system("cls");
            cout << "--- REGISTRO DE RESERVA ---" << endl;
            cout << "Digite la identificacion del cliente: ";
            cin >> identificacion;

            Cliente* cli = coleccionClientes->buscarCliente(identificacion);
            if (cli == nullptr) {
                cout << "Error: El cliente con ID '" << identificacion << "' no existe." << endl;
                system("pause");
                break;
            }

            cout << "Digite el codigo de la cancha: ";
            cin >> codigo;

            Cancha* can = coleccionCanchas->buscarCancha(codigo);
            if (can == nullptr) {
                cout << "Error: La cancha con codigo '" << codigo << "' no existe." << endl;
                system("pause");
                break;
            }

			// Guía de franjas horarias para el usuario
            cout << "\n-----------------------------------------------------" << endl;
            cout << "GUIA DE FRANJAS HORARIAS (0 a 13):" << endl;
            cout << " 0: 06:00-07:00 |  1: 07:00-08:00 |  2: 08:00-09:00" << endl;
            cout << " 3: 09:00-10:00 |  4: 10:00-11:00 |  5: 11:00-12:00" << endl;
            cout << " 6: 12:00-13:00 |  7: 13:00-14:00 |  8: 14:00-15:00" << endl;
            cout << " 9: 15:00-16:00 | 10: 16:00-17:00 | 11: 17:00-18:00" << endl;
            cout << "12: 18:00-19:00 | 13: 19:00-20:00" << endl;
            cout << "-----------------------------------------------------" << endl;

            cout << "Digite la Franja de inicio (0 - 13): ";
            cin >> franjaInicio;
            cout << "Digite la cantidad de franjas continuas a reservar (ej. 1 u 8): ";
            cin >> cantidadFranjas;

            if (coleccionReservas->registrarReserva(cli, can, franjaInicio, cantidadFranjas)) {
                cout << "\nReserva registrada correctamente." << endl;
            }
            else {
                cout << "\nError al registrar reserva. Las franjas solicitadas estan ocupadas o fuera de rango." << endl;
            }
            system("pause");
            break;
        }

        case 2:
            system("cls");
            cout << "--- Listado General de Reservas ---" << endl;
            coleccionReservas->mostrarTodasReservas();
            system("pause");
            break;

        case 3:
            system("cls");
            cout << "Digite el codigo de la cancha: ";
            cin >> codigo;
            cout << "Digite el numero de franja (0 - 13): ";
            cin >> franjaInicio;
            cout << "Digite la nueva disponibilidad (O=Ocupada, L=Libre, M=Mantenimiento): ";
            cin >> estado;

            {
                Cancha* cancha = coleccionCanchas->buscarCancha(codigo);
                if (cancha != nullptr) {
                    cancha->cambiarDisponibilidad(franjaInicio, estado);
                    cout << "\nDisponibilidad actualizada correctamente." << endl;
                }
                else {
                    cout << "\nError: Cancha no encontrada." << endl;
                }
            }
            system("pause");
            break;

        case 4: {
            system("cls");
            cout << "Digite el numero consecutivo de reserva: ";
            cin >> numeroReserva;
            Reserva* res = coleccionReservas->buscarReserva(numeroReserva);
            if (res != nullptr) {
                cout << "\nReserva encontrada:" << endl;
                res->mostrar();
            }
            else {
                cout << "\nReserva no encontrada." << endl;
            }
            system("pause");
            break;
        }

        case 5:
            system("cls");
            cout << "Digite el codigo de la cancha: ";
            cin >> codigo;
            coleccionReservas->mostrarReservasPorCancha(codigo);
            system("pause");
            break;

        case 6:
            system("cls");
            cout << "Digite el numero de reserva a cancelar: ";
            cin >> numeroReserva;
            if (coleccionReservas->cancelarReserva(numeroReserva))
                cout << "\nReserva cancelada exitosamente y franjas liberadas." << endl;
            else
                cout << "\nError al cancelar. No existe una reserva con ese numero." << endl;
            system("pause");
            break;

        case 7:
            break;
        }
    } while (opcion != 7);
}

void Menu::menuEsperas() {
    int opcion = 0;
    do {
        system("cls");
        cout << "==============================================" << endl;
        cout << "              LISTA DE ESPERA                 " << endl;
        cout << "==============================================" << endl;
        cout << "1. Registrar cliente en lista de espera" << endl;
        cout << "2. Mostrar el contenido de la lista de espera" << endl;
        cout << "3. Cambiar el estado de una solicitud de espera" << endl;
        cout << "4. Volver al menu principal" << endl;
        cout << "==============================================" << endl;
        cout << "Digite una opcion: ";
        cin >> opcion;

        while (cin.fail() || opcion < 1 || opcion > 4) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Opcion invalida. Digite un numero entre 1 y 4: ";
            cin >> opcion;
        }

        string identificacion, codigoCancha;
        char estado;
        int franjaHoraria, numeroEspera;

        switch (opcion) {
        case 1: {
            system("cls");
            cout << "--- Registrar Solicitud en Espera ---" << endl;
            cout << "Digite la identificacion del cliente: ";
            cin >> identificacion;

            Cliente* cli = coleccionClientes->buscarCliente(identificacion);
            if (cli == nullptr) {
                cout << "Error: El cliente no esta registrado." << endl;
                system("pause");
                break;
            }

            cout << "Digite el codigo de la cancha: ";
            cin >> codigoCancha;

            Cancha* can = coleccionCanchas->buscarCancha(codigoCancha);
            if (can == nullptr) {
                cout << "Error: La cancha no esta registrada." << endl;
                system("pause");
                break;
            }

            cout << "Digite la franja horaria deseada (0 - 13): ";
            cin >> franjaHoraria;

            if (coleccionEspera->agregarEspera(cli, can, franjaHoraria))
                cout << "\nSolicitud en lista de espera agregada exitosamente." << endl;
            else
                cout << "\nError al registrar la solicitud en lista de espera." << endl;

            system("pause");
            break;
        }

        case 2:
            system("cls");
            cout << "--- Contenido de la Lista de Espera ---" << endl;
            coleccionEspera->mostrarListadoEspera();
            system("pause");
            break;

        case 3:
            system("cls");
            cout << "Digite el id/numero de la solicitud de espera: ";
            cin >> numeroEspera;
            cout << "Digite el nuevo estado (P = Pendiente, C = Confirmado, A = Anulado): ";
            cin >> estado;

            if (coleccionEspera->cambiarEstadoEspera(numeroEspera, estado))
                cout << "\nEstado actualizado correctamente." << endl;
            else
                cout << "\nError al actualizar el estado." << endl;
            system("pause");
            break;

        case 4:
            break;
        }
    } while (opcion != 4);
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