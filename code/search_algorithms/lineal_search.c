#include <stdio.h>


// Busqueda lineal: busca un elemento en un arreglo de enteros
// Complejidad: O(n) en todos los casos, donde n es el tamaño del arreglo
int linear_search(int data[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (data[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int data[] = {1, 4, 7, 2, 3, 9, 8};
    int size = 6;
    int target = 3;

    // %d is used to print an integer value
    // %f is used to print a floating-point value

    printf("El resultado es: %d", linear_search(data, size, target));

    return 0;
}