#include <stdio.h>
#include "include/dynamic_array.h"

int main() { // esta funcion prueba las funciones implementadas anteriormente

    DynamicArray *array = createArray();

    printf("Arreglo inicial:\n");
    printArray(array);

    addElement(array, 10);
    addElement(array, 20);
    addElement(array, 30);
    addElement(array, 40);

    printf("\nDespues de agregar elementos:\n");
    printArray(array);

    printf("\nElement en la posicion 2: %d\n", getElement(array, 2));

    removeElement(array, 1);

    printf("\nDespues de eliminar el indice 1:\n");
    printArray(array);

    freeArray(array);

    return 0;
}


