#pragma once
#include "Clientes.h"
#include "Canchas.h"
using namespace std;

class Espera {
private:
    int numeroEspera;
    int franja;
    string estado;

    Cliente* cliente;
    Cancha* cancha;

public:
    Espera();
    Espera(int numeroReserva, int franja, string estado);
    ~Espera();
    int getNumeroEspera();
    int getFranja();
    string getEstado();
    void setNumeroEspera(int numeroEspera);
    void setFranja(int franja);
    void setEstado(string estado);
    void registrar(int num, Cliente* c, Cancha* ca, int f);
    void mostrar();

};

