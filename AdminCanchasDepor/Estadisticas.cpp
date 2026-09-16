#include "Estadisticas.h"
#include "Canchas.h"
#include "Clientes.h"
#include "Reservas.h"
#include "Espera.h"
#include <stdlib.h>
#include "iostream"
using namespace std;

Estadisticas::Estadisticas() {
	totalClientes = 0;
	totalCanchas = 0;
	totalReservas = 0;
	maxReservas = 120;
	reservas = new Reserva[maxReservas];
	totalEspera = 0;
}

Estadisticas::~Estadisticas() {
	delete[] reservas;
}

// 1. Cancha más reservada
void Estadisticas::reporteCanchaMasReservada(Cancha* canchas[], int cantCanchas, Reserva* reservas[], int cantReservas) const {
	cout << "\n==============================================" << endl;
	cout << "      CANCHA CON MAYOR CANTIDAD DE RESERVAS     " << endl;
	cout << "================================================" << endl;

	if (cantCanchas == 0 || cantReservas == 0) {
		cout << "No hay canchas o reservas registradas." << endl;
		return;
	}
	int maxReservas = -1;
	string codigoMasReservado = "";
	for (int i = 0; i < cantCanchas; i++) {
		int contadorLocal = 0;
		std::string codActual = canchas[i]->getCodigo();

		for (int j = 0; j < cantReservas; j++) {
			if (reservas[j]->getActiva() && reservas[j]->getCancha() != nullptr) {
				if (reservas[j]->getCancha()->getCodigo() == codActual) {
					contadorLocal++;
				}
			}
		}
		cout << "-> Cancha " << codActual << " (" << canchas[i]->getDeporte()
			<< "): " << contadorLocal << " reservas activas." << std::endl;
		if (contadorLocal > maxReservas) {
			maxReservas = contadorLocal;
			codigoMasReservado = codActual;
		}
	}
	cout << "----------------------------------------------" << std::endl;
	cout << "RESULTADO: La cancha mas reservada es " << codigoMasReservado
		<< " con un total de " << maxReservas << " reservas." << std::endl;
	
}

// 2. Cliente con más reservas
void Estadisticas::reporteClienteMasReservas(Cliente* clientes[], int cantClientes, Reserva* reservas[], int cantReservas) const {
	cout << "\n==============================================" << endl;
	cout << "      CLIENTE CON MAYOR CANTIDAD DE RESERVAS     " << endl;
	cout << "================================================" << endl;
	if (cantClientes == 0 || cantReservas == 0) {
		cout << "No hay clientes o reservas registradas." << endl;
		return;
	}
	int maxReservas = -1;
	string idClienteMax = "";
	string nombreClienteMax = "";
	for (int i = 0; i < cantClientes; i++) {
		int contadorLocal = 0;
		std::string idActual = clientes[i]->getId();

		for (int j = 0; j < cantReservas; j++) {
			if (reservas[j]->getActiva() && reservas[j]->getCliente() != nullptr) {
				if (reservas[j]->getCliente()->getId() == idActual) {
					contadorLocal++;
				}
			}
		}
		cout << "-> Cliente ID: " << idActual << " (" << clientes[i]->getNombre()
			<< "): " << contadorLocal << " reservas." << std::endl;
		if (contadorLocal > maxReservas) {
			maxReservas = contadorLocal;
			idClienteMax = idActual;
			nombreClienteMax = clientes[i]->getNombre();
		}
	}
	cout << "----------------------------------------------" << std::endl;
	cout << "RESULTADO: El cliente con mas reservas es " << nombreClienteMax 
              << " (ID: " << idClienteMax << ") con " << maxReservas << " reservas." << std::endl;
}

// 3. Ingreso total
void Estadisticas::reporteIngresoTotal(Reserva* reservas[], int cantReservas) const {
	cout << "\n==============================================" << endl;
	cout << "              REPORTE DE INGESOS TOTALES        " << endl;
	cout << "================================================" << endl;
	float ingresoTotal = 0.0;
	int reservasActivas = 0;
	for (int i = 0; i < cantReservas; i++) {
		if (reservas[i]->getActiva()) {
			float monto = reservas[i]->getMonto();
			ingresoTotal += monto;
			reservasActivas++;
			cout << "-> Reserva #" << reservas[i]->getNumeroReserva()
				<< " | Monto: " << monto << " CRC" << std::endl;
		}
	}
	cout << "----------------------------------------------" << std::endl;
	cout << "RESULTADO: El ingreso total es: $" << ingresoTotal << " CRC" << std::endl;
	cout << "Total de reservas activas: " << reservasActivas << std::endl;
}

// 4. Porcentaje de ocupación
void Estadisticas::reportePorcentajeOcupacion(Cancha* canchas[], int cantCanchas, Reserva* reservas[], int cantReservas) const {
	cout << "\n==============================================" << endl;
	cout << "      CANCHA CON MAYOR CANTIDAD DE RESERVAS     " << endl;
	cout << "================================================" << endl;
	if (cantCanchas == 0) {
		cout << "No hay canchas registradas." << endl;
		return;
	}
	for (int i = 0; i < cantCanchas; i++) {
		int franjasOcupadas = 0;
		string codActual = canchas[i]->getCodigo();
		for (int j = 0; j < cantReservas; j++) {
			if (reservas[j]->getActiva() && reservas[j]->getCancha() != nullptr) { // si la reserva está activa y la cancha no es nula
				if (reservas[j]->getCancha()->getCodigo() == codActual) {// si la reserva pertenece a la cancha actual
					franjasOcupadas += reservas[j]->getCantidadFranjas();// se suman las franjas ocupadas por la reserva
				}
			}
		}
		// El porcentaje se calcula en base a la capacidad operativa de franjas por cancha
		float porcentaje = (franjasOcupadas * 100.00) / CANT_FRANJAS; // CANT_FRANJAS es la cantidad total de franjas horarias posibles
		if (porcentaje > 100.00) porcentaje = 100.00; 
		cout << "-> Cancha " << codActual
			<< "| Franjas ocupadas: " << franjasOcupadas << "/" << CANT_FRANJAS
			<< "| Ocupacion: " << porcentaje << "%" << endl;
			
	}
}

// 5. Horarios extremos
void Estadisticas::reporteHorasExtremas(Reserva* reservas[], int cantReservas) const {
	cout << "\n==============================================" << endl;
	cout << "      HORARIOS EXTREMOS DE RESERVAS             " << endl;
	cout << "================================================" << endl;
	int franjasConteo[CANT_FRANJAS] = { 0 }; // Inicializar el arreglo de conteo de franjas
	for (int i = 0; i < cantReservas; i++) {
		if (reservas[i]->getActiva()) {
			int inicio = reservas[i]->getFranjaInicial();
			int duracion = reservas[i]->getCantidadFranjas();

			for (int f = inicio; f < (inicio + duracion) && f < CANT_FRANJAS; f++) {
				franjasConteo[f]++;
			}
		}
	}
	int mayorDemanda = -1, menorDemanda = 9999999; // Inicializar menorDemanda con un valor alto
	int franjaMayor = 0, franjaMenor = 0;
	for (int i = 0; i < CANT_FRANJAS; i++) {
		cout << "-> Franja [" << i << "]: " << franjasConteo[i] << " reservas." << endl;
		if (franjasConteo[i] > mayorDemanda) {
			mayorDemanda = franjasConteo[i];
			franjaMayor = i;
		}
		if (franjasConteo[i] < menorDemanda) {
			menorDemanda = franjasConteo[i];
			franjaMenor = i;
		}
	}
	cout << "----------------------------------------------" <<endl;
	cout << "RESULTADO:" << endl;
	cout << "Franja con mayor demanda: [" << franjaMayor << "] con " << mayorDemanda << " reservas." << endl;
	cout << "Franja con menor demanda: [" << franjaMenor << "] con " << menorDemanda << " reservas." << endl;
}

// submenu de reportes
void Estadisticas::menuEstadisticas(Cancha* canchas[], int cantCanchas, Cliente* clientes[], int cantClientes, Reserva* reservas[], int cantReservas) const {
	int opcion;
	do {
		cout << "\n==============================================" << endl;
		cout << "      MENU DE ESTADISTICAS Y REPORTES         " << endl;
		cout << "================================================" << endl;
		cout << "1. Cancha con mayor cantidad de reservas" << endl;
		cout << "2. Cliente con mayor cantidad de reservas" << endl;
		cout << "3. Ingreso total por reservas" << endl;
		cout << "4. Porcentaje de ocupacion por cancha" << endl;
		cout << "5. Horarios extremos de reservas" << endl;
		cout << "6. Volver al menu principal" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			reporteCanchaMasReservada(canchas, cantCanchas, reservas, cantReservas);
			break;
		case 2:
			reporteClienteMasReservas(clientes, cantClientes, reservas, cantReservas);
			break;
		case 3:
			reporteIngresoTotal(reservas, cantReservas);
			break;
		case 4:
			reportePorcentajeOcupacion(canchas, cantCanchas, reservas, cantReservas);
			break;
		case 5:
			reporteHorasExtremas(reservas, cantReservas);
			break;
		case 6:
			cout << "Volviendo al menu principal..." << endl;
			break;
		default:
			cout << "Opcion invalida. Intente nuevamente." << endl;
			break;
		}
	} while (opcion != 6);
}

void Estadisticas::registarCliente(string id,string nombre, string telefono) {
	if (totalClientes < 100) {
		clientes[totalClientes++] = Cliente(id, nombre, telefono);
	}
	else {
		cout << "Imposible registar usuario" << endl;

	}
}

Cliente* Estadisticas::buscarCliente(string id) {
	for (int i = 0; i < totalClientes; i++) {
		if (clientes[i].getId() == id) {
			return &clientes[i];
		}
	}
	return nullptr;
}

void Estadisticas::mostrarCliente(){
	for (int i = 0; i < totalClientes; i++) {
		cout << "Cliente #" << (i + 1) << ": " << endl;
		cout << "ID: " << clientes[i].getId() << endl;
		cout << "Nombre: " << clientes[i].getNombre() << endl;
		cout << "Telefono: " << clientes[i].getTelefono() << endl;
		cout << "------------------------" << endl;
	}
}

void Estadisticas::registrarCancha(string codigo, string tipo, float precio) {
	if (totalCanchas < 10) {
		canchas[totalCanchas++] = Cancha(codigo, tipo, precio);
	}
	else {
		cout << "Imposible registrar cancha" << endl;
	}
}

Cancha* Estadisticas::buscarCancha(string codigo) {
	for (int i = 0; i < totalCanchas; i++) {
		if (canchas[i].getCodigo() == codigo) {
			return &canchas[i];
		}
	}
	return nullptr;
}

void Estadisticas::mostrarCanchas() {
	for (int i = 0; i < totalCanchas; i++) {
		cout << "Cancha: " << canchas[i].getCodigo() 
			 << canchas[i].getDeporte()
			 << canchas[i].getPrecioHora() << endl;
	}
}
//Pruebas
void Estadisticas::registrarReserva(string id, string codigo, int franjaInicial, int cantidadFranjas) {
	Cliente* cliente = buscarCliente(id);
	Cancha* cancha =buscarCancha(codigo);
	if (cancha && cliente && totalReservas < maxReservas) {
		//reservas[totalReservas++] = Reserva ();
		if (reservas[totalReservas - 1].getActiva()) {
			cout << "Reserva registrada exitosamente." << endl;
		}
		else {
			cout << "Se encuentra en lista de espera." << endl;
		//	registarCliente();
		}	
		totalReservas++;
	}
	else {
		cout << "Imposible registrar reserva" << endl;
	}
}