#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
private:
	int idUsuario;
	string usuario;
	string contrasena;

public:
	Usuario();
	Usuario(int id, string user, string pass);

	int getIdUsuario();
	string getUsuario();
	string getContrasena();

	void setUsuario(string user);
	void setContrasena(string pass);
};

#endif
#pragma once
