#include "Canchas.h"
#include <iostream>
using namespace std; 

Cancha::Cancha() : codigo("") {
    deporte = "";
    precioHora = 0.0;
	for (int i = 0; i < CANT_FRANJAS; i++) { //cambie 12 por CANT_FRANJAS
		disponibilidad[i] = 'L'; // Inicializar todas las franjas como libres
    }
}
//constructor con parametros
Cancha::Cancha(string codigo, string deporte, float precioHora, char dispInicial) : codigo(codigo), 
    deporte(deporte), precioHora(precioHora) {
	// no se puede usar this->codigo = codigo; porque codigo es constante y se asigna en el constructor
    this -> deporte = deporte;
    this->precioHora = precioHora;
    for (int i = 0; i < CANT_FRANJAS; i++) {
        this->disponibilidad[i] = dispInicial;
    }
}

Cancha::~Cancha() {}

//getters y setters
string Cancha::getCodigo() const{
    return codigo;
}

string Cancha::getDeporte() const {
    return deporte;
}

float Cancha::getPrecioHora() const {
    return precioHora;
}
// no se hace set de codigo porque es constante y se asigna en el constructor
void Cancha::setDeporte(string deporte) {
	this->deporte = deporte; //aqui si se usa el this porque deporte no es constante y se puede modificar
}

void Cancha::setPrecioHora(float precioHora) {
    this->precioHora = precioHora;
}

void Cancha::setEstadoFranja(int indice, char estado) {
    if (indice >= 0 && indice < CANT_FRANJAS) {
        this->disponibilidad[indice] = estado;
    }
}

void Cancha::mostrarDisponibilidad() const {
    cout << "Disponibilidad de cancha " << codigo << ": ";
    for (int i = 0; i < CANT_FRANJAS; i++) {
        cout << "[" << i << "] " << disponibilidad[i] << " ";
    }
    cout << endl;
       
}

void Cancha::registrar(string d, float p) {
    deporte = d;
    precioHora = p;
}

void Cancha::mostrar() const {
    cout << "Codigo: " << codigo << " | Deporte: " << deporte
        << " | Precio: " << precioHora << endl;
}

void Cancha::menuCanchas(Cancha canchas[], int& numCanchas) {
    int opcion;
	string codTemp, depTemp;
    bool encontrado;
    float precTemp;
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
                cout << "Ingrese codigo: "; cin >> codTemp;
                cout << "Ingrese deporte: "; cin >> depTemp;
                cout << "Ingrese precio por hora: "; cin >> precTemp;
                canchas[numCanchas] = Cancha(codTemp, depTemp, precTemp);
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

            cout << "Ingrese codigo a buscar: "; cin >> codTemp;
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
            cout << "Ingrese codigo de la cancha: "; cin >> codTemp;
            encontrado = false;
            for (int i = 0; i < numCanchas; i++) {
                if (canchas[i].getCodigo() == codigo) {
                    cout << "Ingrese nuevo precio: "; cin >> precTemp;
                    canchas[i].setPrecioHora(precTemp);
                    cout << "Precio actualizado.<< endl";
                    encontrado = true;
                }
            }
            if (!encontrado) cout << "Cancha no encontrada.<< endl";
        }
        else if (opcion == 5) {
            cout << "Ingrese codigo de la cancha: "; cin >> codTemp;
            encontrado = false;
            for (int i = 0; i < numCanchas; i++) {
                if (canchas[i].getCodigo() == codTemp) {
                    canchas[i].mostrarDisponibilidad();
                    encontrado = true;
                }
            }
            if (!encontrado) cout << "Cancha no encontrada.<< endl";
        }
    } while (opcion != 6);
}
// Valida que no sea 0 o que sobrepase el numero maximo, revisa que solo si es 'L' -> Libre continue,si se cumple la 'O' -> Ocupa
bool Cancha::reservarFranja(int inicio, int cantidad) {
    if (inicio < 0 || inicio + cantidad > 12)
        return false;
    for (int i = inicio; i < inicio + cantidad; i++) {
        if (disponibilidad[i] != 'L')
            return false;
    }
    for (int i = inicio; i < inicio + cantidad; i++)
        disponibilidad[i] = 'O';
    return true;
}
//Se corre el ciclo y si encuentra opcion '0' -> Ocupa, las libera 'L' -> Libre 
void Cancha::cancelarFranja(int franjaInicial, int cantidadFranjas) {
    for (int i = franjaInicial; i < franjaInicial + cantidadFranjas; i++) {
        if (disponibilidad[i] == '0')
            disponibilidad[i] = 'L';
    }
}
