#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* nombres[5];
    char buffer[50];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Ingrese el nombre %d: ", i+1);
        fgets(buffer, sizeof(buffer), stdin);

        nombres[i] = (char*) malloc(strlen(buffer)+1);
        strcpy(nombres[i], buffer);
    }

    printf("Los nombres ingresados son:\n");
    for (i = 0; i < 5; i++) {
        printf("%d: %s", i+1, nombres[i]);
        free(nombres[i]);
    }

    return 0;
}
