#include "Estadisticas.h"
#include "Cancha.h"
#include "Cliente.h"
#include "Reserva.h"
Estadisticas::Estadisticas() {
	// Constructor
}
Estadisticas::~Estadisticas() {
	// Destructor
}

// 1. Cancha más reservada
void Estadisticas::reporteCanchaMasReservada(Cancha* canchas[], int cantCanchas, Reserva* reservas[], int cantReservas) const {
	
	if (cantCanchas == 0 || cantReservas == 0) {
		cout << "No hay canchas o reservas registradas." << endl;
		return;
	}
	int maxReservas = -1;
	string codigoMasReservado = "";
	for (int i = 0; i < cantCanchas; i++) {
		int contadorLocal = 0;
		string codActual = canchas[i]->getCodigo();

		for (int j = 0; j < cantReservas; j++) {
			if (reservas[j]->isActiva() && reservas[j]->getCancha() != nullptr) {
				if (reservas[j]->getCancha()->getCodigo() == codActual) {
					contadorLocal++;
				}
			}
		}
		cout << "-> Cancha " << codActual << " (" << canchas[i]->getDeporte()
			<< "): " << contadorLocal << " reservas activas." << endl;
		if (contadorLocal > maxReservas) {
			maxReservas = contadorLocal;
			codigoMasReservado = codActual;
		}
	}
	cout << "----------------------------------------------" << endl;
	cout << "RESULTADO: La cancha mas reservada es " << codigoMasReservado
		<< " con un total de " << maxReservas << " reservas." << endl;
	
}

// 2. Cliente con más reservas
void Estadisticas::reporteClienteMasReservas(Cliente* clientes[], int cantClientes, Reserva* reservas[], int cantReservas) const {
	
	if (cantClientes == 0 || cantReservas == 0) {
		cout << "No hay clientes o reservas registradas." << endl;
		return;
	}
	int maxReservas = -1;
	string idClienteMax = "";
	string nombreClienteMax = "";
	for (int i = 0; i < cantClientes; i++) {
		int contadorLocal = 0;
		string idActual = clientes[i]->getIdentificacion();

		for (int j = 0; j < cantReservas; j++) {
			if (reservas[j]->isActiva() && reservas[j]->getCliente() != nullptr) {
				if (reservas[j]->getCliente()->getIdentificacion() == idActual) {
					contadorLocal++;
				}
			}
		}
		cout << "-> Cliente ID: " << idActual << " (" << clientes[i]->getNombre()
			<< "): " << contadorLocal << " reservas." << endl;
		if (contadorLocal > maxReservas) {
			maxReservas = contadorLocal;
			idClienteMax = idActual;
			nombreClienteMax = clientes[i]->getNombre();
		}
	}
	cout << "----------------------------------------------" << endl;
	cout << "RESULTADO: El cliente con mas reservas es " << nombreClienteMax 
              << " (ID: " << idClienteMax << ") con " << maxReservas << " reservas." << endl;
}

// 3. Ingreso total
void Estadisticas::reporteIngresoTotal(Reserva* reservas[], int cantReservas) const {
	
	double ingresoTotal = 0.0;
	int reservasActivas = 0;
	for (int i = 0; i < cantReservas; i++) {
		if (reservas[i]->isActiva()) {
			double monto = reservas[i]->getMontoTotal();
			ingresoTotal += monto; 
			reservasActivas++;
			cout << "-> Reserva #" << reservas[i]->getNumeroReserva()
				<< " | Monto: " << monto << " CRC" << endl;
		}
	}
	cout << "----------------------------------------------" << endl;
	cout << "RESULTADO: El ingreso total es: " << ingresoTotal << " CRC" << endl;
	cout << "Total de reservas activas: " << reservasActivas << endl;
}

// 4. Porcentaje de ocupación
void Estadisticas::reportePorcentajeOcupacion(Cancha* canchas[], int cantCanchas, Reserva* reservas[], int cantReservas) const {
	
	if (cantCanchas == 0) {
		cout << "No hay canchas registradas." << endl;
		return;
	}
	for (int i = 0; i < cantCanchas; i++) {
		int franjasOcupadas = 0;
		string codActual = canchas[i]->getCodigo();
		for (int j = 0; j < cantReservas; j++) {
			if (reservas[j]->isActiva() && reservas[j]->getCancha() != nullptr) { // si la reserva está activa y la cancha no es nula
				if (reservas[j]->getCancha()->getCodigo() == codActual) {// si la reserva pertenece a la cancha actual
					franjasOcupadas += reservas[j]->getCantidadFranjas();// se suman las franjas ocupadas por la reserva
				}
			}
		}
		// El porcentaje se calcula en base a la capacidad operativa de franjas por cancha
		double porcentaje = (franjasOcupadas * 100.0) / CANT_FRANJAS; // CANT_FRANJAS es la cantidad total de franjas horarias posibles
		if (porcentaje > 100.0) porcentaje = 100.0; // Control de tope
		cout << "-> Cancha " << codActual
			<< "| Franjas ocupadas: " << franjasOcupadas << "/" << CANT_FRANJAS
			<< "| Ocupacion: " << porcentaje << "%" << endl;
	}
}

// 5. Horarios extremos
void Estadisticas::reporteHorasExtremas(Reserva* reservas[], int cantReservas) const {
	
	int franjasConteo[CANT_FRANJAS] = { 0 }; // Inicializar el arreglo de conteo de franjas
	for (int i = 0; i < cantReservas; i++) {
		if (reservas[i]->isActiva()) {
			int inicio = reservas[i]->getFranjaInicio();
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