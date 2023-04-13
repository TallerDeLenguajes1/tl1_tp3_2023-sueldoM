#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 12

int main() {
    int matriz[FILAS][COLUMNAS];
    int i, j, total_anual, max_valor, min_valor, max_anio, min_anio, max_mes, min_mes;

    // Inicializar la semilla para la generación de números aleatorios
    srand(time(NULL));

    // Cargar la matriz con valores aleatorios entre 10000 y 50000
    for (i = 0; i < FILAS; i++) {
        total_anual = 0;
        for (j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = rand() % (50000 - 10000 + 1) + 10000; // Generar un número aleatorio entre 10000 y 50000
            total_anual += matriz[i][j];
        }
        printf("Total anual para el año %d: %d\n", i+1, total_anual);
    }

    // Mostrar los valores cargados en la matriz
    printf("\nValores cargados en la matriz:\n");
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    // Calcular el promedio de ganancia por año y mostrarlos por pantalla
    printf("\nPromedio de ganancia por anio:\n");
    for (i = 0; i < FILAS; i++) {
        total_anual = 0;
        for (j = 0; j < COLUMNAS; j++) {
            total_anual += matriz[i][j];
        }
        printf("Anio %d: %.2f\n", i+1, (float)total_anual/COLUMNAS);
    }

    // Obtener el valor máximo y mínimo, y su ubicación en la matriz
    max_valor = matriz[0][0];
    min_valor = matriz[0][0];
    max_anio = min_anio = max_mes = min_mes = 1;

    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] > max_valor) {
                max_valor = matriz[i][j];
                max_anio = i+1;
                max_mes = j+1;
            }
            if (matriz[i][j] < min_valor) {
                min_valor = matriz[i][j];
                min_anio = i+1;
                min_mes = j+1;
            }
        }
    }

    // Mostrar el valor máximo y mínimo, y su ubicación en la matriz
    printf("\nValor maximo: %d (Anio %d, Mes %d)\n", max_valor, max_anio, max_mes);
    printf("Valor minimo: %d (Anio %d, Mes %d)\n", min_valor, min_anio, min_mes);

    return 0;
}
