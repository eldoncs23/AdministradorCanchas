#include "ColeccionReservas.h"
ColeccionReservas::ColeccionReservas(int capacidad) {
    this->max = capacidad;
    this->cant = 0;
	this->vec = new Reserva*[max]; //se crea un arreglo dinámico de punteros a Reserva
    for (int i = 0; i < max; i++) {
        vec[i] = nullptr;
    }
}
ColeccionReservas:: ~ColeccionReservas() {
    for (int i = 0; i < cant; i++) {
        delete vec[i];
		vec[i] = nullptr;
    }
    delete[] vec;
	vec = nullptr;
}
bool ColeccionReservas::registrarReserva(Cliente* cliente, Cancha* cancha, int franjaInicio, int cantidadFranjas) {
    if (cliente == nullptr || cancha == nullptr || cant >= max) {
		//verificar que los punteros no sean nulos y que no se haya alcanzado la capacidad máxima
        return false;
    }
    if (franjaInicio < 0 || (franjaInicio + cantidadFranjas) > CANT_FRANJAS || cantidadFranjas <= 0) {
		//verificar que la franja de inicio y la cantidad de franjas sean válidas
        return false;
    }
    //verificar que toda la franja solicitada se encuentre libre (L)
	for (int i = franjaInicio; i < franjaInicio + cantidadFranjas; i++) {
		if (cancha->getEstadoFranja(i) != 'L') { 
            //getEstado proviene de la clase Cancha, y devuelve el estado de la franja (L, R, M)
			return false;
		}
	}
	//cambiar estado de la cancha de L a O (ocupada)
	for (int i = franjaInicio; i < franjaInicio + cantidadFranjas; i++) {
		cancha->ocuparFranja(i);
	}
	//crear la reserva y agregarla al vector
	Reserva* nuevaReserva = new Reserva(cliente, cancha, franjaInicio, cantidadFranjas);
	vec[cant] = nuevaReserva;
    cant++;
    return true;
}
Reserva* ColeccionReservas::buscarReserva(int numeroReserva)const {
    for (int i = 0; i < cant; i++) {
        if (vec[i] != nullptr && vec[i]->getNumeroReserva() == numeroReserva) {
            return vec[i];
        }
    }
    return nullptr;
}
bool ColeccionReservas::cancelarReserva(int numeroReserva, ColeccionEspera* coleccionEspera) {
    
    Reserva* reserva = buscarReserva(numeroReserva); // Buscar la reserva por número
    if (reserva == nullptr || !reserva->isActiva()) { // Verificar que exista y esté activa
        return false; // No se encontró o ya estaba cancelada
    }

	// guardar datos de la reserva antes de cancelarla, para notificar a la colección de espera
    string codigoCancha = "";
    if (reserva->getCancha() != nullptr) {
        codigoCancha = reserva->getCancha()->getCodigo();
    }
    int franjaInicio = reserva->getFranjaInicio();
    int cantidadFranjas = reserva->getCantidadFranjas();

	// cambiar el estado de la reserva a cancelada y liberar las franjas de la cancha
    bool exito = reserva->cancelarReserva();

	// notificar a la colección de espera si la reserva fue cancelada exitosamente y si se proporcionó una colección de espera válida
    if (exito && coleccionEspera != nullptr && codigoCancha != "") {
        coleccionEspera->verificarNotificacionesEspera(codigoCancha, franjaInicio, cantidadFranjas);
    }

    // retornar el resultado de la operación de cancelación
    return exito;
}

void ColeccionReservas::mostrarTodasReservas() const {
    if (cant == 0) {
        cout << "No hay reservas registradas." << endl;
        return;
    }
    for (int i = 0; i < cant; i++) {
		if (vec[i] != nullptr) {
			vec[i]->mostrar();
		}
    }
}

void ColeccionReservas::mostrarReservasPorCliente(string identificacion) const {
    bool encontradas = false;

	for (int i = 0; i < cant; i++) { // Iterar sobre todas las reservas
        if (vec[i] != nullptr && vec[i]->getCliente() != nullptr && vec[i]->getCliente()->getIdentificacion() == identificacion) { 
			// Mostrar la reserva encontrada que coincide con la identificación del cliente y verificar que el puntero del cliente no sea nulo
            vec[i]->mostrar();
            encontradas = true;
        }
    }
    if (!encontradas) {
        cout << "No se encontraron reservas para el cliente con identificación: " << identificacion << endl;
    }
}

void ColeccionReservas::mostrarReservasPorCancha(string codigoCancha) const {
	bool encontradas = false;
    for (int i = 0; i < cant; i++) {
        if (vec[i] != nullptr && vec[i]->getCancha() != nullptr && vec[i]->getCancha()->getCodigo() == codigoCancha) {
			// Mostrar la reserva encontrada que coincide con el código de la cancha y verificar que el puntero de la cancha no sea nulo
            vec[i]->mostrar();
            encontradas = true;
        }
    }
    if (!encontradas) {
        cout << "No se encontraron reservas para la cancha con código: " << codigoCancha << endl;
    }
}

int ColeccionReservas::getCant()const {
    return cant;
}

int ColeccionReservas::getMax()const {
    return max;
}

Reserva* ColeccionReservas::getReservaPorIndice(int indice)const {
    if (indice >= 0 && indice < cant) {
        return vec[indice];
    }
    return nullptr;
}
int ColeccionReservas::contarReservasActivasPorCancha(string codigoCancha) const
{
    int activas = 0;
    for (int i = 0; i < cant; i++)
    {
        if (vec[i] != nullptr && vec[i]->getCancha() != nullptr
            && vec[i]->getCancha()->getCodigo() == codigoCancha && vec[i]->isActiva())
        {
            activas++;
        }
    }
    return activas;
}

int ColeccionReservas::contarReservasActivasPorCliente(string identificacion) const
{
    int activas = 0;
    for (int i = 0; i < cant; i++)
    {
        if (vec[i] != nullptr && vec[i]->getCliente() != nullptr
            && vec[i]->getCliente()->getIdentificacion() == identificacion && vec[i]->isActiva())
        {
            activas++;
        }
    }
    return activas;
}