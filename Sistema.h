#ifndef SISTEMA_H
#define SISTEMA_H

#include "Conexion.h"
#include "Inventario.h"

class Sistema {
private:
    Conexion db;

public:
    void iniciar();
};

#endif