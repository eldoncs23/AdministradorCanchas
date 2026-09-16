#pragma once

#include <string>
using namespace std;

class Cliente {

private:
    string id;
    string nombre;
    string telefono;

public:
	//constructor y destructor
    Cliente();
    Cliente(string id, string nombre, string telefono);
    ~Cliente();
    //Set y Get
    string getId() const;
    string getNombre() const;
    string getTelefono() const;
    void setId(string id);
    void setNombre(string nombre);
    //Metodos
    void setTelefono(string telefono);
    void mostrar();
};