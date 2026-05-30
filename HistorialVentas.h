#ifndef HISTORIALVENTAS_H
#define HISTORIALVENTAS_H

#include <iostream>
#include <libpq-fe.h>

using namespace std;

class HistorialVentas {
private:
    PGconn* conn;

public:
    HistorialVentas(PGconn* conexion);

    void mostrarHistorial();
};

#endif
