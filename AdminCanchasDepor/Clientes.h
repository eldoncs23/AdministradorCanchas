#pragma once

#include <string>
using namespace std;

class Cliente {

private:
    const string id;
    string nombre;
    string telefono;

public:
	//constructor y destructor
    Cliente();
    Cliente(string id, string nombre, string telefono);
    ~Cliente();
    string getId() const;
    string getNombre() const;
    string getTelefono() const;
    //void setId(string id);
    void setNombre(string nombre);
    void setTelefono(string telefono);
    void mostrar();
};