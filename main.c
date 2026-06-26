#include <stdio.h>
#include "include/linked_list.h"

int main() {

    LinkedList *list = createList();

    printf("lista inicial:\n");
    printList(list);

    addNode(list, 10);
    addNode(list, 20);
    addNode(list, 30);
    addNode(list, 40);

    printf("\nDespues de agregar nodos:\n");
    printList(list);

    printf("\nBuscar 20: %d\n", findNode(list, 20));
    printf("Buscar 100: %d\n", findNode(list, 100));

    removeNode(list, 20);

    printf("\nDespues de eliminar el 20:\n");
    printList(list);

    freeList(list);

    return 0;
}


