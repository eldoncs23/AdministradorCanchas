#ifndef CANCHA_H
#define CANCHA_H
#include <iostream>
#include <string>
using namespace std;
const int CANT_FRANJAS = 12; // Atributo constante para la cantidad de franjas horarias, ya que son 12 franjas de 1 hora cada una
class Cancha {
private:
    string codigo;
    string deporte;
    double precioPorHora;
	char franjas[CANT_FRANJAS]; // Arreglo de 12 franjas horarias, cada una representada por un carácter ('L' para libre, 'O' para ocupada, M = Mantenimiento)

public:
    Cancha();
	Cancha(string codigo, string deporte, double precioPorHora);
    ~Cancha();
	//getters
    string getCodigo() const;
    string getDeporte() const;
    float getPrecioPorHora() const;
	char getEstadoFranja(int indiceFranja) const; //metodo para obtener el estado de una franja horaria específica
	//setts 
    void setDeporte(string deporte);
	void setCodigo(string codigo);
	void setPrecioPorHora(double precioPorHora);

    //metodos para cambiar estados de franjas
	bool setMantenimientoFranja(int indiceFranja);
	bool retirarMantenimientoFranja(int indiceFranja);
	bool ocuparFranja(int indiceFranja);
	bool liberarFranja(int indiceFranja);

    //menu visual de las franjas y estados de cada una
    void mostrarDisponibilidad(string fecha = "18/09/2026") const;
    void cambiarDisponibilidad(int indiceFranja, char nuevoEstado);
    void mostrar() const;
};
#endif