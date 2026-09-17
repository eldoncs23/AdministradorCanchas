#pragma once
#include <string>
using namespace std;

class Cancha {
private:
	static const int CANT_FRANJAS = 12; // Atributo constante para la cantidad de franjas horarias, ya que son 12 franjas de 1 hora cada una
    string codigo;
    string deporte;
	float precioHora; // Lo puse double por recomendacion de Visual, me tiraba warning
	char disponibilidad[CANT_FRANJAS]; // Arreglo de 12 franjas horarias, cada una representada por un carácter ('L' para libre, 'O' para ocupada)

public:
    //Constructores y destructor
    Cancha();
	Cancha(string codigo, string deporte, float precioHora, char dispInicial = 'L'); // preguntar al tutor si se puede poner un valor por defecto para el atributo disponibilidad
    //Respondiendo a esto si lo dejo solo con '' me tira error que debe tener algun caracter
    ~Cancha();
    //Set y Get
    string getCodigo() const;
    string getDeporte() const;
    float getPrecioHora() const;
    void setEstadoFranja(int indice, char estado);
    void setDeporte(string deporte);
    void setPrecioHora(float precioHora);

    //Metodos
	void mostrarDisponibilidad() const;
    bool reservarFranja(int inicio, int cantidad);
    void cancelarFranja(int inicio, int cantidad);
	void registrar(string d, float p); 
    void mostrar() const;
    
    //sub menu de gestion preguntar al tutor
    //Aca era lo que te decia de crear lo de principio de responsabilidad unica
    void menuCanchas(Cancha canchas[], int& numCanchas);

    
    
};