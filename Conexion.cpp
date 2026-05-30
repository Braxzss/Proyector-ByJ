#include "Conexion.h"

Conexion::Conexion() {
    conn = nullptr;
}

Conexion::~Conexion() {
    cerrarConexion();
}

bool Conexion::conectar() {
    conn = PQconnectdb(
        "host=localhost "
        "port=5432 "
        "dbname=autopartes_gtr "
        "user=postgres "
        "password=277353"
    );

    if (PQstatus(conn) != CONNECTION_OK) {
        cout << "Error al conectar con PostgreSQL: " << PQerrorMessage(conn) << endl;
        return false;
    }

    cout << "Conexion exitosa a PostgreSQL." << endl;
    return true;
}

void Conexion::cerrarConexion() {
    if (conn != nullptr) {
        PQfinish(conn);
        conn = nullptr;
    }
}

PGconn* Conexion::getConexion() {
    return conn;
}

bool Conexion::validarLogin(string usuario, string contrasena) {
    string consulta =
        "SELECT id_usuario FROM usuarios WHERE usuario = '" +
        usuario + "' AND contrasena = '" + contrasena + "';";

    PGresult* resultado = PQexec(conn, consulta.c_str());

    if (PQresultStatus(resultado) != PGRES_TUPLES_OK) {
        cout << "Error en consulta de login." << endl;
        PQclear(resultado);
        return false;
    }

    int filas = PQntuples(resultado);
    PQclear(resultado);

    return filas > 0;
}
