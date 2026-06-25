#include <stdio.h>
#include <stdlib.h>
#include "../include/dynamic_array.h"

DynamicArray* createArray() {
    DynamicArray  *array = malloc(sizeof(DynamicArray)); // reserva memoria para estructura

    if (array == NULL) {
        return NULL;

    }

    array->data = NULL;
    array->size = 0;

    return array;

}

void addElement(DynamicArray *array, int value) {

    int *temp = realloc(array->data, (array->size + 1) * sizeof(int));

    if (temp == NULL) {

        return;

    }

    array->data = temp;

    array->data[array->size] = value;

    array->size++;
}

void removeElement(DynamicArray *array, int index) {

    if (index < 0 || index >= array->size) { // esta linea pregunta si es valido el valor
        return;
    }
    for (int i = index; i < array->size - 1; i++) { // cierra el espacio que dejo el elemento eliminado

        array->data[i] = array->data[i + 1];
    }

    array->size--; // actualiza el tamaño del arreglo

    int *temp = realloc(array->data, array->size * sizeof(int)); // usamos temp para no perder la direccion del arreglo original

    if (temp != NULL || array->size == 0) {

        array->data = temp;

    }
}

int getElement(DynamicArray *array, int index) {

    if (index < 0 || index >= array->size) {

        return -1;

    }

    return array->data[index];
}


void printArray(DynamicArray *array) {

    for (int i = 0; i < array->size; i++) {

        printf("%d ", array->data[i]);

    }

    printf("\n");

}


void freeArray(DynamicArray *array) {

    free(array->data);
    free(array);

}
