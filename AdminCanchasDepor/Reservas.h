#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cliente;
class Cancha;

class Reserva {

private:
    int numeroReserva;
    int franjaInicial;
    int cantidadFranjas;
    float monto;
    bool activa;

    Cliente* cliente;
    Cancha* cancha;

public:
    Reserva();
    Reserva(int numeroReserva, int franjaInicial, int cantidadFranjas, float monto, bool activa);
    ~Reserva();
    int getNumeroReserva();
    int getFranjaInicial();
    int getCantidadFranjas();
    float getMonto();
    bool getActiva();
    void setNumeroReserva(int numeroReserva);
    void setFranjaInicial(int franjaInicial);
    void setCantidadFranjas(int cantidadFranjas);
    void setMonto(float monto);
    void setActiva(bool activa);
    void mostrar();
    void registrar(int num, Cliente* c, Cancha* ca, int fi, int cf);

};