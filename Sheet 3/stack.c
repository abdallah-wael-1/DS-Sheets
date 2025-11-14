#include <stdio.h>
#include "stack.h"

void createStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

int isStackFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, Customer c) {
    if (isStackFull(s)) {
        printf("Stack Full!\n");
        return;
    }
    s->items[++s->top] = c;
}

Customer pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack Empty!\n");
        Customer dummy = {"", -1};
        return dummy;
    }
    return s->items[s->top--];
}

void displayStack(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("\nCustomers in most-recent order:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("ID: %d, Name: %s\n", s->items[i].ID, s->items[i].name);
    }
}
