#include <stdio.h>
#include "include/doubly_linked_list.h"

int main() {

    DoublyLinkedList *list = createList();

    printf("lista inicial:\n");
    printForward(list);

    printf("Hacia atras:\n");
    printBackward(list);

    insertAtBeginning(list, 20);
    insertAtBeginning(list, 10);
    insertAtEnd(list, 40);
    insertAtPosition(list, 30, 2);

    printf("\nDespues de agregar nodos:\n");
    printForward(list);

    printf("Hacia atras:\n");
    printBackward(list);

    printf("\nBuscar 20: %d\n", findNode(list, 20));
    printf("Buscar 100: %d\n", findNode(list, 100));

    removeNode(list, 20);

    printf("\nDespues de eliminar el 20:\n");
    printForward(list);

    printf("Hacia atras:\n");
    printBackward(list);

    freeList(list);

    return 0;
}


