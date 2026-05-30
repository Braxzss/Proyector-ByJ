#include "Sistema.h"
#include "Usuario.h"
#include "Utilidades.h"
#include <iostream>

using namespace std;

int main() {

    Usuario usuario(
        1,
        "Administrador",
        "admin",
        "1234"
    );

    usuario.mostrarDatos();

    cout << "\nFactorial de 5: "
         << Utilidades::factorial(5)
         << endl;

    Sistema sistema;
    sistema.iniciar();

    return 0;
}