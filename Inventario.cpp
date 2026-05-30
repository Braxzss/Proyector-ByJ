#include "Inventario.h"

Inventario::Inventario(PGconn* conexion) {
    conn = conexion;
}

void Inventario::agregarProducto() {
    string codigo, nombre, categoria;
    double precio;
    int stock;

    cout << "\n--- AGREGAR PRODUCTO ---\n";
    cout << "Codigo: ";
    cin >> codigo;
    cin.ignore();

    cout << "Nombre: ";
    getline(cin, nombre);

    cout << "Categoria: ";
    getline(cin, categoria);

    cout << "Precio: ";
    cin >> precio;

    cout << "Stock: ";
    cin >> stock;

    string consulta =
        "INSERT INTO productos(codigo, nombre, categoria, precio, stock) VALUES('" +
        codigo + "', '" + nombre + "', '" + categoria + "', " +
        to_string(precio) + ", " + to_string(stock) + ");";

    PGresult* res = PQexec(conn, consulta.c_str());

    if (PQresultStatus(res) == PGRES_COMMAND_OK) {
        cout << "\nProducto agregado correctamente.\n";
    }
    else {
        cout << "\nError al agregar producto: " << PQerrorMessage(conn) << endl;
    }

    PQclear(res);
}

void Inventario::mostrarProductos() {
    string consulta = "SELECT id_producto, codigo, nombre, categoria, precio, stock FROM productos ORDER BY id_producto;";
    PGresult* res = PQexec(conn, consulta.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        cout << "Error al mostrar productos.\n";
        PQclear(res);
        return;
    }

    int filas = PQntuples(res);

    cout << "\n--- LISTA DE PRODUCTOS ---\n";

    for (int i = 0; i < filas; i++) {
        cout << "\nID: " << PQgetvalue(res, i, 0);
        cout << "\nCodigo: " << PQgetvalue(res, i, 1);
        cout << "\nNombre: " << PQgetvalue(res, i, 2);
        cout << "\nCategoria: " << PQgetvalue(res, i, 3);
        cout << "\nPrecio: Q" << PQgetvalue(res, i, 4);
        cout << "\nStock: " << PQgetvalue(res, i, 5);
        cout << "\n--------------------------\n";
    }

    PQclear(res);
}

void Inventario::buscarProducto() {
    string codigo;

    cout << "\n--- BUSCAR PRODUCTO ---\n";
    cout << "Ingrese codigo del producto: ";
    cin >> codigo;

    string consulta =
        "SELECT id_producto, codigo, nombre, categoria, precio, stock FROM productos WHERE codigo = '" +
        codigo + "';";

    PGresult* res = PQexec(conn, consulta.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        cout << "Error al buscar producto.\n";
        PQclear(res);
        return;
    }

    if (PQntuples(res) == 0) {
        cout << "\nProducto no encontrado.\n";
    }
    else {
        cout << "\nProducto encontrado:\n";
        cout << "ID: " << PQgetvalue(res, 0, 0) << endl;
        cout << "Codigo: " << PQgetvalue(res, 0, 1) << endl;
        cout << "Nombre: " << PQgetvalue(res, 0, 2) << endl;
        cout << "Categoria: " << PQgetvalue(res, 0, 3) << endl;
        cout << "Precio: Q" << PQgetvalue(res, 0, 4) << endl;
        cout << "Stock: " << PQgetvalue(res, 0, 5) << endl;
    }

    PQclear(res);
}

void Inventario::actualizarProducto() {
    int id;
    string nombre, categoria;
    double precio;
    int stock;

    cout << "\n--- ACTUALIZAR PRODUCTO ---\n";
    cout << "Ingrese ID del producto: ";
    cin >> id;
    cin.ignore();

    cout << "Nuevo nombre: ";
    getline(cin, nombre);

    cout << "Nueva categoria: ";
    getline(cin, categoria);

    cout << "Nuevo precio: ";
    cin >> precio;

    cout << "Nuevo stock: ";
    cin >> stock;

    string consulta =
        "UPDATE productos SET nombre = '" + nombre +
        "', categoria = '" + categoria +
        "', precio = " + to_string(precio) +
        ", stock = " + to_string(stock) +
        " WHERE id_producto = " + to_string(id) + ";";

    PGresult* res = PQexec(conn, consulta.c_str());

    if (PQresultStatus(res) == PGRES_COMMAND_OK) {
        cout << "\nProducto actualizado correctamente.\n";
    }
    else {
        cout << "\nError al actualizar producto: " << PQerrorMessage(conn) << endl;
    }

    PQclear(res);
}

void Inventario::eliminarProducto() {
    int id;

    cout << "\n--- ELIMINAR PRODUCTO ---\n";
    cout << "Ingrese ID del producto: ";
    cin >> id;

    string consulta =
        "DELETE FROM productos WHERE id_producto = " + to_string(id) + ";";

    PGresult* res = PQexec(conn, consulta.c_str());

    if (PQresultStatus(res) == PGRES_COMMAND_OK) {
        cout << "\nProducto eliminado correctamente.\n";
    }
    else {
        cout << "\nError al eliminar producto: " << PQerrorMessage(conn) << endl;
    }

    PQclear(res);
}

void Inventario::menuInventario() {
    int opcion;

    do {
        cout << "\n===== MENU INVENTARIO =====\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Buscar producto\n";
        cout << "4. Actualizar producto\n";
        cout << "5. Eliminar producto\n";
        cout << "0. Salir del inventario\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            agregarProducto();
            break;
        case 2:
            mostrarProductos();
            break;
        case 3:
            buscarProducto();
            break;
        case 4:
            actualizarProducto();
            break;
        case 5:
            eliminarProducto();
            break;
        case 0:
            cout << "Saliendo del inventario...\n";
            break;
        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 0);
}
