#ifndef COLECCION_ESPERA_H
#define COLECCION_ESPERA_H
#include "RegistroEspera.h"
#include <iostream>
#include <string>

using namespace std;

class ColeccionEspera{
private:
    RegistroEspera** vec;
	int cant;
    int max;

public:
	ColeccionEspera(int capacidad = 10); // el enunciado dice que la capacidad es 10, pero se puede cambiar
	~ColeccionEspera();

	//metodos
    bool agregarEspera(Cliente* cliente, Cancha* cancha, int posicionFranja);
    void mostrarListadoEspera() const;
	void verificarNotificacionesEspera(string codigoCancha, int franjaInicio, int cantidadFranjas) const;
	bool cambiarEstadoEspera(int numeroConsecutivo, char nuevoEstado);
	//getters
	int getCant()const;
	int getMax()const;
	//devuelve el registro de espera en la posicion indicada
	RegistroEspera* getRegistroPorIndice(int indice)const;

};
#endif
