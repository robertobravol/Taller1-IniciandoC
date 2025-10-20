#include <stdio.h>
#include <string.h>
#include "Producto.h"
 
#define MAX_PRODUCTOS 30

Producto inventario[MAX_PRODUCTOS];
int totalProductos = 0;

void agregarProducto(Producto producto) { //Funcion agregar producto, agrega maximo hasta el limite del inventario
    if (totalProductos < MAX_PRODUCTOS) {
        inventario[totalProductos++] = producto;
        printf("Producto agregado: %s\n", producto.nombre);
    } else {
        printf("Inventario lleno, no se puede agregar más productos.\n");
    }
}

void mostrarProducto(Producto producto) {   //Muestra de manera ordenada los productos 
    printf("---------------------------\n");
    printf("Nombre: %s\n", producto.nombre);
    printf("Código: %d\n", producto.codigo);
    printf("Precio: %.2f\n", producto.precio);
    printf("Stock: %d\n", producto.stock);
}

void ingresarProducto(void) {  //Funcion para ingresar un nuevo producto
    Producto nuevoProducto;
    printf("Ingrese el nombre del producto: ");
    getchar();
    size_t ln = strlen(nuevoProducto.nombre);
    if (ln > 0 && nuevoProducto.nombre[ln-1] == '\n') nuevoProducto.nombre[ln-1] = '\0';

    printf("Ingrese el código del producto: ");
    if (scanf(" %d", &nuevoProducto.codigo) != 1) { printf("Código inválido.\n"); return; }
    printf("Ingrese el precio del producto: ");
    if (scanf(" %f", &nuevoProducto.precio) != 1) { printf("Precio inválido.\n"); return; }
    printf("Ingrese el stock del producto: ");
    if (scanf(" %d", &nuevoProducto.stock) != 1) { printf("Stock inválido.\n"); return; }

    agregarProducto(nuevoProducto);
}

void mostrarTodosProductos(void) { //Muestra todos los productos en el inventario
    if (totalProductos == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }
    printf("\nLista de productos (%d):\n", totalProductos);
    for (int i = 0; i < totalProductos; i++) {
        mostrarProducto(inventario[i]);
    }
}

int incrementarStock(int codigo, int cantidad) { //Incrementa el stock de un producto
    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].codigo == codigo) {
            inventario[i].stock += cantidad;
            return 1;
        }
    }
    return 0;
}

int venderProducto(int codigo, int cantidad) { //Vende una cantidad de un producto
    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].codigo == codigo) {
            if (inventario[i].stock < cantidad) return -1; 
            inventario[i].stock -= cantidad;
            return 1; 
        }
    }
    return 0;
}