CREATE DATABASE SenadoVirtual;
USE SenadoVirtual;

CREATE TABLE Usuarios (
    id_usuario INT PRIMARY KEY,
    nombre VARCHAR(20) NOT NULL,
    ap1 VARCHAR(40) NOT NULL,
    ap2 VARCHAR(40),
    tipo ENUM('Ciudadano', 'Senador') NOT NULL,
    mail VARCHAR(256) UNIQUE,
    municipio VARCHAR(50)
);

CREATE TABLE Leyes (
    id_ley VARCHAR(10) PRIMARY KEY,
    titulo VARCHAR(255) NOT NULL,
    preambulo TEXT,
    cuerpo TEXT,
    estado ENUM('Borrador', 'En votacion', 'Votada') NOT NULL
);

CREATE TABLE Votos (
    id_voto INT PRIMARY KEY,
    valor ENUM('Si', 'No', 'Abstención') NOT NULL,
    fk_usuario INT,
    fk_ley VARCHAR(10),
    FOREIGN KEY (fk_usuario) REFERENCES Usuarios(id_usuario),
    FOREIGN KEY (fk_ley) REFERENCES Leyes(id_ley)
);


CREATE TABLE Posts (
    id_post INT PRIMARY KEY,
    cuerpo TEXT NOT NULL,
    fk_usuario INT,
    fk_hilo INT,
    FOREIGN KEY (fk_usuario) REFERENCES Usuarios(id_usuario),
    FOREIGN KEY (fk_hilo) REFERENCES Hilos(id_hilo)
);

CREATE TABLE Artículos (
    id_articulo INT PRIMARY KEY,
    n_articulo VARCHAR(10) NOT NULL,
    cuerpo TEXT,
    fk_ley VARCHAR(10),
    FOREIGN KEY (fk_ley) REFERENCES Leyes(id_ley)
);

CREATE TABLE Hilos (
    id_hilo INT PRIMARY KEY,
    titulo VARCHAR(128) NOT NULL,
    cuerpo TEXT,
    fk_usuario INT,
    FOREIGN KEY (fk_usuario) REFERENCES Usuarios(id_usuario)
);