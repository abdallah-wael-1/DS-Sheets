#ifndef STACK_H
#define STACK_H

typedef int Type;


typedef struct node {
    Type info;
    struct node *next;
} Node;

typedef struct  stack{
    Node *head;
} Stack;

void createStack(Stack *s);
int isStackEmpty(Stack s);
int isStackFull(Stack s);
void push(Type item, Stack *s);
Type pop(Stack *s);
Type peek(Stack s);

#endif
