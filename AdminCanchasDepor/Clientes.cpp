#include <iostream>
#include "Clientes.h"
using namespace std;

Cliente::Cliente() : id("") { 
    nombre = "";
    telefono = "";
}

Cliente::Cliente(string id, string nombre, string telefono)
    : id(id), nombre(nombre), telefono(telefono){
    
}

Cliente::~Cliente() {}

void Cliente::setNombre(string nombre) {
    this->nombre = nombre;
}

void Cliente::setTelefono(string telefono) {
    this->telefono = telefono;
}

string Cliente::getId() const {
    return id;
}

string Cliente::getNombre() const {
    return nombre;
}

string Cliente::getTelefono() const     {
    return telefono;
}
void Cliente::mostrar() {
    cout << "Identificacion: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Telefono: " << telefono << endl;
}
