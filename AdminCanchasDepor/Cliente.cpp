#include "Cliente.h"

Cliente::Cliente(){ 
    identificacion="";
    nombre = "";
    apellido = "";
    telefono = "";
    
}

Cliente::Cliente(string identificacion, string nombre, string apellido, string  telefono){
	this->identificacion = identificacion;
	this->nombre = nombre;
    this->apellido = apellido;
	this->telefono = telefono;
    
}

Cliente::~Cliente() {}

string Cliente::getIdentificacion() const {
	return identificacion;
}
string Cliente::getNombre() const { 
    return nombre;
}
string Cliente::getApellido() const {
    return apellido;
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
void Cliente::setApellido(string apellido) {
    this->apellido = apellido;
}
void Cliente::setTelefono(string telefono) {
    this->telefono = telefono;
}
void Cliente::mostrar() const {
    cout << "Identificacion: " << identificacion << endl;
    cout << "Nombre:         " << nombre << endl;
    cout << "Telefono:       " << telefono << endl;
    cout << "Apellido:       " << apellido << endl;
}
string Cliente::toString() const {
    return "----------------------------------------\n"
        "  Identificacion : " + identificacion + "\n"
        "  Cliente        : " + nombre + " " + apellido + "\n"
        "  Telefono       : " + telefono + "\n"
        "----------------------------------------";
}