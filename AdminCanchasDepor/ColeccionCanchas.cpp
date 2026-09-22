#include "ColeccionCanchas.h"
ColeccionCanchas::ColeccionCanchas(int capacidad) {
	this->max = capacidad;
	this->cant = 0;
	this->vec = new Cancha * [max]; //se crea un arreglo dinámico de punteros a Cancha
	for (int i = 0; i < max; i++) {
		vec[i] = nullptr;
	}
}
ColeccionCanchas::~ColeccionCanchas() {
	for (int i = 0; i < cant; i++) {
		if (vec[i] != nullptr) { //se libera la memoria de cada cancha
			delete vec[i]; //se asigna nullptr a cada puntero
			vec[i] = nullptr; //se asigna nullptr a cada puntero
		}
	}
	delete[] vec;//se libera la memoria del arreglo
	vec = nullptr; //se asigna nullptr al puntero del arreglo
}
bool ColeccionCanchas::agregarCancha(Cancha* cancha) {
	if (cancha == nullptr || cant >= max) { 
		//verificar que el puntero no sea nulo y que no se haya alcanzado la capacidad máxima
		return false;
	}
	if (buscarCancha(cancha->getCodigo()) == nullptr) { 
		//verificar que no exista la misma cancha por codigo
		return true;
	}
	vec[cant] = cancha;
	cant++;
	return false;
}
Cancha* ColeccionCanchas::buscarCancha(string codigo)const {
	for (int i = 0; i < cant; i++) {
		if (vec[i] != nullptr && vec[i]->getCodigo() == codigo) {
			return vec[i];
		}
	}
	return nullptr;
}
void ColeccionCanchas::mostrarCanchas() const {
	if (cant == 0) {
		cout << "No hay canchas registradas." << endl;
		return;

	}
	cout << "========================================" << endl;
	cout << "            LISTA DE CANCHAS            " << endl;
	cout << "========================================" << endl;
	for (int i = 0; i < cant; i++) {
		if (vec[i] != nullptr) {
			vec[i]->mostrar();
			cout << "----------------------------------------" << endl;
		}
	}
}
//getters
int ColeccionCanchas::getCant()const {
	return cant;
}
int ColeccionCanchas::getMax()const { 
	return max;
}
Cancha* ColeccionCanchas::getCanchaPorIndice(int indice)const {
	if (indice >= 0 && indice < cant && vec[indice] != nullptr) { 
		//verificar que el indice sea valido y que el puntero no sea nulo
		return vec[indice];
	}
	return nullptr;
}