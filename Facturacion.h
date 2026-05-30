#ifndef FACTURACION_H
#define FACTURACION_H

#include <iostream>
#include <string>
#include <libpq-fe.h>

using namespace std;

class Facturacion {
private:
    PGconn* conn;

public:
    Facturacion(PGconn* conexion);

    void generarComprobante();
};

#endif
