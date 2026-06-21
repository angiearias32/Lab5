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

