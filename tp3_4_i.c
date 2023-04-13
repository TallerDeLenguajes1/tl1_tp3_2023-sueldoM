#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaración de las estructuras
char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

typedef struct {
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
} Producto;

typedef struct {
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
} Cliente;

// Función para generar un número aleatorio entre min y max
int aleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    int cantClientes;

    // Solicitar al usuario la cantidad de clientes
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantClientes);
    fflush(stdin); // Limpiar el buffer de entrada

    // Reservar memoria para el vector de clientes
    Cliente *clientes = (Cliente*)malloc(cantClientes * sizeof(Cliente));
    if (clientes == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    // Generar clientes aleatorios
    srand(time(NULL)); // Inicializar la semilla para la generación de números aleatorios
    for (int i = 0; i < cantClientes; i++) {
        // Reservar memoria para el nombre del cliente
        clientes[i].NombreCliente = (char*)malloc(50 * sizeof(char));
        if (clientes[i].NombreCliente == NULL) {
            printf("Error al reservar memoria.\n");
            return 1;
        }

        // Generar los datos del cliente
        clientes[i].ClienteID = i + 1;
        printf("\nIngrese el nombre del cliente %d: ", i+1);
        scanf("%s", clientes[i].NombreCliente);
        fflush(stdin); // Limpiar el buffer de entrada
        clientes[i].CantidadProductosAPedir = aleatorio(1, 5);

        // Reservar memoria para el vector de productos del cliente
        clientes[i].Productos = (Producto*)malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));
        if (clientes[i].Productos == NULL) {
            printf("Error al reservar memoria.\n");
            return 1;
        }

        // Generar los productos del cliente
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = aleatorio(1, 10);
            clientes[i].Productos[j].TipoProducto = TiposProductos[aleatorio(0, 4)];
            clientes[i].Productos[j].PrecioUnitario = aleatorio(10, 100) / 10.0;
        }
    }

    // Liberar la memoria reservada para cada cliente
    for (int i = 0; i < cantClientes; i++) {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }

    // Liberar la memoria reservada para el vector de clientes
    free(clientes);

    return 0;
}
