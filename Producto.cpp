#include "Producto.h"

Producto::Producto() {
	idProducto = 0;
	codigo = "";
	nombre = "";
	categoria = "";
	precio = 0.0;
	stock = 0;
}

Producto::Producto(int id, string cod, string nom, string cat, double pre, int st) {
	idProducto = id;
	codigo = cod;
	nombre = nom;
	categoria = cat;
	precio = pre;
	stock = st;
}

void Producto::mostrarProducto() {
	cout << "\nID: " << idProducto;
	cout << "\nCodigo: " << codigo;
	cout << "\nNombre: " << nombre;
	cout << "\nCategoria: " << categoria;
	cout << "\nPrecio: Q" << precio;
	cout << "\nStock: " << stock << endl;
}

int Producto::getIdProducto() { return idProducto; }
string Producto::getCodigo() { return codigo; }
string Producto::getNombre() { return nombre; }
string Producto::getCategoria() { return categoria; }
double Producto::getPrecio() { return precio; }
int Producto::getStock() { return stock; }

void Producto::setCodigo(string cod) { codigo = cod; }
void Producto::setNombre(string nom) { nombre = nom; }
void Producto::setCategoria(string cat) { categoria = cat; }
void Producto::setPrecio(double pre) { precio = pre; }
void Producto::setStock(int st) { stock = st; }
