#include "Usuario.h"

Usuario::Usuario() {
	idUsuario = 0;
	usuario = "";
	contrasena = "";
}

Usuario::Usuario(int id, string user, string pass) {
	idUsuario = id;
	usuario = user;
	contrasena = pass;
}

int Usuario::getIdUsuario() { return idUsuario; }
string Usuario::getUsuario() { return usuario; }
string Usuario::getContrasena() { return contrasena; }

void Usuario::setUsuario(string user) { usuario = user; }
void Usuario::setContrasena(string pass) { contrasena = pass; }
