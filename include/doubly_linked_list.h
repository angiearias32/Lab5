#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct DNode {

    int data;
    struct DNode *next;
    struct DNode *prev;

} DNode;

typedef struct {

    DNode *head;
    int size;

} DoublyLinkedList;

DoublyLinkedList* createList();

void insertAtBeginning(DoublyLinkedList *list int value);

void insertAtEnd(DoublyLinkedList *list int value);

void insertAtPosition(DoublyLinkedList *list int value, int position);

void removeNode(DoublyLinkedList *list, int value);

int findNode(DoublyLInkedList *list, int value);

void printForward(DoublyLinkedList *list);

void printBackward(DoublyLinkedList *list);

void freeList(DoublyLinkedList *list);

#endif
