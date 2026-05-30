#ifndef CONEXION_H
#define CONEXION_H

#include <iostream>
#include <string>
#include <libpq-fe.h>

using namespace std;

class Conexion {
private:
	PGconn* conn;

public:
	Conexion();
	~Conexion();

	bool conectar();
	void cerrarConexion();

	PGconn* getConexion();

	bool validarLogin(string usuario, string contrasena);
};

#endif

