#include "Venta.h"
#include <iostream>
using namespace std;

Venta::Venta() {
	idVenta = 0;
	fecha = "";
	total = 0.0;
	idUsuario = 0;
}

Venta::Venta(int id, string fec, double tot, int user) {
	idVenta = id;
	fecha = fec;
	total = tot;
	idUsuario = user;
}

int Venta::getIdVenta() { return idVenta; }
string Venta::getFecha() { return fecha; }
double Venta::getTotal() { return total; }
int Venta::getIdUsuario() { return idUsuario; }

void Venta::mostrarVenta() {
	cout << "\nID Venta: " << idVenta;
	cout << "\nFecha: " << fecha;
	cout << "\nTotal: Q" << total;
	cout << "\nUsuario ID: " << idUsuario << endl;
}
