#pragma once

#include <string>
using namespace std;

class Cancha {

private:
    string codigo;
    string deporte;
    float precioHora;
    char disponibilidad[12];

public:
    Cancha();
    Cancha(string codigo, string deporte, float precioHora, char);
    ~Cancha();
    string getCodigo();
    string getDeporte();
    float getPrecioHora();
    char getDisponibilidad();
    void setCodigo(string codigo);
    void setDeporte(string deporte);
    void setPrecioHora(float precioHora);
    void setDisponibilidad(char disponibilidad);
    void mostrarDisponibilidad();
    void menuCanchas(Cancha canchas[], int& numCanchas);
    void registrar(string c, string d, float p);
    void mostrar();


};