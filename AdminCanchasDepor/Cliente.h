#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
using namespace std;

class Cliente {

private:
    string identificacion;
    string nombre;
    string telefono;

public:
	//constructor y destructor
    Cliente();
    Cliente(string identificacion, string nombre, string telefono);
    ~Cliente();
	//getters y setters
    string getIdentificacion() const;
    string getNombre() const;
    string getTelefono() const;
    void setIdentificacion(string identificacion);
    void setNombre(string nombre);
    void setTelefono(string telefono);
    void mostrar() const;
};

#endif