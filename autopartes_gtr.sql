CREATE DATABASE autopartes_gtr;

CREATE TABLE usuarios (
   id_usuario SERIAL PRIMARY KEY,
   usuario VARCHAR(50) UNIQUE NOT NULL,
   contrasena VARCHAR(100) NOT NULL
);

CREATE TABLE productos (
   id_producto SERIAL PRIMARY KEY,
   codigo VARCHAR(20) UNIQUE NOT NULL,
   nombre VARCHAR(100) NOT NULL,
   categoria VARCHAR(50) NOT NULL,
   precio DECIMAL(10,2) NOT NULL,
   stock INT NOT NULL
);

CREATE TABLE ventas (
   id_venta SERIAL PRIMARY KEY,
   fecha TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
   total DECIMAL(10,2) NOT NULL,
   id_usuario INT NOT NULL,
   FOREIGN KEY (id_usuario) REFERENCES usuarios(id_usuario)
);

CREATE TABLE detalle_venta (
   id_detalle SERIAL PRIMARY KEY,
   id_venta INT NOT NULL,
   id_producto INT NOT NULL,
   cantidad INT NOT NULL,
   subtotal DECIMAL(10,2) NOT NULL,
   FOREIGN KEY (id_venta) REFERENCES ventas(id_venta),
   FOREIGN KEY (id_producto) REFERENCES productos(id_producto)
);

INSERT INTO usuarios(usuario, contrasena)
VALUES
('admin', '1234'),
('brayan', '2025');

INSERT INTO productos(codigo, nombre, categoria, precio, stock)
VALUES
('A001', 'Aceite 20W50', 'Lubricantes', 230.00, 20),
('A002', 'Aceite 10W30', 'Lubricantes', 240.00, 15),
('A003', 'Aceite 15W40', 'Lubricantes', 250.00, 18),
('F001', 'Filtro de aceite Toyota', 'Filtros', 45.00, 30),
('F002', 'Filtro de aire Mitsubishi', 'Filtros', 85.00, 12),
('B001', 'Bateria LTH', 'Baterias', 850.00, 10),
('P001', 'Pastillas de freno', 'Frenos', 320.00, 12),
('R001', 'Radiador Mitsubishi', 'Sistema de enfriamiento', 950.00, 5);
