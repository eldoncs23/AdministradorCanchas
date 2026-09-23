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
	string apellido; 

public:
	//constructor y destructor
    Cliente();
    Cliente(string identificacion, string nombre, string apellido, string  telefono);
    ~Cliente();
	//getters y setters
    string getIdentificacion() const;
    string getNombre() const;
    string getTelefono() const;
    string getApellido() const;
    void setIdentificacion(string identificacion);
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setTelefono(string telefono);
    string toString() const;
    void mostrar() const;
};

#endif