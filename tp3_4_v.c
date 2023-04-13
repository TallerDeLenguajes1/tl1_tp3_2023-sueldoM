#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

float costoTotal(struct Producto p){
    return p.Cantidad * p.PrecioUnitario;
}

void cargarDatosCliente(struct Cliente *c) {
    int cantidadProductos = rand() % 5 + 1;
    c->CantidadProductosAPedir = cantidadProductos;
    c->Productos = (struct Producto*)malloc(sizeof(struct Producto) * cantidadProductos);

    for(int i = 0; i < cantidadProductos; i++) {
        struct Producto p;
        p.ProductoID = i + 1;
        p.Cantidad = rand() % 10 + 1;
        p.TipoProducto = TiposProductos[rand() % 5];
        p.PrecioUnitario = (rand() % 91 + 10) / 10.0f;
        c->Productos[i] = p;
    }
}

void mostrarCliente(struct Cliente c){
    printf("Cliente %d: %s\n", c.ClienteID, c.NombreCliente);
    float totalAPagar = 0;
    for(int i = 0; i < c.CantidadProductosAPedir; i++){
        struct Producto p = c.Productos[i];
        float costo = costoTotal(p);
        totalAPagar += costo;
        printf("\tProducto %d: %s - Cantidad: %d - Precio Unitario: $%.2f - Costo: $%.2f\n",
            p.ProductoID, p.TipoProducto, p.Cantidad, p.PrecioUnitario, costo);
    }
    printf("\tTotal a pagar: $%.2f\n", totalAPagar);
}

int main() {
    srand(time(NULL));

    int cantidadClientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadClientes);
    struct Cliente clientes[cantidadClientes];

    for(int i = 0; i < cantidadClientes; i++){
        struct Cliente c;
        c.ClienteID = i + 1;
        c.NombreCliente = (char*)malloc(sizeof(char) * 50);
        printf("\nDatos del cliente %d:\n", c.ClienteID);
        printf("Ingrese el nombre del cliente: ");
        scanf("%s", c.NombreCliente);
        cargarDatosCliente(&c);
        clientes[i] = c;
    }

    printf("\n----- Datos cargados -----\n\n");
    for(int i = 0; i < cantidadClientes; i++){
        mostrarCliente(clientes[i]);
    }

    return 0;
}
