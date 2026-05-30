#ifndef USUARIO_H
#define USUARIO_H

#include "Persona.h"

class Usuario : public Persona {
private:
    string usuario;
    string contrasena;

public:
    Usuario();

    Usuario(
        int id,
        string nombre,
        string usuario,
        string contrasena
    );

    string getUsuario();
    string getContrasena();

    void setUsuario(string usuario);
    void setContrasena(string contrasena);

    void mostrarDatos() override;
};

#endif
