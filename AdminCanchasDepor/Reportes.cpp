#include "Reportes.h"
void Reportes::canchaConMasReservasActivas(const ColeccionCanchas& canchas, const ColeccionReservas& reservas) {
    cout << "\n========================================================" << endl;
    cout << "   REPORTE: CANCHA CON MAYOR CANTIDAD DE RESERVAS ACTIVAS" << endl;
    cout << "========================================================" << endl;

    if (canchas.getCant() == 0) {
        cout << "No hay canchas registradas en el sistema." << endl;
        return;
    }

    cout << "DETALLE DE RESERVAS POR CANCHA:" << endl;
    cout << "--------------------------------------------------------" << endl;

    int maxReservas = -1;
    Cancha* canchaGanadora = nullptr;

    // recorrer cada cancha para contar sus reservas activas
    for (int i = 0; i < canchas.getCant(); i++) {
        Cancha* canchaActual = canchas.getCanchaPorIndice(i);
        if (canchaActual == nullptr) continue;

        int contadorActivas = 0;

        // recorrer todas las reservas
        for (int j = 0; j < reservas.getCant(); j++) {
            Reserva* res = reservas.getReservaPorIndice(j);
            if (res != nullptr && res->isActiva()) {
                // comprobar si la reserva pertenece a la cancha actual
                if (res->getCancha() != nullptr && res->getCancha()->getCodigo() == canchaActual->getCodigo()) {
                    contadorActivas++;
                }
            }
        }

        cout << "Cancha: " << canchaActual->getCodigo()
            << " | Reservas Activas: " << contadorActivas << endl;

        if (contadorActivas > maxReservas) {
            maxReservas = contadorActivas;
            canchaGanadora = canchaActual;
        }
    }

    cout << "--------------------------------------------------------" << endl;
    if (canchaGanadora != nullptr && maxReservas > 0) {
        cout << "RESULTADO:" << endl;
        cout << "La cancha con mayor cantidad de reservas activas es: "
            << canchaGanadora->getCodigo() << " con " << maxReservas << " reserva(s)." << endl;
    }
    else {
        cout << "RESULTADO: No existen reservas activas actualmente." << endl;
    }
    cout << "========================================================\n" << endl;
}
void Reportes::clienteConMasReservasActivas(const ColeccionClientes& clientes, const ColeccionReservas& reservas) {
    cout << "\n========================================================" << endl;
    cout << "  REPORTE: CLIENTE CON MAYOR CANTIDAD DE RESERVAS ACTIVAS" << endl;
    cout << "========================================================" << endl;

    if (clientes.getCant() == 0) {
        cout << "No hay clientes registrados en el sistema." << endl;
        return;
    }

    cout << "DETALLE DE RESERVAS POR CLIENTE:" << endl;
    cout << "--------------------------------------------------------" << endl;

    int maxReservas = -1;
    const Cliente* clienteGanador = nullptr; // se cambia a const Cliente* para coincidir con res->getCliente()

    // recorremos las reservas para evaluar cada cliente
    for (int i = 0; i < reservas.getCant(); i++) {
        const Reserva* res = reservas.getReservaPorIndice(i);
        if (res != nullptr && res->isActiva() && res->getCliente() != nullptr) {
            string idCliente = res->getCliente()->getIdentificacion();

            // contar cuantas reservas activas tiene este cliente
            int contadorActivas = 0;
            for (int j = 0; j < reservas.getCant(); j++) {
                const Reserva* r2 = reservas.getReservaPorIndice(j);
                if (r2 != nullptr && r2->isActiva() && r2->getCliente() != nullptr) {
                    if (r2->getCliente()->getIdentificacion() == idCliente) {
                        contadorActivas++;
                    }
                }
            }

            if (contadorActivas > maxReservas) {
                maxReservas = contadorActivas;
                clienteGanador = res->getCliente(); // ahora la asignacion es valida
            }
        }
    }

    if (clienteGanador != nullptr && maxReservas > 0) {
        cout << "Cliente: " << clienteGanador->getNombre()
            << " (ID: " << clienteGanador->getIdentificacion() << ")" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "RESULTADO:" << endl;
        cout << "El cliente con mas reservas activas es " << clienteGanador->getNombre()
            << " con un total de " << maxReservas << " reserva(s)." << endl;
    }
    else {
        cout << "RESULTADO: No hay reservas activas registradas para ningun cliente." << endl;
    }
    cout << "========================================================\n" << endl;
}
void Reportes::ingresoTotalReservasActivas(const ColeccionReservas& reservas) {
    cout << "\n========================================================" << endl;
    cout << "    REPORTE: INGRESO TOTAL POR RESERVAS ACTIVAS" << endl;
    cout << "========================================================" << endl;

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
        if (res != nullptr && res->isActiva()) {
            double montoReserva = res->getMontoTotal(); // O calculo: res->getCantidadFranjas() * precio
            ingresoTotal += montoReserva;
            contadorActivas++;

            cout << "Reserva #" << res->getNumeroReserva()
                << " | Cliente: " << (res->getCliente() ? res->getCliente()->getNombre() : "N/A")
                << " | Cancha: " << (res->getCancha() ? res->getCancha()->getCodigo() : "N/A")
                << " | Franjas: " << res->getCantidadFranjas()
                << " | Monto: $" << montoReserva << endl;
        }
    }

    cout << "--------------------------------------------------------" << endl;
    cout << "TOTAL DE RESERVAS ACTIVAS: " << contadorActivas << endl;
    cout << "INGRESO TOTAL GENERADO   : $" << ingresoTotal << endl;
    cout << "========================================================\n" << endl;
}
void Reportes::porcentajeOcupacionPorCancha(const ColeccionCanchas& canchas, const ColeccionReservas& reservas) {
    cout << "\n========================================================" << endl;
    cout << "     REPORTE: PORCENTAJE DE OCUPACION POR CANCHA" << endl;
    cout << "========================================================" << endl;

    if (canchas.getCant() == 0) {
        cout << "No hay canchas registradas." << endl;
        return;
    }

    const int TOTAL_FRANJAS_DIA = 24; // O la cantidad total de franjas configuradas por jornada

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
    cout << "\n========================================================" << endl;
    cout << "   REPORTE: HORAS CON MAYOR Y MENOR DEMANDA DE RESERVAS" << endl;
    cout << "========================================================" << endl;

    // Crear arreglo dinamico para contar reservas por cada franja horaria
    int* conteoFranjas = new int[totalFranjasDia];
    for (int i = 0; i < totalFranjasDia; i++) {
        conteoFranjas[i] = 0;
    }

    // Contabilizar cuantas reservas ocupan cada franja
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

    cout << "DETALLE DE DEMANDA POR FRANJA HORARIA:" << endl;
    cout << "--------------------------------------------------------" << endl;

    int maxDemanda = conteoFranjas[0];
    int minDemanda = conteoFranjas[0];

    for (int i = 0; i < totalFranjasDia; i++) {
        cout << "Franja " << i << " (Hora " << i << ":00): "
            << conteoFranjas[i] << " reserva(s)" << endl;

        if (conteoFranjas[i] > maxDemanda) maxDemanda = conteoFranjas[i];
        if (conteoFranjas[i] < minDemanda) minDemanda = conteoFranjas[i];
    }

    cout << "--------------------------------------------------------" << endl;
    cout << "RESULTADOS:" << endl;

    cout << "- Franja(s) de MAYOR demanda (" << maxDemanda << " reservas): ";
    for (int i = 0; i < totalFranjasDia; i++) {
        if (conteoFranjas[i] == maxDemanda) {
            cout << "[Franja " << i << "] ";
        }
    }
    cout << endl;

    cout << "- Franja(s) de MENOR demanda (" << minDemanda << " reservas): ";
    for (int i = 0; i < totalFranjasDia; i++) {
        if (conteoFranjas[i] == minDemanda) {
            cout << "[Franja " << i << "] ";
        }
    }
    cout << endl;

    // Liberar memoria dinamica del arreglo auxiliar
    delete[] conteoFranjas;

    cout << "========================================================\n" << endl;
}