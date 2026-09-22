#pragma once
#include "Cliente.h"
#include "Cancha.h"
using namespace std;
class Cliente;
class Cancha;

class Espera {
private:
	static int contadorSecuencia; //contador global para generar IDs de espera únicos
	const int numeroEspera; // Atributo constante para el número de espera
    int franja;
	string estado; // "esperando", "cancelada", "atendido
	//relaciones con otras clases
    Cliente* cliente;
    Cancha* cancha;

public:
    Espera();
	Espera(Cliente* c, Cancha* ca, int franja, string estado = "esperando");
    ~Espera();

    //gets
	int getNumeroEspera() const;
	int getFranja() const;
	string getEstado() const;
	Cliente* getCliente() const;
	Cancha* getCancha() const;

    //settters
    void setFranja(int franja);
    void setEstado(string estado);

    void registrar(Cliente* c, Cancha* ca, int f);
    void mostrar()const;

};

