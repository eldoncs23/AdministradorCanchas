#ifndef COLECCIONCANCHAS_H
#define COLECCIONCANCHAS_H
#include "Cancha.h"
#include <iostream>
#include <string>

using namespace std;

class ColeccionCanchas{
private:
	Cancha** vec;
	int cant;
	int max;
public:
	ColeccionCanchas(int capacidad = 10); // el enunciado dice que la capacidad es 10, pero se puede cambiar
	~ColeccionCanchas();
	bool agregarCancha(Cancha* codigo);
	Cancha* buscarCancha(string codigo)const;
	void mostrarCanchas() const;
	bool modificarPrecio(string codigo, float nuevoPrecio);
	void mostrarDisponibilidad(string codigo) const;
	//getters
	int getCant()const;
	int getMax()const;
	Cancha* getCanchaPorIndice(int indice)const;
};

#endif