#include "Reportes.h"

void Reportes::canchaConMasReservasActivas(const ColeccionCanchas& coleccionCanchas, const ColeccionReservas& coleccionReservas) {
	int totalCanchas = coleccionCanchas.getCant();
	if (totalCanchas == 0) {
		cout << "No hay canchas registradas en el sistema." << endl;
		return;
	}
	cout << "DETALLE DE RESERVAS POR CANCHA:" << endl;
	cout << "--------------------------------------------------------" << endl;
	int maxReservas = 0;
    for (int i = 0; i < totalCanchas; i++) {
        Cancha* canchaActual = coleccionCanchas.getCanchaPorIndice(i);
        if (canchaActual != nullptr) {
            int conteo = coleccionReservas.contarReservasActivasPorCancha(canchaActual->getCodigo());
            if (conteo > maxReservas) {
                maxReservas = conteo;
            }
        }
    }
    // Si el maximo es 0, no hay reservas activas registradas para ninguna cancha
    if (maxReservas == 0) {
        cout << "NO existen reservas activas en el sistema actualmente." << endl;
        return;
    }
	//imprimir las canchas que empatan en el máximo de reservas activas
    cout << "Mayor cantidad de reservas activas encontradas: " << maxReservas << endl << endl;
    for (int i = 0; i < totalCanchas; i++) {
        Cancha* canchaActual = coleccionCanchas.getCanchaPorIndice(i);
        if (canchaActual != nullptr) {
            int conteo = coleccionReservas.contarReservasActivasPorCancha(canchaActual->getCodigo());
            if (conteo == maxReservas) {
                canchaActual->mostrar();
                cout << "Total de reservas activas: " << conteo << endl;
                cout << "-----------------------------------------------------" << endl;
            }
        }
    }
    
}
void Reportes::clienteConMasReservasActivas(const ColeccionClientes& clientes, const ColeccionReservas& reservas) {
    
    if (clientes.getCant() == 0) {
        cout << "No hay clientes registrados en el sistema." << endl;
        return;
    }

    cout << "DETALLE DE RESERVAS POR CLIENTE:" << endl;
    cout << "--------------------------------------------------------" << endl;

    int maxReservas = 0;

	// recorrer cada cliente para contar sus reservas activas
    for (int i = 0; i < clientes.getCant(); i++) {
        Cliente* clienteActual = clientes.getClientePorIndice(i);
        if (clienteActual == nullptr) continue;

        int contadorActivas = reservas.contarReservasActivasPorCliente(clienteActual->getIdentificacion());

        cout << "Cliente: " << clienteActual->getNombre()
            << " (" << clienteActual->getIdentificacion() << ")"
            << " | Reservas Activas: " << contadorActivas << endl;

        if (contadorActivas > maxReservas) {
            maxReservas = contadorActivas;
        }
    }

    cout << "--------------------------------------------------------" << endl;
    if (maxReservas == 0) {
        cout << "RESULTADO: No existen reservas activas actualmente." << endl;
        cout << "===================================================\n" << endl;
        return;
    }

    // imprimir los clientes que empatan en el máximo de reservas
    cout << "RESULTADO: Cliente(s) con mayor cantidad de reservas activas (" << maxReservas << "):" << endl;
    for (int i = 0; i < clientes.getCant(); i++) {
        Cliente* clienteActual = clientes.getClientePorIndice(i);
        if (clienteActual == nullptr) continue;

        int contadorActivas = reservas.contarReservasActivasPorCliente(clienteActual->getIdentificacion());

        if (contadorActivas == maxReservas) {
            cout << " -> Cliente: " << clienteActual->getNombre()
                << " | ID: " << clienteActual->getIdentificacion()
                << " | Reservas Activas: " << contadorActivas << endl;
        }
    }
    cout << "========================================================\n" << endl;
}
void Reportes::ingresoTotalReservasActivas(const ColeccionReservas& reservas) {


    if (reservas.getCant() == 0) {
        cout << "No hay reservas en el sistema." << endl;
        return;
    }

    cout << "DETALLE DE INGRESOS POR RESERVA ACTIVA:" << endl;
    cout << "--------------------------------------------------------" << endl;

    double ingresoTotal = 0.0;
    int contadorActivas = 0;

    for (int i = 0; i < reservas.getCant(); i++) {
        Reserva* res = reservas.getReservaPorIndice(i);

        // verificamos que la reserva exista y esté activa
        if (res != nullptr && res->isActiva()) {
            double montoReserva = res->getMontoTotal();
            ingresoTotal += montoReserva;
            contadorActivas++;

            // obtener el nombre del cliente de forma segura
            string nombreCliente = "N/A";
            if (res->getCliente() != nullptr) {
                nombreCliente = res->getCliente()->getNombre();
            }

			// obtener el código de la cancha de forma segura
            string codigoCancha = "N/A";
            if (res->getCancha() != nullptr) {
                codigoCancha = res->getCancha()->getCodigo();
            }

			// imprimir la información de la reserva activa
            cout << "Reserva #" << res->getNumeroReserva()
                << " | Cliente: " << nombreCliente
                << " | Cancha: " << codigoCancha
                << " | Franjas: " << res->getCantidadFranjas()
                << " | Monto: " << montoReserva << " Colones" << endl;
        }
    }

    cout << "--------------------------------------------------------" << endl;
    cout << "TOTAL DE RESERVAS ACTIVAS: " << contadorActivas << endl;
    cout << "INGRESO TOTAL GENERADO   : " << ingresoTotal << " Colones" << endl;
    cout << "========================================================\n" << endl;
}

void Reportes::porcentajeOcupacionPorCancha(const ColeccionCanchas& canchas, const ColeccionReservas& reservas) {

    if (canchas.getCant() == 0) {
        cout << "No hay canchas registradas." << endl;
        return;
    }

    const int TOTAL_FRANJAS_DIA = 12; //12 franjas horarias segun enunciado

    cout << "DETALLE DE OCUPACION (Sobre " << TOTAL_FRANJAS_DIA << " franjas diarias totales):" << endl;
    cout << "--------------------------------------------------------" << endl;

    for (int i = 0; i < canchas.getCant(); i++) {
        Cancha* canchaActual = canchas.getCanchaPorIndice(i);
        if (canchaActual == nullptr) continue;

        int franjasOcupadas = 0;

        for (int j = 0; j < reservas.getCant(); j++) {
            Reserva* res = reservas.getReservaPorIndice(j);
            if (res != nullptr && res->isActiva()) {
                if (res->getCancha() != nullptr && res->getCancha()->getCodigo() == canchaActual->getCodigo()) {
                    franjasOcupadas += res->getCantidadFranjas();
                }
            }
        }

        double porcentaje = ((double)franjasOcupadas / TOTAL_FRANJAS_DIA) * 100.0;

        cout << "Cancha: " << canchaActual->getCodigo()
            << " | Franjas Ocupadas: " << franjasOcupadas << " / " << TOTAL_FRANJAS_DIA
            << " | Ocupacion: " << porcentaje << "%" << endl;
    }

    cout << "========================================================\n" << endl;
}
void Reportes::horasMayorYMenorDemanda(const ColeccionReservas& reservas, int totalFranjasDia) {

    // Arreglo dinámico según las franjas especificadas (12 franjas: 0 a 11)
    int* conteoFranjas = new int[totalFranjasDia];
    for (int i = 0; i < totalFranjasDia; i++) {
        conteoFranjas[i] = 0;
    }

    // Contabilizar franjas ocupadas por reservas activas
    for (int i = 0; i < reservas.getCant(); i++) {
        Reserva* res = reservas.getReservaPorIndice(i);
        if (res != nullptr && res->isActiva()) {
            int inicio = res->getFranjaInicio();
            int duracion = res->getCantidadFranjas();

            for (int f = inicio; f < inicio + duracion && f < totalFranjasDia; f++) {
                conteoFranjas[f]++;
            }
        }
    }

    cout << "DETALLE DE DEMANDA POR FRANJA HORARIA (08:00 A 20:00):" << endl;
    cout << "--------------------------------------------------------" << endl;

    // Mostrar en dos columnas si son 12 franjas para mejorar visualización
    if (totalFranjasDia == 12) {
        for (int i = 0; i < 6; i++) {
            int h1 = 8 + i;
            int h2 = 8 + i + 6;
            cout << "Franja " << (i < 10 ? " " : "") << i << " (" << (h1 < 10 ? "0" : "") << h1 << ":00-" << (h1 + 1 < 10 ? "0" : "") << h1 + 1 << ":00): " << conteoFranjas[i] << " res. | "
                 << "Franja " << (i + 6 < 10 ? " " : "") << i + 6 << " (" << h2 << ":00-" << (h2 + 1 < 10 ? "0" : "") << h2 + 1 << ":00): " << conteoFranjas[i + 6] << " res." << endl;
        }
    }
    else {
        for (int i = 0; i < totalFranjasDia; i++) {
            int h = 8 + i;
            cout << "Franja " << i << " (" << (h < 10 ? "0" : "") << h << ":00-" << (h + 1 < 10 ? "0" : "") << h + 1 << ":00): " << conteoFranjas[i] << " reserva(s)" << endl;
        }
    }

    int maxDemanda = conteoFranjas[0];
    int minDemanda = conteoFranjas[0];
    for (int i = 1; i < totalFranjasDia; i++) {
        if (conteoFranjas[i] > maxDemanda) maxDemanda = conteoFranjas[i];
        if (conteoFranjas[i] < minDemanda) minDemanda = conteoFranjas[i];
    }

    cout << "--------------------------------------------------------" << endl;
    cout << "RESULTADOS:" << endl;

    cout << "- Franja(s) de MAYOR demanda (" << maxDemanda << " reservas):" << endl;
    for (int i = 0; i < totalFranjasDia; i++) {
        if (conteoFranjas[i] == maxDemanda) {
            int h = 8 + i;
            cout << "  * Franja " << i << " (" << (h < 10 ? "0" : "") << h << ":00 a " << (h + 1 < 10 ? "0" : "") << h + 1 << ":00)" << endl;
        }
    }

    cout << "- Franja(s) de MENOR demanda (" << minDemanda << " reservas):" << endl;
    for (int i = 0; i < totalFranjasDia; i++) {
        if (conteoFranjas[i] == minDemanda) {
            int h = 8 + i;
            cout << "  * Franja " << i << " (" << (h < 10 ? "0" : "") << h << ":00 a " << (h + 1 < 10 ? "0" : "") << h + 1 << ":00)" << endl;
        }
    }

    delete[] conteoFranjas;
    cout << "========================================================\n" << endl;
}