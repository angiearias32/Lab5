#include <stdio.h>
#include "include/stack.h"

int main() {

    // Se crea una pila vacía.
    Stack *stack = createStack();

    // Se agregan elementos a la pila.
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    // Muestra el elemento que está en la cima.
    printf("Elemento en la cima: %d\n", peek(stack));

    // Elimina el elemento de la cima.
    printf("Pop: %d\n", pop(stack));

    // Se muestra la nueva cima después del pop.
    printf("Nueva cima: %d\n", peek(stack));

    // Verifica si la pila está vacía.
    if (isEmpty(stack)) {
        printf("La pila esta vacia.\n");
    } else {
        printf("La pila no esta vacia.\n");
    }

    // Libera toda la memoria utilizada.
    freeStack(stack);

    return 0;
}
