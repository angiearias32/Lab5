#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"

// se crea una pila vacia
Stack* createStack() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}
// verifica si la pila esta vacia y devuelve un 1 si esta vacia y un 0 si no
int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

// agrega un elemento en la parte de arriba de la pila
void push(Stack *stack, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// elimina y devuelve el elemento que esta en la parte superior y si la pila esta vacia devuelve -1
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        return -1;
    }

    Node *temp = stack->top;
    int value = temp->data;

    stack->top = temp->next;
    free(temp);

    return value;
}

// devuelve el valor de arriba de la pila sin eliminarlo
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        return -1;
    }

    return stack->top->data;
}

// libera toda la memoria utilizada
void freeStack(Stack *stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }

    free(stack);
}
