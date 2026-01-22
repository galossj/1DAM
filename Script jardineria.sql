CREATE DATABASE IF NOT EXISTS jardineria;
USE jardineria;

drop table if exists pago;
drop table if exists detalle_pedido;
drop table if exists producto;
drop table if exists pedido;
drop table if exists cliente;
drop table if exists empleado;
drop table if exists oficina;
drop table if exists gama_producto;

CREATE TABLE gama_producto (
    gama VARCHAR(50) NOT NULL,
    descripcion_texto TEXT,
    descripcion_html TEXT,
    imagen VARCHAR(256),
    PRIMARY KEY (gama)
);


CREATE TABLE oficina (
    codigo_oficina VARCHAR(10) NOT NULL,
    ciudad VARCHAR(30) NOT NULL,
    pais VARCHAR(50) NOT NULL,
    region VARCHAR(50),
    codigo_postal VARCHAR(10) NOT NULL,
    telefono VARCHAR(20) NOT NULL,
    linea_direccion1 VARCHAR(50) NOT NULL,
    linea_direccion2 VARCHAR(50),
    PRIMARY KEY (codigo_oficina)
);


CREATE TABLE empleado (
    codigo_empleado INT(11) NOT NULL,
    nombre VARCHAR(50) NOT NULL,
    apellido1 VARCHAR(50) NOT NULL,
    apellido2 VARCHAR(50),
    extension VARCHAR(10) NOT NULL,
    email VARCHAR(100) NOT NULL,
    codigo_oficina VARCHAR(10) NOT NULL,
    codigo_jefe INT(11),
    puesto VARCHAR(50),
    PRIMARY KEY (codigo_empleado),
    FOREIGN KEY (codigo_oficina) REFERENCES oficina(codigo_oficina),
    FOREIGN KEY (codigo_jefe) REFERENCES empleado(codigo_empleado)
);


CREATE TABLE cliente (
    codigo_cliente INT(11) NOT NULL,
    nombre_cliente VARCHAR(50) NOT NULL,
    nombre_contacto VARCHAR(30),
    apellido_contacto VARCHAR(30),
    telefono VARCHAR(15) NOT NULL,
    fax VARCHAR(15) NOT NULL,
    linea_direccion1 VARCHAR(50) NOT NULL,
    linea_direccion2 VARCHAR(50),
    ciudad VARCHAR(50) NOT NULL,
    region VARCHAR(50),
    pais VARCHAR(50),
    codigo_postal VARCHAR(10),
    codigo_empleado_rep_ventas INT(11),
    limite_credito DECIMAL(15,2),
    PRIMARY KEY (codigo_cliente),
    FOREIGN KEY (codigo_empleado_rep_ventas) REFERENCES empleado(codigo_empleado)
);


CREATE TABLE pedido (
    codigo_pedido INT(11) NOT NULL,
    fecha_pedido DATE NOT NULL,
    fecha_esperada DATE NOT NULL,
    fecha_entrega DATE,
    estado VARCHAR(15) NOT NULL,
    comentarios TEXT,
    codigo_cliente INT(11) NOT NULL,
    PRIMARY KEY (codigo_pedido),
    FOREIGN KEY (codigo_cliente) REFERENCES cliente(codigo_cliente)
);


CREATE TABLE producto (
    codigo_producto VARCHAR(15) NOT NULL,
    nombre VARCHAR(70) NOT NULL,
    gama VARCHAR(50) NOT NULL,
    dimensiones VARCHAR(25),
    proveedor VARCHAR(50),
    descripcion TEXT,
    cantidad_en_stock SMALLINT(6) NOT NULL,
    precio_venta DECIMAL(15,2) NOT NULL,
    precio_proveedor DECIMAL(15,2),
    PRIMARY KEY (codigo_producto),
    FOREIGN KEY (gama) REFERENCES gama_producto(gama)
);


CREATE TABLE detalle_pedido (
    codigo_pedido INT(11) NOT NULL,
    codigo_producto VARCHAR(15) NOT NULL,
    cantidad INT(11) NOT NULL,
    precio_unidad DECIMAL(15,2) NOT NULL,
    numero_linea SMALLINT(6) NOT NULL,
    PRIMARY KEY (codigo_pedido, codigo_producto),
    FOREIGN KEY (codigo_pedido) REFERENCES pedido(codigo_pedido),
    FOREIGN KEY (codigo_producto) REFERENCES producto(codigo_producto)
);


CREATE TABLE pago (
    codigo_cliente INT(11) NOT NULL,
    forma_pago VARCHAR(40) NOT NULL,
    id_transaccion VARCHAR(50) NOT NULL,
    fecha_pago DATE NOT NULL,
    total DECIMAL(15,2) NOT NULL,
    PRIMARY KEY (codigo_cliente, id_transaccion),
    FOREIGN KEY (codigo_cliente) REFERENCES cliente(codigo_cliente)
);