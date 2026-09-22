#include "Cancha.h"

Cancha::Cancha() {
    codigo = "";
    deporte = "";
    precioPorHora = 0.0;
	for (int i = 0; i < CANT_FRANJAS; i++) { //cambie 12 por CANT_FRANJAS
		franjas[i] = 'L'; // Inicializar todas las franjas como libres
    }
}
//constructor con parametros
Cancha::Cancha(string codigo, string deporte, float precioPorHora) {
	this->codigo = codigo;
    this->deporte = deporte;
	this->precioPorHora = precioPorHora;
	for (int i = 0; i < CANT_FRANJAS; i++) {
		franjas[i] = 'L';
	}
}

Cancha::~Cancha() {}

//getters y setters
string Cancha::getCodigo() const{
    return codigo;
}

string Cancha::getDeporte() const {
    return deporte;
}

float Cancha::getPrecioPorHora() const {
    return precioPorHora;
}

char Cancha::getEstadoFranja(int indiceFranja) const {
    if (indiceFranja >= 0 && indiceFranja < CANT_FRANJAS) {
        return franjas[indiceFranja];
    }
    return 'L'; // Devolver 'L' si el índice es inválido
}

//setters
void Cancha::setCodigo(string codigo) {
	this->codigo = codigo;
}
void Cancha::setDeporte(string deporte) {
	this->deporte = deporte; //aqui si se usa el this porque deporte no es constante y se puede modificar
}
void Cancha::setPrecioPorHora(float precioPorHora) {
    this->precioPorHora = precioPorHora;
}

bool Cancha::setMantenimientoFranja(int indiceFranja) {
	// no se puede poner en mantenimiento una franja que ya esté ocupada
    if (indiceFranja >= 0 && indiceFranja < CANT_FRANJAS) {
        if (franjas[indiceFranja] == 'L') {
            franjas[indiceFranja] = 'M';
            return true;
        }
    }
    return false;
}

bool Cancha::retirarMantenimientoFranja(int indiceFranja) {
	if (indiceFranja >= 0 && indiceFranja < CANT_FRANJAS) {
		if (franjas[indiceFranja] == 'M') {
			franjas[indiceFranja] = 'L';
			return true;
		}
	}
	return false;
}

bool Cancha::ocuparFranja(int indiceFranja) {
    if (indiceFranja >= 0 && indiceFranja < CANT_FRANJAS && franjas[indiceFranja] == 'L') {
        franjas[indiceFranja] = 'O';
        return true;
    }
    return false;
}

bool Cancha::liberarFranja(int indiceFranja) {
	if (indiceFranja >= 0 && indiceFranja < CANT_FRANJAS && franjas[indiceFranja] == 'O') {
		franjas[indiceFranja] = 'L';
		return true;
	}
	return false;
}

void Cancha::mostrarDisponibilidad(string fecha) const {
    cout << "DISPONIBILIDAD DE LA CANCHA " << codigo << endl;
    cout << "Fecha: " << fecha << endl;
	cout << "| 8:00| 9:00| 10:00| 11:00| 12:00| 13:00| 14:00| 15:00| 16:00| 17:00| 18:00| 19:00|" << endl;
	cout << "|";
	for (int i = 0; i < CANT_FRANJAS; i++) {
		cout << "  " << franjas[i] << "  |";
	}
	cout << endl;
	cout << endl;
	cout << "L = Libre, O = Ocupada, M = Mantenimiento" << endl;
}

void Cancha::mostrar() const {
    cout << " | Codigo:  " << codigo << endl;
	cout << " | Deporte: " << deporte << endl;
	cout << " | Precio:  " << precioPorHora << endl;
}