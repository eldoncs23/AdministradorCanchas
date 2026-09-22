#pragma once

#include <string>
using namespace std;

class Cancha {
private:
	static const int CANT_FRANJAS = 12; // Atributo constante para la cantidad de franjas horarias, ya que son 12 franjas de 1 hora cada una
    string codigo;
    string deporte;
    float precioHora;
	char disponibilidad[CANT_FRANJAS]; // Arreglo de 12 franjas horarias, cada una representada por un carácter ('L' para libre, 'O' para ocupada)

public:
    Cancha();
	Cancha(string codigo, string deporte, float precioHora, char disInicial = 'L'); // preguntar al tutor si se puede poner un valor por defecto para el atributo disponibilidad
    ~Cancha();
    string getCodigo() const;
    string getDeporte() const;
    float getPrecioHora() const;
    //metodos de disponibilidad
	void mostrarDisponibilidad() const;
	void setEstadoFranja(int indice, char estado);

	//setts 
    void setDeporte(string deporte);
    void setPrecioHora(float precioHora);
    
	void registrar(string d, float p); // le quite string c, ya que el codigo es constante y se asigna en el constructor?
    void mostrar() const;
    
    //sub menu de gestion preguntar al tutor
    void menuCanchas(Cancha canchas[], int& numCanchas);
    


};