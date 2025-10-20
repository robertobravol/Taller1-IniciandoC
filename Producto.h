#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <stdint.h>

#define PRODUCTO_NOMBRE_MAX 128

// Estructura para producto
typedef struct Producto {
	char nombre[PRODUCTO_NOMBRE_MAX]; // Nombre del producto
	int codigo;                       // Código identificador del producto
	float precio;                     // Precio unitario
	int stock;                        // Cantidad disponible en inventario
} Producto;

void agregarProducto(struct Producto producto); // Agrega un producto al inventario
void verificarProducto(struct Producto producto); // Verifica la existencia de un producto
void ingresarProducto(); // Permite ingresar un nuevo producto
void mostrarProducto(struct Producto producto); // Muestra la información de un producto
int incrementarStock(int codigo, int cantidad); // Incrementa el stock de un producto
int venderProducto(int codigo, int cantidad); // Vende una cantidad de un producto

#endif

