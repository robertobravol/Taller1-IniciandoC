#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Producto.h"

int main(void) {
    int opcion;

    do {
        printf("\n===== SISTEMA DE INVENTARIO =====\n");
        printf("1 Agregar producto\n");
        printf("2 Mostrar productos\n");
        printf("\t a) Incrementar stock\n");
        printf("\t b) Vender producto\n");
        printf("\t c) Regresar\n");
        printf("0 Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                ingresarProducto();
                break;
            case 2: {
                char sub;
                do {
                    mostrarTodosProductos();
                    printf("\nSubmenu (a/b/c): ");
                    if (scanf(" %c", &sub) != 1) break;

                    if (sub == 'a') {
                        int codigo, cantidad;
                        printf("Codigo del producto a incrementar: ");  //aca valida el codigo para encontrar el producto
                        scanf(" %d", &codigo);
                        printf("Cantidad a aumentar: ");
                        scanf(" %d", &cantidad);
                        if (incrementarStock(codigo, cantidad))
                            printf("Stock actualizado.\n");
                        else
                            printf("Producto no encontrado.\n"); //caso que no lo encuentre 
                    } else if (sub == 'b') {
                        int codigo, cantidad;
                        printf("Codigo del producto a vender: ");
                        scanf(" %d", &codigo);
                        printf("Cantidad a vender: ");
                        scanf(" %d", &cantidad);
                        int res = venderProducto(codigo, cantidad);
                        if (res == 1)
                            printf("Venta realizada.\n");  // la confirmacion de la vent 
                        else if (res == -1)
                            printf("Stock insuficiente.\n");   // caso de stock insuficiente
                        else
                            printf("Producto no encontrado.\n");
                    }
                } while (sub != 'c');
                break;
            }
            case 0:   // Aca agregamos un case para definir la salida del programa 
                printf("Saliendo del programa.\n"); 
                break;
            default:  //Aca valida que el usuario solo ingrese opciones validas y no caracteres no permitidos 
                printf("Opcion invalida, intente de nuevo.\n");
        }

    } while (opcion != 0);

    return 0;
}