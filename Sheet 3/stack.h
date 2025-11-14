#ifndef STACK_H
#define STACK_H

#include "global.h"

typedef struct stack {
    Customer items[MAX];
    int top;
} Stack;

void createStack(Stack *s);
int isStackEmpty(Stack *s);
int isStackFull(Stack *s);
void push(Stack *s, Customer c);
Customer pop(Stack *s);
void displayStack(Stack *s);

#endif
