#include "Sistema.h"
#include "HistorialVentas.h"
#include "Facturacion.h"
#include "GestionVentas.h"
#include <iostream>

using namespace std;

void Sistema::iniciar() {

    if (!db.conectar()) {
        cout << "No se pudo conectar a la base de datos." << endl;
        return;
    }

    string usuario;
    string contrasena;

    cout << "\n===== LOGIN AUTOPARTES GTR =====" << endl;

    cout << "Usuario: ";
    cin >> usuario;

    cout << "Contrasena: ";
    cin >> contrasena;

    if (!db.validarLogin(usuario, contrasena)) {
        cout << "\nUsuario o contrasena incorrectos." << endl;
        return;
    }

    int opcion;

    do {

        cout << "\n======================================" << endl;
        cout << "       SISTEMA AUTOPARTES GTR" << endl;
        cout << "======================================" << endl;
        cout << "1. Inventario" << endl;
        cout << "2. Ventas" << endl;
        cout << "3. Historial de ventas" << endl;
        cout << "4. Facturacion / Comprobante" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";

        cin >> opcion;

        switch (opcion) {

        case 1:
        {
            Inventario inventario(db.getConexion());
            inventario.menuInventario();
            break;
        }

        case 2:
        {
            GestionVentas ventas(
                db.getConexion());

            ventas.registrarVenta();
            break;
        }

        case 3:
        {
            HistorialVentas historial(
                db.getConexion());

            historial.mostrarHistorial();
            break;
        }

        case 4:
        {
            Facturacion factura(
                db.getConexion());

            factura.generarComprobante();
            break;
        }

        case 0:
            cout << "\nGracias por utilizar AutoPartes GTR." << endl;
            break;

        default:
            cout << "\nOpcion invalida." << endl;
        }

    } while (opcion != 0);
}