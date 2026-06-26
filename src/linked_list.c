#include <stdio.h> // como para funciones como print
#include <stdlib.h> // para malloc() free()
#include "../include/linked_list.h" // conoce las estructuras

LinkedList* createList() { // devuelve un puntero a una lista creada recientemente

    LinkedList *list = malloc(sizeof(LinkedList)); // se reserva memoria para LinkedList

    if (list == NULL) { // aqui comprueba si malloc funciono
        return NULL;

    }

    list->head = NULL;
    list->size = 0;

    return list; // cuando se llame createList() se recibe la direccion de la lista recien creada

}

void addNode(LinkedList *list, int value) {

    Node *newNode = malloc(sizeof(Node)); // reserva memoria para nuevo nodo

    if (newNode == NULL) { // comprueba que malloc no fallo
        return;

    }

    newNode->data = value; // Aqui se guarda el valor del usuario
    newNode->next = NULL; // aca no se apunta a ningun nodo ya que es el ultimo nodo

    if (list->head == NULL) {
        list->head = newNode;
        list->size++;
        return;
    }

    Node *current = list->head;

    while (current->next != NULL) { // tiene la funcion de mover el puntero hasta llegar al ultimo de la lista
        current = current->next;

    }

    current->next = newNode; //apunta al ultimo nodo nuevo
    list->size++; // actualiza el contador de nodos

}


void printList(LinkedList *list) {

    Node *current = list->head; // comienza el primer nodo

    while (current != NULL) { // recorre todos los nodos hasta llegar al final
        printf("%d ", current->data);
        current = current->next;

    }

    printf("\n");

}

int findNode(LinkedList *list, int value) {

    Node *current = list->head; // comienza en el primer nodo
    while (current != NULL) {
        if (current->data == value) {

            return 1;
        }
        current = current->next;
    }

    return 0; // no encontro el valor
}

void removeNode(LinkedList *list, int value) {

    if  (list->head == NULL) { // si la lista esta vacia no elimina nada
        return;

    }

    Node *current = list->head;
    Node *previous = NULL;

// busca el nodo que contiene el valor
    while (current != NULL && current->data != value) {

        previous = current;
        current = current->next;
    }

// si no encontro el valor
    if (current == NULL) {
        return;
    }

// si el nodo que se va a eliminar es el primero

    if (previous == NULL) {
        list->head = current->next;
        free(current); //libera memoria del nodo eliminado
        list->size--;
        return;
    }


    previous->next = current->next; // el nodo anterior ahora apunta al siguiente
    free(current); // libera la memoria del nodo eliminado
    list->size--; // disminuye la cantidad de nodos

}

void freeList(LinkedList *list) {

    Node *current = list->head; // comienza en el primer nodo

    while (current != NULL) { // nodos pendientes de liberar

        Node *next = current->next; // guarda la direccion del siguiente nodo antes de borrar el actual

        free(current); // libera el nodo actual

        current = next; // continua con el siguiente nodo
    }

    free(list); // libera la estructura
}
