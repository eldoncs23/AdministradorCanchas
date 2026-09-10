#include <iostream>
#include "Clientes.h"

Cliente::Cliente() {
    id = "";
    nombre = "";
    telefono = "";
}

Cliente::Cliente(string id, string nombre, string telefono) {
    this->id = id;
    this->nombre = nombre;
    this->telefono = telefono;
}

Cliente::~Cliente() {}

void Cliente::setId(string id) {
    this->id = id;
}

void Cliente::setNombre(string nombre) {
    this->nombre = nombre;
}

void Cliente::setTelefono(string telefono) {
    this->telefono = telefono;
}

string Cliente::getId() {
    return id;
}

string Cliente::getNombre() {
    return nombre;
}

string Cliente::getTelefono() {
    return telefono;
}
void Cliente::mostrar() {
    cout << "Identificacion: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Telefono: " << telefono << endl;
}
