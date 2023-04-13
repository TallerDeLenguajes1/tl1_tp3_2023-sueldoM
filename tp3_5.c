#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int cantidad_nombres;
    char buffer[50];
    int i;

    printf("Ingrese la cantidad de nombres que desea ingresar: ");
    scanf("%d", &cantidad_nombres);
    getchar(); // Consumimos el '\n' que quedó en el buffer

    char* nombres[cantidad_nombres];

    for (i = 0; i < cantidad_nombres; i++) {
        printf("Ingrese el nombre %d: ", i+1);
        fgets(buffer, sizeof(buffer), stdin);

        nombres[i] = (char*) malloc(strlen(buffer)+1);
        strcpy(nombres[i], buffer);
    }

    printf("Los nombres ingresados son:\n");
    for (i = 0; i < cantidad_nombres; i++) {
        printf("%d: %s", i+1, nombres[i]);
        free(nombres[i]);
    }

    return 0;
}
