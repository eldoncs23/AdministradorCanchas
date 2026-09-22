#ifndef REGISTROESPERA_H
#define REGISTROESPERA_H
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Cancha.h"

using namespace std;

class RegistroEspera {
private:
    int numeroConsecutivo;
    int posicionFranja;
	char estado; // 'E' = Esperando, 'A' = Atendido/Asignado, 'C' = Cancelado
	//relaciones con otras clases
    Cliente* cliente;
    Cancha* cancha;

	static int siguienteConsecutivo; // Atributo estático para llevar el control del siguiente número de consecutivo
public:
    RegistroEspera();
	RegistroEspera(Cliente* cliente, Cancha* cancha, int posicionFranja);
    ~RegistroEspera();

    //getters
	int getNumeroConsecutivo() const;
	int getPosicionFranja() const;
	char getEstado() const;
	const Cliente* getCliente() const;
	const Cancha* getCancha() const;

    //settters
    void setEstado(char estado);

    string getEstadoTexto() const;
    void mostrar()const;

};

#endif