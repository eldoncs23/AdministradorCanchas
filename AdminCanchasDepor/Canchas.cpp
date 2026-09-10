#include "Canchas.h"
#include <iostream>

Cancha::Cancha() {
    codigo = "";
    deporte = "";
    precioHora = 0;
    for (int i = 0; i < 12; i++) {
        disponibilidad[i] = 'L';
    }
}

Cancha::Cancha(string codigo, string deporte, float precioHora, char disponibilidad) {
    this->codigo = codigo;
    this->deporte = deporte;
    this->precioHora = precioHora;
    for (int i = 0; i < 12; i++) {
        this->disponibilidad[i] = disponibilidad;
    }
}

Cancha::~Cancha() {}

string Cancha::getCodigo() {
    return codigo;
}

string Cancha::getDeporte() {
    return deporte;
}

float Cancha::getPrecioHora() {
    return precioHora;
}

char Cancha::getDisponibilidad() {
    return disponibilidad[0];
}

void Cancha::setCodigo(string codigo) {
    this->codigo = codigo;
}

void Cancha::setDeporte(string deporte) {
    this->deporte = deporte;
}

void Cancha::setPrecioHora(float precioHora) {
    this->precioHora = precioHora;
}

void Cancha::setDisponibilidad(char disponibilidad) {
    for (int i = 0; i < 12; i++) {
        this->disponibilidad[i] = disponibilidad;
    }
}

void Cancha::mostrarDisponibilidad() {
    cout << "Disponibilidad de cancha " << codigo << ": ";
    for (int i = 0; i < 12; i++) cout << "[" << i << "] " << disponibilidad[i] << " ";
    cout << endl;
}

void Cancha::registrar(string c, string d, float p) {
    codigo = c;
    deporte = d;
    precioHora = p;
}

void Cancha::mostrar() {
    cout << "Codigo: " << codigo << " | Deporte: " << deporte
        << " | Precio: " << precioHora << endl;
}

void Cancha::menuCanchas(Cancha canchas[], int& numCanchas) {
    int opcion;
    bool encontrado;
    float nuevoPrecio;
    do {

        cout << "==============================" << endl;
        cout << "      GESTION DE CANCHAS" << endl;
        cout << "==============================" << endl;
        cout << "1. Registrar cancha" << endl;
        cout << "2. Mostrar todas las canchas" << endl;
        cout << "3. Buscar cancha por codigo" << endl;
        cout << "4. Modificar precio de una cancha" << endl;
        cout << "5. Mostrar disponibilidad de una cancha" << endl;
        cout << "6. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            if (numCanchas < 10) {
                cout << "Ingrese codigo: "; cin >> codigo;
                cout << "Ingrese deporte: "; cin >> deporte;
                cout << "Ingrese precio por hora: "; cin >> precioHora;
                canchas[numCanchas].registrar(codigo, deporte, precioHora);
                numCanchas++;
                cout << "Cancha registrada exitosamente. << endl";
            }
            else {
                cout << "No se pueden registrar mas canchas.<< endl";
            }
        }
        else if (opcion == 2) {
            for (int i = 0; i < numCanchas; i++) {
                canchas[i].mostrar();
            }
        }
        else if (opcion == 3) {

            cout << "Ingrese codigo a buscar: "; cin >> codigo;
            encontrado = false;
            for (int i = 0; i < numCanchas; i++) {
                if (canchas[i].getCodigo() == codigo) {
                    canchas[i].mostrar();
                    encontrado = true;
                }
            }
            if (!encontrado) cout << "Cancha no encontrada.<< endl";
        }
        else if (opcion == 4) {
            cout << "Ingrese codigo de la cancha: "; cin >> codigo;
            encontrado = false;
            for (int i = 0; i < numCanchas; i++) {
                if (canchas[i].getCodigo() == codigo) {
                    cout << "Ingrese nuevo precio: "; cin >> nuevoPrecio;
                    canchas[i].setPrecioHora(nuevoPrecio);
                    cout << "Precio actualizado.<< endl";
                    encontrado = true;
                }
            }
            if (!encontrado) cout << "Cancha no encontrada.<< endl";
        }
        else if (opcion == 5) {
            cout << "Ingrese codigo de la cancha: "; cin >> codigo;
            encontrado = false;
            for (int i = 0; i < numCanchas; i++) {
                if (canchas[i].getCodigo() == codigo) {
                    canchas[i].mostrarDisponibilidad();
                    encontrado = true;
                }
            }
            if (!encontrado) cout << "Cancha no encontrada.<< endl";
        }
    } while (opcion != 6);
}


