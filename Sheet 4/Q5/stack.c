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


stack_entry last_element(Stack *s) {
    return peek(s);
}


stack_entry first_element_copy(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    Node *cur = s->top;
    while (cur->next != NULL) cur = cur->next;
    return cur->data;
}


void destroyStack(Stack *s) {
    while (!isEmpty(s)) pop(s);
}

void copyStack(Stack *src, Stack *dest) {
    dest->top = NULL;
    dest->size = 0;

    if (isEmpty(src)) return;

    Stack temp;
    temp.top = NULL;
    temp.size = 0;

    Node *cur = src->top;
    while (cur != NULL) {
        Node *n = (Node*)malloc(sizeof(Node));
        n->data = cur->data;
        n->next = temp.top;
        temp.top = n;
        temp.size++;
        cur = cur->next;
    }

    cur = temp.top;
    while (cur != NULL) {
        Node *n = (Node*)malloc(sizeof(Node));
        n->data = cur->data;
        n->next = dest->top;
        dest->top = n;
        dest->size++;
        cur = cur->next;
    }
}


int stack_size_impl(Stack *s) {
    return s->size;
}

