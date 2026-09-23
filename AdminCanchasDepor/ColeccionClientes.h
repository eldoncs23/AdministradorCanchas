#ifndef COLECCIONCLIENTES_H
#define COLECCIONCLIENTES_H
#include "Cliente.h"
#include <iostream>
#include <string>

using namespace std;

class ColeccionClientes{
private:
	Cliente** vec; //puntero a puntero de Cliente, para crear un arreglo dinámico de punteros a Cliente
	int cant;
	int max;

public:
	ColeccionClientes(int capacidad = 100); //como solicita el enunciado, se puede pasar un valor por defecto de 100 clientes
	~ColeccionClientes();
	//metodos
	bool agregarCliente(Cliente* cliente);
	Cliente* buscarCliente(string identificacion)const;
	// metodo indispensable para iterar en la clase Reportes
	Cliente* getClientePorIndice(int index) const;
	void mostrarClientes()const;

	int getCant()const;
	int getMax()const;
};

#endif