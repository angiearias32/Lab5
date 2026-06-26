#ifndef LINKED_LIST_H // evita que el archivo se repita
#define LINKED_LIST_H // lee por primera vez y la segunda vez ignora todo

typedef struct Node { //  aqui inicia la estructura Node

    int data; // guarda un dato
    struct Node *next; // guarda la direccion de memoria

} Node; // termina la estructura

typedef struct { // aqui empieza otra estructura

    Node *head; // apunta al primer nodo
    int size; // guarda cuantos nodos hay

} LinkedList; // termina la estructura

LinkedList* createList(); // crea una lista vacia

void addNode(LinkedList *list, int value); // agrega un nodo

void removeNode(LinkedList *list, int value); // elimina un nodo

int findNode(LinkedList *list, int value); //busca un valor

void printList(LinkedList *list); // imprime todos los elementos

void freeList(LinkedList *list); // libera la memoria completa

#endif // termina el #ifndef
