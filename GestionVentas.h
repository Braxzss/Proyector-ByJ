#ifndef GESTIONVENTAS_H
#define GESTIONVENTAS_H

#include <iostream>
#include <string>
#include <libpq-fe.h>

using namespace std;

class GestionVentas {
private:
    PGconn* conn;

public:
    GestionVentas(PGconn* conexion);

    void registrarVenta();
    void mostrarProductosDisponibles();
};

#endif#pragma once
