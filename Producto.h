#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
using namespace std;

class Producto {
private:
	int idProducto;
	string codigo;
	string nombre;
	string categoria;
	double precio;
	int stock;

public:
	Producto();
	Producto(int id, string cod, string nom, string cat, double pre, int st);

	void mostrarProducto();

	int getIdProducto();
	string getCodigo();
	string getNombre();
	string getCategoria();
	double getPrecio();
	int getStock();

	void setCodigo(string cod);
	void setNombre(string nom);
	void setCategoria(string cat);
	void setPrecio(double pre);
	void setStock(int st);
};

#endif
#pragma once
