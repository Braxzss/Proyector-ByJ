#include "GestionVentas.h"

GestionVentas::GestionVentas(PGconn* conexion) {
    conn = conexion;
}

void GestionVentas::mostrarProductosDisponibles() {

    string consulta =
        "SELECT id_producto, codigo, nombre, precio, stock "
        "FROM productos "
        "ORDER BY id_producto;";

    PGresult* res =
        PQexec(conn, consulta.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {

        cout << "\nError al consultar productos.\n";
        PQclear(res);
        return;
    }

    cout << "\n===== PRODUCTOS DISPONIBLES =====\n";

    int filas = PQntuples(res);

    for (int i = 0; i < filas; i++) {

        cout << "\nID: "
            << PQgetvalue(res, i, 0);

        cout << "\nCodigo: "
            << PQgetvalue(res, i, 1);

        cout << "\nNombre: "
            << PQgetvalue(res, i, 2);

        cout << "\nPrecio: Q"
            << PQgetvalue(res, i, 3);

        cout << "\nStock: "
            << PQgetvalue(res, i, 4);

        cout << "\n-------------------------\n";
    }

    PQclear(res);
}

void GestionVentas::registrarVenta() {

    int idProducto;
    int cantidad;

    mostrarProductosDisponibles();

    cout << "\nID del producto: ";
    cin >> idProducto;

    cout << "Cantidad: ";
    cin >> cantidad;

    string consultaProducto =
        "SELECT precio, stock "
        "FROM productos "
        "WHERE id_producto = " +
        to_string(idProducto) + ";";

    PGresult* productoRes =
        PQexec(conn, consultaProducto.c_str());

    if (PQresultStatus(productoRes) != PGRES_TUPLES_OK ||
        PQntuples(productoRes) == 0) {

        cout << "\nProducto no encontrado.\n";

        PQclear(productoRes);
        return;
    }

    double precio =
        atof(PQgetvalue(productoRes, 0, 0));

    int stock =
        atoi(PQgetvalue(productoRes, 0, 1));

    if (cantidad > stock) {

        cout << "\nStock insuficiente.\n";

        PQclear(productoRes);
        return;
    }

    double subtotal = precio * cantidad;

    string insertarVenta =
        "INSERT INTO ventas(total, id_usuario) "
        "VALUES(" +
        to_string(subtotal) +
        ", 1) RETURNING id_venta;";

    PGresult* ventaRes =
        PQexec(conn, insertarVenta.c_str());

    if (PQresultStatus(ventaRes) != PGRES_TUPLES_OK) {

        cout << "\nError al registrar venta.\n";

        PQclear(productoRes);
        PQclear(ventaRes);
        return;
    }

    int idVenta =
        atoi(PQgetvalue(ventaRes, 0, 0));

    string insertarDetalle =
        "INSERT INTO detalle_venta("
        "id_venta, "
        "id_producto, "
        "cantidad, "
        "subtotal) VALUES(" +
        to_string(idVenta) + ", " +
        to_string(idProducto) + ", " +
        to_string(cantidad) + ", " +
        to_string(subtotal) + ");";

    PGresult* detalleRes =
        PQexec(conn, insertarDetalle.c_str());

    string actualizarStock =
        "UPDATE productos "
        "SET stock = stock - " +
        to_string(cantidad) +
        " WHERE id_producto = " +
        to_string(idProducto) + ";";

    PGresult* stockRes =
        PQexec(conn, actualizarStock.c_str());

    if (PQresultStatus(detalleRes) ==
        PGRES_COMMAND_OK &&
        PQresultStatus(stockRes) ==
        PGRES_COMMAND_OK) {

        cout << "\nVenta registrada correctamente.\n";
        cout << "ID Venta: "
            << idVenta << endl;

        cout << "Total: Q"
            << subtotal << endl;
    }
    else {

        cout << "\nError al completar venta.\n";
    }

    PQclear(productoRes);
    PQclear(ventaRes);
    PQclear(detalleRes);
    PQclear(stockRes);
}