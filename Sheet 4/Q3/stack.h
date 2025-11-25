#ifndef STACK_H
#define STACK_H

typedef int stack_entry;

typedef struct Node {
    stack_entry data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
    int size;
} Stack;


void createStack(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, stack_entry e);
stack_entry pop(Stack *s);
stack_entry peek(Stack *s);

#endif
