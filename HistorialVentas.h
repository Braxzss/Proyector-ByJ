#ifndef HISTORIALVENTAS_H
#define HISTORIALVENTAS_H

#include <iostream>
#include <libpq-fe.h>
#include "Reporte.h"

using namespace std;

class HistorialVentas : public Reporte {
private:
    PGconn* conn;

public:
    HistorialVentas(PGconn* conexion);

    void mostrarHistorial();

    void mostrar() override;
};

#endif