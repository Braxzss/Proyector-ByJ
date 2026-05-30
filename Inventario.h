#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <string>
#include <libpq-fe.h>

using namespace std;

class Inventario {
private:
	PGconn* conn;

public:
	Inventario(PGconn* conexion);

	void agregarProducto();
	void mostrarProductos();
	void buscarProducto();
	void actualizarProducto();
	void eliminarProducto();
	void menuInventario();
};

#endif
#pragma once
