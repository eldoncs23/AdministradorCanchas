#ifndef RESERVA_H
#define RESERVA_H
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Cancha.h"

using namespace std;

class Reserva {
private:
	int numeroReserva; // Atributo constante para el número de reserva
    int franjaInicio;
    int cantidadFranjas;
    double montoTotal;
    bool activa;
	static int siguienteNumeroReserva; // Atributo estático para llevar el control del siguiente número de reserva
	//relaciones con otras clases
    Cliente* cliente;
    Cancha* cancha;

public:
    Reserva();
    Reserva(Cliente* cliente, Cancha* cancha, int franjaInicio, int cantidadFranjas);
    ~Reserva();
	const Cliente* getCliente() const; // se usa const para indicar que el puntero no se puede modificar y que la función no modifica el objeto
    const Cancha* getCancha() const;
	//getters
    int getNumeroReserva() const;
    int getFranjaInicio() const;
    int getCantidadFranjas() const;
    double getMontoTotal() const;
	bool isActiva() const; // se usa isActiva() en lugar de getActiva() para indicar que es un método que devuelve un valor booleano
	
	// no hay setters para numeroReserva, cliente y cancha porque son constantes y no deben modificarse después de la creación de la reserva
    
    //metodos
	bool cancelarReserva();
    void mostrar()const;

};
#endif