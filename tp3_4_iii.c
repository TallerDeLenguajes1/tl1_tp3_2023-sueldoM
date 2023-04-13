#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int generarAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

float generarPrecioAleatorio(float min, float max) {
    float scale = rand() / (float) RAND_MAX;
    return min + scale * (max - min); // escalamos el valor al rango deseado
}

struct Cliente cargarCliente(int id) {
    struct Cliente cliente;
    cliente.ClienteID = id;

    printf("\nIngrese el nombre del cliente %d: ", id);
    char nombre[50];
    scanf("%s", nombre);
    cliente.NombreCliente = strdup(nombre); // duplicamos el string con strdup para no tener problemas con la memoria

    cliente.CantidadProductosAPedir = generarAleatorio(1, 5);
    cliente.Productos = (struct Producto*) malloc(cliente.CantidadProductosAPedir * sizeof(struct Producto));

    printf("Productos del cliente %d:\n", id);
    for (int i = 0; i < cliente.CantidadProductosAPedir; i++) {
        struct Producto producto;
        producto.ProductoID = i + 1;
        producto.Cantidad = generarAleatorio(1, 10);
        producto.TipoProducto = TiposProductos[generarAleatorio(0, 4)];
        producto.PrecioUnitario = generarPrecioAleatorio(10.0, 100.0);
        cliente.Productos[i] = producto;

        printf("Producto %d:\n", producto.ProductoID);
        printf("Cantidad: %d\n", producto.Cantidad);
        printf("Tipo: %s\n", producto.TipoProducto);
        printf("Precio unitario: %.2f\n", producto.PrecioUnitario);
    }

    return cliente;
}

int main() {
    srand(time(NULL));

    int cantidadClientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadClientes);

    struct Cliente *clientes = (struct Cliente*) malloc(cantidadClientes * sizeof(struct Cliente));

    for (int i = 0; i < cantidadClientes; i++) {
        struct Cliente cliente = cargarCliente(i + 1);
        clientes[i] = cliente;
    }

    return 0;
}
