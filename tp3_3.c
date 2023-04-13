#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRES 5
#define MAX_LONG_NOMBRE 50

int main() {
    char *nombres[MAX_NOMBRES]; // Vector de punteros a char
    char nombre[MAX_LONG_NOMBRE];
    int i;

    // Reservar memoria para cada puntero del vector
    for (i = 0; i < MAX_NOMBRES; i++) {
        nombres[i] = (char*)malloc(MAX_LONG_NOMBRE * sizeof(char));
        if (nombres[i] == NULL) {
            printf("Error al reservar memoria.\n");
            return 1;
        }
    }

    // Solicitar y cargar los nombres en el vector
    for (i = 0; i < MAX_NOMBRES; i++) {
        printf("Ingrese el nombre %d: ", i+1);
        fgets(nombre, MAX_LONG_NOMBRE, stdin); // Leer el nombre desde la entrada estándar
        nombre[strlen(nombre)-1] = '\0'; // Eliminar el salto de línea al final del nombre
        strcpy(nombres[i], nombre); // Copiar el nombre al vector de punteros
    }

    // Listar los nombres por pantalla
    printf("\nNombres ingresados:\n");
    for (i = 0; i < MAX_NOMBRES; i++) {
        printf("%d. %s\n", i+1, nombres[i]);
    }

    // Liberar la memoria reservada para cada puntero del vector
    for (i = 0; i < MAX_NOMBRES; i++) {
        free(nombres[i]);
    }

    return 0;
}
