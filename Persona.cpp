#include "Persona.h"

Persona::Persona() {
    id = 0;
    nombre = "";
}

Persona::Persona(int id, string nombre) {
    this->id = id;
    this->nombre = nombre;
}

void Persona::mostrarDatos() {
    cout << "\nID: " << id;
    cout << "\nNombre: " << nombre << endl;
}

int Persona::getId() {
    return id;
}

string Persona::getNombre() {
    return nombre;
}

void Persona::setNombre(string nombre) {
    this->nombre = nombre;
}

Persona::~Persona() {
}