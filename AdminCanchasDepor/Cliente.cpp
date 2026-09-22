#include "Cliente.h"

Cliente::Cliente(){ 
    identificacion="";
    nombre = "";
    telefono = "";
}

Cliente::Cliente(string identificacion, string nombre, string telefono){
	this->identificacion = identificacion;
	this->nombre = nombre;
	this->telefono = telefono;
    
}

Cliente::~Cliente() {}

string Cliente::getIdentificacion() const {
	return identificacion;
}
string Cliente::getNombre() const { 
    return nombre;
}
string Cliente::getTelefono() const {
    return telefono;
}

void Cliente::setIdentificacion(string identificacion) {
    this->identificacion = identificacion;
}
void Cliente::setNombre(string nombre) {
    this->nombre = nombre;
}

void Cliente::setTelefono(string telefono) {
    this->telefono = telefono;
}
void Cliente::mostrar() const {
    cout << "Identificacion: " << identificacion << endl;
    cout << "Nombre:         " << nombre << endl;
    cout << "Telefono:       " << telefono << endl;
}
