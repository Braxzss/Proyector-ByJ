#ifndef VENTA_H
#define VENTA_H

#include <string>
using namespace std;

class Venta {
private:
	int idVenta;
	string fecha;
	double total;
	int idUsuario;

public:
	Venta();
	Venta(int id, string fec, double tot, int user);

	int getIdVenta();
	string getFecha();
	double getTotal();
	int getIdUsuario();

	void mostrarVenta();
};

#endif
#pragma once
