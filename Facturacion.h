#ifndef FACTURACION_H
#define FACTURACION_H

#include <iostream>
#include <string>
#include <libpq-fe.h>
#include "Reporte.h"

using namespace std;

class Facturacion : public Reporte {
private:
    PGconn* conn;

public:
    Facturacion(PGconn* conexion);

    void generarComprobante();

    void mostrar() override;
};

#endif