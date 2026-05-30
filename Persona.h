#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

using namespace std;

class Persona {
protected:
    int id;
    string nombre;

public:
    Persona();
    Persona(int id, string nombre);

    virtual void mostrarDatos();

    int getId();
    string getNombre();

    void setNombre(string nombre);

    virtual ~Persona();
};

#endif