#include "ColeccionClientes.h"

ColeccionClientes::ColeccionClientes(int capacidad) {
	this->max = capacidad;
    this->cant = 0;
	this->vec = new Cliente * [max]; //se crea un arreglo dinámico de punteros a Cliente
	for (int i = 0; i < max; i++) {
		vec[i] = nullptr;
	}
} 
ColeccionClientes::~ColeccionClientes() {
	//este metodo destruye la coleccion de clientes, liberando la memoria de cada cliente y del arreglo
	for (int i = 0; i < cant; i++) {
		if(vec[i] != nullptr) {
			delete vec[i]; //se libera la memoria de cada cliente
			vec[i] = nullptr; //se asigna nullptr a cada puntero	
		}
	}
	delete[] vec; //se libera la memoria del arreglo
	vec = nullptr; //se asigna nullptr al puntero del arreglo
}
//metodos
bool ColeccionClientes::agregarCliente(Cliente* cliente) {
	if (cliente == nullptr || cant >= max) {
		return false;
	}
	//verificar que no exista la misma identificacion
	if (buscarCliente(cliente->getIdentificacion()) != nullptr) {
		return false;
	}
	vec[cant] = cliente;
	cant++;
	return true;
}

Cliente* ColeccionClientes::buscarCliente(string identificacion)const {
	for (int i = 0; i < cant; i++) {
		if (vec[i] != nullptr && vec[i]->getIdentificacion() == identificacion) {
			return vec[i];
		}
	}
	return nullptr;
}
void ColeccionClientes::mostrarClientes() const {
	if(cant == 0) {
		cout << "No hay clientes registrados." << endl;
		return;
	}
	cout << "================================" << endl;
	cout << "        LISTA DE CLIENTES       " << endl;
	cout << "================================" << endl;
	for (int i = 0; i < cant; i++) {
		if(vec[i] != nullptr) {
			vec[i]->mostrar();
			cout << "--------------------------------" << endl;
		}
	}
}

int ColeccionClientes::getCant()const {
	return cant;
}
int ColeccionClientes::getMax()const {
	return max;
}