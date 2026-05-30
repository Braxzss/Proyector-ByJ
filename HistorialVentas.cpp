#include "HistorialVentas.h"

HistorialVentas::HistorialVentas(PGconn* conexion) {
    conn = conexion;
}

void HistorialVentas::mostrarHistorial() {

    string consulta =
        "SELECT id_venta, fecha, total, id_usuario "
        "FROM ventas "
        "ORDER BY id_venta;";

    PGresult* res = PQexec(conn, consulta.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        cout << "\nError al consultar historial.\n";
        PQclear(res);
        return;
    }

    int filas = PQntuples(res);

    cout << "\n===== HISTORIAL DE VENTAS =====\n";

    if (filas == 0) {
        cout << "\nNo existen ventas registradas.\n";
    }

    for (int i = 0; i < filas; i++) {

        cout << "\nVenta No.: "
            << PQgetvalue(res, i, 0);

        cout << "\nFecha: "
            << PQgetvalue(res, i, 1);

        cout << "\nTotal: Q"
            << PQgetvalue(res, i, 2);

        cout << "\nUsuario ID: "
            << PQgetvalue(res, i, 3);

        cout << "\n-----------------------------\n";
    }

    PQclear(res);
}