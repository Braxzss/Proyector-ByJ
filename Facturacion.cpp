#include "Facturacion.h"

Facturacion::Facturacion(PGconn* conexion) {
    conn = conexion;
}

void Facturacion::generarComprobante() {

    int idVenta;

    cout << "\nIngrese ID de venta: ";
    cin >> idVenta;

    string consultaVenta =
        "SELECT id_venta, fecha, total "
        "FROM ventas "
        "WHERE id_venta = " +
        to_string(idVenta) + ";";

    PGresult* ventaRes =
        PQexec(conn, consultaVenta.c_str());

    if (PQresultStatus(ventaRes) != PGRES_TUPLES_OK ||
        PQntuples(ventaRes) == 0) {

        cout << "\nVenta no encontrada.\n";
        PQclear(ventaRes);
        return;
    }

    cout << "\n====================================";
    cout << "\n        AUTOPARTES GTR";
    cout << "\n====================================";

    cout << "\nVenta No: "
        << PQgetvalue(ventaRes, 0, 0);

    cout << "\nFecha: "
        << PQgetvalue(ventaRes, 0, 1);

    cout << "\n------------------------------------";

    string consultaDetalle =
        "SELECT p.nombre, d.cantidad, d.subtotal "
        "FROM detalle_venta d "
        "INNER JOIN productos p "
        "ON d.id_producto = p.id_producto "
        "WHERE d.id_venta = " +
        to_string(idVenta) + ";";

    PGresult* detalleRes =
        PQexec(conn, consultaDetalle.c_str());

    if (PQresultStatus(detalleRes) == PGRES_TUPLES_OK) {

        int filas = PQntuples(detalleRes);

        for (int i = 0; i < filas; i++) {

            cout << "\nProducto: "
                << PQgetvalue(detalleRes, i, 0);

            cout << "\nCantidad: "
                << PQgetvalue(detalleRes, i, 1);

            cout << "\nSubtotal: Q"
                << PQgetvalue(detalleRes, i, 2);

            cout << "\n------------------------";
        }
    }

    cout << "\nTOTAL: Q"
        << PQgetvalue(ventaRes, 0, 2);

    cout << "\n====================================\n";

    PQclear(detalleRes);
    PQclear(ventaRes);
}

void Facturacion::mostrar() {
    generarComprobante();
}