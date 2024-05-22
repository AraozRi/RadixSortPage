#include <stdio.h>
#include <stdlib.h>

// Función para obtener el número máximo en el arreglo
int obtenerMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Función para hacer el conteo y ordenar de acuerdo al dígito específico
void contarYOrdenar(int arr[], int n, int exp) {
    int output[n]; // Arreglo de salida
    int count[10] = {0};

    // Almacenar el conteo de las ocurrencias en count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Cambiar count[i] para que contenga la posición actual de este dígito en output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Construir el arreglo de salida
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copiar el arreglo de salida a arr[], para que arr[] contenga los números ordenados según el dígito actual
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Función principal para implementar Radix Sort
void radixSort(int arr[], int n) {
    // Encontrar el número máximo para saber el número de dígitos
    int max = obtenerMax(arr, n);

    // Hacer el conteo y ordenamiento para cada dígito
    for (int exp = 1; max / exp > 0; exp *= 10)
        contarYOrdenar(arr, n, exp);
}

// Función para imprimir un arreglo
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Función principal ejemplo 
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Arreglo original:\n");
    imprimirArreglo(arr, n);
    radixSort(arr, n);
    printf("Arreglo ordenado:\n");
    imprimirArreglo(arr, n);
    return 0;
}
