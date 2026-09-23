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
    int opcion = 0;
    cout << "==============================================" << endl;
    cout << "          GESTION DE CANCHAS" << endl;
    cout << "==============================================" << endl;
    cout << "1. Registrar nueva cancha" << endl;
    cout << "2. Mostrar todas las canchas" << endl;
    cout << "3. Buscar cancha por codigo" << endl;
    cout << "4. Modificar el precio de una cancha" << endl;
    cout << "5. Mostrar disponibilidad de una cancha" << endl;
    cout << "6. Volver al menu principal" << endl;
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
    if (opcion == 1) {
        cout << "Digite el codigo de la cancha: ";
        cin >> codigo;
        cout << "Digite el deporte de la cancha: ";
        cin >> deporte;
        cout << "Digite el precio de la cancha: ";
        cin >> precio;
        if (coleccionCanchas->agregarCancha(new Cancha(codigo, deporte, precio)))
            cout << "Cancha registrada correctamente." << endl;
        else
            cout << "Error al registrar la cancha. Codigo ya existe." << endl;
        system("cls");
        system("pause");
    }

    if (opcion == 2) {
        system("cls");
        coleccionCanchas->mostrarCanchas();
        system("pause");
    }

    if (opcion == 3) {
        system("cls");
        cout << "Digite el codigo de la cancha a buscar: ";
        cin >> codigo;
        if (coleccionCanchas->buscarCancha(codigo))
            cout << "Cancha encontrada." << endl;
        else
            cout << "Cancha no encontrada." << endl;
        system("pause");
    }

    if (opcion == 4) {
        cout << "Digite el codigo de la cancha a modificar: ";
        cin >> codigo;
        cout << "Digite el nuevo precio de la cancha: ";
        cin >> precio;
        system("cls");
        if (coleccionCanchas->modificarPrecio(codigo, precio))
            cout << "Precio actualizado correctamente." << endl;
        else
            cout << "Imposible actualizar precio." << endl;
        system("pause");
    }

    if (opcion == 5) {
        cout << "Codigo: ";
        cin >> codigo;
        coleccionCanchas->mostrarDisponibilidad(codigo);
        system("pause");
    }
}

void Menu::menuClientes() {
    system("cls");
    int opcion = 0;
    cout << "==============================================" << endl;
    cout << "          GESTION DE CLIENTES" << endl;
    cout << "==============================================" << endl;
    cout << "1. Registrar nuevo cliente" << endl;
    cout << "2. Mostrar todos los clientes" << endl;
    cout << "3. Buscar cliente por identificacion" << endl;
    cout << "4. Mostrar reservas de un cliente" << endl;
    cout << "5. Volver al menu principal" << endl;
    cout << "Digite una opcion: ";
    cin >> opcion;
    while (cin.fail() || opcion < 1 || opcion > 5) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Opcion invalida. Digite un numero entre 1 y 5: ";
        cin >> opcion;
    }

    string identificacion, nombre, telefono;

    if (opcion == 1) {
        system("cls");
        cout << "Digite la identificacion del cliente: ";
        cin >> identificacion;
        cout << "Digite el nombre del cliente: ";
        cin >> nombre;
        cout << "Digite el telefono del cliente: ";
        cin >> telefono;
        if (coleccionClientes->agregarCliente(new Cliente(identificacion, nombre, telefono)))
            cout << "Cliente registrado correctamente." << endl;
        else
            cout << "Error al registrar el cliente. Identificacion ya existe." << endl;
        system("cls");
        system("pause");
    }

    if (opcion == 2) {
        system("cls");
        coleccionClientes->mostrarClientes();
        system("pause");
    }

    if (opcion == 3) {
        system("cls");
        cout << "Digite la identificacion del cliente a buscar: ";
        cin >> identificacion;
        if (coleccionClientes->buscarCliente(identificacion))
            cout << "Cliente encontrado." << endl;
        else
            cout << "Cliente no encontrado." << endl;
        system("pause");
    }

    if (opcion == 4) {
        system("cls");
        cout << "Digite la identificacion del cliente: ";
        cin >> identificacion;
        coleccionReservas->mostrarReservasPorCliente(identificacion);
        system("pause");
    }
}

void Menu::menuReservas() {
    system("cls");
    int opcion = 0;

    cout << "==============================================" << endl;
    cout << "          GESTION DE RESERVAS" << endl;
    cout << "==============================================" << endl;
    cout << "1. Registrar reservas" << endl;
    cout << "2. Mostrar todas las reservas" << endl;
    cout << "3. Cambio de disponibilidad" << endl;
    cout << "4. Buscar reserva por numero de reserva" << endl;
    cout << "5. Mostrar reservas asociadas a una cancha" << endl;
    cout << "6. Cancelar reserva" << endl;
    cout << "7. Volver al menu principal" << endl;
    cout << "Digite una opcion: ";

    while (cin.fail() || opcion < 1 || opcion > 7) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Opcion invalida. Digite un numero entre 1 y 6: ";
        cin >> opcion;
    }

    string identificacion, codigo;
    char estado;
    int franjaInicio, cantidadFranjas, numeroReserva;

    if (opcion == 1) {
        system("cls");
        cout << "Digite la identificacion del cliente: ";
        cin >> identificacion;
        cout << "Digite el codigo de la cancha: ";
        cin >> codigo;
        cout << "Digite la Franja de inicio: ";
        cin >> franjaInicio;
        cout << "Digite la cantidad de franjas a reservar: ";
        cin >> cantidadFranjas;
        if (coleccionReservas->registrarReserva(coleccionClientes->buscarCliente(identificacion),
            coleccionCanchas->buscarCancha(codigo), franjaInicio, cantidadFranjas))
            cout << "Reserva registrada correctamente." << endl;
        else
            cout << "Error al registrar la reserva." << endl;
        system("pause");
    }

    if (opcion == 2) {
        system("cls");
        coleccionReservas->mostrarTodasReservas();
        system("pause");
    }

    if (opcion == 3) {
        system("cls");
        cout << "Digite el codigo de la cancha: ";
        cin >> codigo;
        cout << "Digite la franja a cambiar: ";
        cin >> cantidadFranjas;
        cout << "Digite la nueva disponibilidad (O=Ocupada, L=Libre, M=Mantenimiento): ";
        cin >> estado;
        Cancha* cancha = coleccionCanchas->buscarCancha(codigo);
        if (cancha) {
            cancha->cambiarDisponibilidad(cantidadFranjas, estado);
            cout << "Disponibilidad actualizada correctamente." << endl;
        }
        else {
            cout << "Error al actualizar la disponibilidad." << endl;
        }
        system("pause");
    }

    if (opcion == 4) {
        system("cls");
        cout << "Numero de reserva: ";
        cin >> numeroReserva;
        if (coleccionReservas->buscarReserva(numeroReserva)) {
            coleccionReservas->buscarReserva(numeroReserva)->mostrar();
            cout << "Reserva encontrada." << endl;
        }
        else {
            cout << "Reserva no encontrada." << endl;
        }
        system("pause");
    }

    if (opcion == 5) {
        system("cls");
        coleccionReservas->mostrarReservasPorCancha(codigo);
        system("pause");
    }

    if (opcion == 6) {
        system("cls");
        cout << "Numero de reserva: ";
        cin >> numeroReserva;
        if (coleccionReservas->cancelarReserva(numeroReserva))
            cout << "Reserva cancelada correctamente." << endl;
        else
            cout << "Error al cancelar la reserva." << endl;
        system("pause");
    }
}

void Menu::menuEsperas() {
    system("cls");
    int opcion = 0;
    cout << "==============================================" << endl;
    cout << "              LISTA DE ESPERA                 " << endl;
    cout << "==============================================" << endl;
    cout << "1. Registrar cliente en lista de espera" << endl;
    cout << "2. Mostrar el contenido de la lista de espera" << endl;
    cout << "3. Cambiar el estado de un cliente en la lista de espera" << endl;
    cout << "4. Volver al menu principal" << endl;
    cout << "Digite una opcion: ";

    while (cin.fail() || opcion < 1 || opcion > 4) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Opcion invalida. Digite un numero entre 1 y 4: ";
        cin >> opcion;
    }

    string identificacion, codigoCancha;
    char  estado;
    int franjaHoraria, numeroReserva;
    system("pause");

    if (opcion == 1) {
        system("cls");
        cout << "Digite la identificacion del cliente: ";
        cin >> identificacion;
        cout << "Digite el codigo de la cancha: ";
        cin >> codigoCancha;
        cout << "Digite la franja horaria: ";
        cin >> franjaHoraria;
        if (coleccionEspera->agregarEspera(coleccionClientes->buscarCliente(identificacion),
            coleccionCanchas->buscarCancha(codigoCancha), franjaHoraria))
            cout << "Cliente registrado en lista de espera correctamente." << endl;
        else
            cout << "Error al registrar el cliente en la lista de espera  ." << endl;
        system("cls");
        system("pause");
    }

    if (opcion == 2) {
        system("cls");
        coleccionEspera->mostrarListadoEspera();
        system("pause");
    }

    if (opcion == 3) {
        system("cls");
        cout << "Digite el numero de espera: ";
        cin >> numeroReserva;
        cout << "Digite el nuevo estado del cliente (Pendiente, Confirmado, Cancelado): ";
        cin >> estado;
        if (coleccionEspera->cambiarEstadoEspera(numeroReserva, estado))
            cout << "Estado del cliente actualizado correctamente." << endl;
        else
            cout << "Error al actualizar el estado del cliente." << endl;
        system("pause");
    }
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