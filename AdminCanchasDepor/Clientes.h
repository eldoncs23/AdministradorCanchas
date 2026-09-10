#pragma once

#include <string>
using namespace std;

class Cliente {

private:
    string id;
    string nombre;
    string telefono;

public:

    Cliente();
    Cliente(string id, string nombre, string telefono);
    ~Cliente();
    string getId();
    string getNombre();
    string getTelefono();
    void setId(string id);
    void setNombre(string nombre);
    void setTelefono(string telefono);
    void mostrar();
};