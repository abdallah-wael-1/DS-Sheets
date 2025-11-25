#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void createStack(Stack *s) {
    s->top = NULL;
    s->size = 0;
}

int isEmpty(Stack *s) {
    return (s->top == NULL);
}

int isFull(Stack *s) {
    return 0; 
}

void push(Stack *s, stack_entry e) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = e;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

stack_entry pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    Node *temp = s->top;
    stack_entry val = temp->data;
    s->top = temp->next;
    free(temp);
    s->size--;
    return val;
}

stack_entry peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return s->top->data;
}
