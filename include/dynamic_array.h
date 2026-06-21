#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct {

    int *data; //puntero donde se almacenan los numeris del arreglo dinamico
    int size; // cantidad de elementos actual
} DynamicArray;

DynamicArray* createArray(); // crear arreglo

void addElement(DynamicArray *array, int value); //agregar elemento

void removeElement(DynamicArray *array, int index); // eliminar elemento

int getElement(DynamicArray *array, int index); // obtener por indice

void printArray(DynamicArray *array); //imprimir arreglo

void freeArray(DynamicArray *array); // liberar memoria

#endif
