#include <stdio.h>

/**
 *  Búsqueda binaria: busca un elemento en un arreglo de enteros ordenado
 *  Complejidad: O(log n) en el mejor y promedio de los casos
 *  -------------
 *  Prerequisitos: El arreglo debe estar ordenado de manera ascendente.
 *  Usa la estrategia de divide y vencerás para reducir el espacio de búsqueda a 
 *  la mitad en cada iteración.
 * 
 *  No en todos los casos la búsqueda binaria es más eficiente que la búsqueda lineal,
 *  especialmente en arreglos pequeños o cuando el elemento buscado está cerca del
 *  inicio del arreglo.
 */

 int binarySearch(int data[], int bot, int top, int target) {
    
    if (bot > top) {
        return -1; // Elemento no encontrado
    }

    int mid = bot + (top - bot) / 2; // Evita overflow

    // Caso excepcion: Se halló el valor

    if(data[mid] == target) {
        return mid;
    }

    if (data[mid] > target) {
        return binarySearch(data, bot, mid - 1, target); // Buscar en la mitad inferior
    }
    
    if (data[mid] < target) {
        return binarySearch(data, mid + 1, top, target); // Buscar en la mitad superior
    }

    return -1;

}

int main() {
    int data[] = {1, 4, 7, 2, 3, 9, 8};
    int top = 6;
    int bot = 0;
    int target = 3;


    // %d is used to print an integer value
    // %f is used to print a floating-point value

    printf("El resultado es: %d", binarySearch(data, bot, top, target));

    return 0;
}