#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

struct Producto {
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
};

struct Cliente {
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    struct Producto *Productos;
};

int main() {
    int cantidadClientes;

    printf("Ingrese la cantidad de clientes a cargar: ");
    scanf("%d", &cantidadClientes);

    struct Cliente *clientes = (struct Cliente *) malloc(sizeof(struct Cliente) * cantidadClientes);

    for (int i = 0; i < cantidadClientes; i++) {
        printf("\nCarga de datos del cliente %d\n", i + 1);

        clientes[i].ClienteID = i + 1;

        // Reservamos memoria para el nombre del cliente
        char nombreCliente[100];
        printf("Ingrese el nombre del cliente: ");
        scanf("%s", nombreCliente);
        clientes[i].NombreCliente = (char *) malloc(strlen(nombreCliente) + 1);
        strcpy(clientes[i].NombreCliente, nombreCliente);

        clientes[i].CantidadProductosAPedir = rand() % 5 + 1;

        clientes[i].Productos = (struct Producto *) malloc(sizeof(struct Producto) * clientes[i].CantidadProductosAPedir);

        printf("Carga de %d productos\n", clientes[i].CantidadProductosAPedir);
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = rand() % 10 + 1;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
            clientes[i].Productos[j].PrecioUnitario = (rand() % 91 + 10) / 10.0;

            printf("Producto %d: %d unidades de %s a $%.2f cada uno\n", clientes[i].Productos[j].ProductoID,
                clientes[i].Productos[j].Cantidad, clientes[i].Productos[j].TipoProducto,
                clientes[i].Productos[j].PrecioUnitario);
        }
    }

    // Mostramos los clientes cargados
    printf("\nClientes cargados:\n");
    for (int i = 0; i < cantidadClientes; i++) {
        printf("Cliente %d: %s - %d productos\n", clientes[i].ClienteID, clientes[i].NombreCliente,
            clientes[i].CantidadProductosAPedir);
    }

    // Liberamos la memoria reservada
    for (int i = 0; i < cantidadClientes; i++) {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
    free(clientes);

    return 0;
}
