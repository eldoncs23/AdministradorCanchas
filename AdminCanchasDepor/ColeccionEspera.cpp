#include "ColeccionEspera.h"
ColeccionEspera::ColeccionEspera(int capacidad) {
    this->max = capacidad;
    this->cant = 0;
	this->vec = new RegistroEspera * [max]; //se crea un arreglo dinámico de punteros a RegistroEspera
    for (int i = 0; i < max; i++) {
        vec[i] = nullptr;
    }
}
ColeccionEspera::~ColeccionEspera() {
    for (int i = 0; i < cant; i++) {
        if (vec[i] != nullptr) {
            delete vec[i];
            vec[i] = nullptr;
        }
    }
    delete[] vec;
    vec = nullptr;
}

//metodos
bool ColeccionEspera::agregarEspera(Cliente* cliente, Cancha* cancha, int posicionFranja) {
    if (cliente == nullptr || cancha == nullptr || cant >= max) {
        return false;
    }
    if (posicionFranja < 0 || posicionFranja >= CANT_FRANJAS) {
        return false;
    }
	//solo se permite agrega a espera si la franja esta ocupada (O)
    if (cancha->getEstadoFranja(posicionFranja) != 'O') {
        return false;
    }
	//validacion: un mismo cliente no puede aparecer dos veces en estado 'E' para la misma cancha y franja
    for (int i = 0; i < cant; i++) {
        if (vec[i] != nullptr && vec[i]->getEstado() == 'E' &&
            vec[i]->getCliente()->getIdentificacion() == cliente->getIdentificacion() && 
            vec[i]->getCancha()->getCodigo() == cancha->getCodigo() && 
            vec[i]->getPosicionFranja() == posicionFranja) {
			return false; //ya existe un registro de espera para este cliente, cancha y franja
        }
    }
	RegistroEspera* nuevoRegistro = new RegistroEspera(cliente, cancha, posicionFranja);
    vec[cant] = nuevoRegistro;
    cant++;
    return true;
}
void ColeccionEspera::mostrarListadoEspera() const {
    if (cant == 0) {
        cout << "La lista de espera está vacía." << endl;
        return;
    }
    cout << "================================" << endl;
    cout << "        LISTA DE ESPERA       " << endl;
    cout << "================================" << endl;
    for (int i = 0; i < cant; i++) {
        if (vec[i] != nullptr) {
            vec[i]->mostrar();
            cout << "--------------------------------" << endl;
        }
    }
}
void ColeccionEspera::verificarNotificacionesEspera(string codigoCancha, int franjaInicio, int cantidadFranjas) const {
    bool hayGente = false;
    for (int fi= franjaInicio; fi < franjaInicio + cantidadFranjas; fi++){
        for (int i = 0; i < cant; i++) {
            if (vec[i] != nullptr && vec[i]->getEstado() == 'E' && 
                vec[i]->getCancha()->getCodigo() == codigoCancha && 
                vec[i]->getPosicionFranja() == fi) {

				if (!hayGente) { //si haygente es !hayGente, significa que es la primera vez que se entra al if, entonces se imprime el mensaje de notificacion
                    cout << "\n==========================================" << endl;
                    cout << "   Hay clientes en espera para la cancha    " << endl;
                    cout << "===========================================" << endl;
                    hayGente = true;
                }
                cout << " -> Cliente: " << vec[i]->getCliente()->getNombre()
                    << " (" << vec[i]->getCliente()->getIdentificacion() << ")"
                    << " - Cancha:         |" << codigoCancha
                    << " - Franja Horaria: |" << (fi + 8) << ":00 hs" << endl;
                //se suma 8 a fi para mostrar la hora real de la franja
            }
        }
    }
    if (!hayGente) {
        cout << "\n[INFO] No hay clientes en lista de espera para el horario liberado." << endl;
    }
}
bool ColeccionEspera::cambiarEstadoEspera(int numeroConsecutivo, char nuevoEstado) {
    if (nuevoEstado >= 'a' && nuevoEstado <= 'z') {
        nuevoEstado = nuevoEstado - 32;
    }
    if (nuevoEstado != 'E' && nuevoEstado != 'A' && nuevoEstado != 'C') {
        return false;
    }

    for (int i = 0; i < cant; i++) {
        if (vec[i] != nullptr && vec[i]->getNumeroConsecutivo() == numeroConsecutivo) {
            vec[i]->setEstado(nuevoEstado);
            return true;
        }
    }
    return false;
}
//getters
int ColeccionEspera::getCant()const {
    return cant;
}
int ColeccionEspera::getMax()const {
    return max;
}
//devuelve el registro de espera en la posicion indicada
RegistroEspera* ColeccionEspera::getRegistroPorIndice(int indice)const {
    if (indice >= 0 && indice < cant) {
        return vec[indice];
    }
    return nullptr;
}