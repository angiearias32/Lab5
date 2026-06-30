#include <stdio.h>
#include <stdlib.h>

#include "../include/doubly_linked_list.h"

DoublyLinkedList* createList() {

    DoublyLinkedList *list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));

    list->head = NULL;
    list->size = 0;

    return list;

}

void insertAtBeginning(DoublyLinkedList *list, int value) {

    DNode *newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = value;

    newNode->next = list->head;
    newNode->prev = NULL;

    if (list->head != NULL) {
        list->head->prev = newNode;

    }

    list->head = newNode; // convierte el nuevo nodo en el primero de la lista
    list->size++; // actualiza la cantidad de nodos que hicimos en la lista enlazada simple
}

void insertAtEnd(DoublyLinkedList *list, int value) {

    DNode *newNode = (DNode*)malloc(sizeof(DNode));

    newNode->data = value;
    newNode->next = NULL; // es NULL porque es el ultimo nodo de la lista

    if (list->head == NULL) {
        newNode->prev = NULL;
        list->head = newNode; // aumenta el tamaño
        list->size++;

        return;
    }


    DNode *current = list->head;
    while (current->next != NULL) { // su mision es encontrar el ultimo nodo

        current = current->next;

    }
// aqui ya encontramos el ultimo nodo
    current->next = newNode;
    newNode->prev = current;
    list->size++;


}

void insertAtPosition(DoublyLinkedList *list, int value, int position) {

    if (position < 0 || position > list->size) { // aqui se valida la posicion
        return;

    }
// en esta parte se llama a las funciones anteriores para no estar repitiendo codigo

    if (position == 0) {
        insertAtBeginning(list, value);
        return;

    }

    if (position == list->size) {
        insertAtEnd(list, value);
        return;
    }

    // crear el nuevo nodo
    DNode *newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = value;

    // buscar el nodo anterior a la posicion donde se insertara

    DNode *current = list->head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;

    }

    // conectar el nuevo nodo
    newNode->next = current->next;
    newNode->prev = current;

    current->next->prev = newNode;
    current->next = newNode;

    list->size++;


}

int findNode(DoublyLinkedList *list, int value) {

    DNode *current = list->head;

    while (current != NULL) {

        if (current->data == value) {
            return 1;

        }

        current = current->next;

    }

    return 0;

}

void printForward(DoublyLinkedList *list) {

    DNode *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);

        current = current->next;

    }

    printf("\n");

}


void printBackward(DoublyLinkedList *list) {

    DNode *current = list->head;

    while (current != NULL && current->next != NULL) {

        current = current->next;
    }

    while (current != NULL) {
        printf("%d ", current->data);

        current = current->prev;

    }
    printf("\n");
}


void freeList(DoublyLinkedList *list) {

    DNode *current = list->head; // se crea un puntero auxiliar
    while (current != NULL) {

        DNode *next = current->next;
        free(current);
        current = next;

    }

    free(list);

}


void removeNode(DoublyLinkedList *list, int value) {

    DNode *current = list->head;
    while (current != NULL && current->data != value) { // recorre la lista hasta que encuentre el valor o en su defecto llega al final

        current = current->next;
    }
 // funciona para encontrar un nodo y si el usuario quiere eliminar uno que no existe se sale de la funcion

    if (current == NULL) {
        return;

    }


    if (current->prev == NULL) {
        list->head = current->next;

        if (current->next != NULL) {
            current->next->prev = NULL;

        }
   }

    // se reconcetan los nodos

    else {

        current->prev->next = current->next;

        if (current->next != NULL) {

            current->next->prev = current->prev;
        }

    }
    free(current);
    list->size--;
}
