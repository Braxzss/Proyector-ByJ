#include "Usuario.h"
#include <iostream>

using namespace std;

Usuario::Usuario()
    : Persona()
{
    usuario = "";
    contrasena = "";
}

Usuario::Usuario(
    int id,
    string nombre,
    string usuario,
    string contrasena
)
    : Persona(id, nombre)
{
    this->usuario = usuario;
    this->contrasena = contrasena;
}

string Usuario::getUsuario() {
    return usuario;
}

string Usuario::getContrasena() {
    return contrasena;
}

void Usuario::setUsuario(string usuario) {
    this->usuario = usuario;
}

void Usuario::setContrasena(string contrasena) {
    this->contrasena = contrasena;
}

void Usuario::mostrarDatos() {
    cout << "\n===== USUARIO =====";
    Persona::mostrarDatos();
    cout << "Usuario: " << usuario << endl;
}