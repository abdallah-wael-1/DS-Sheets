#ifndef STACK_H
#define STACK_H

#define MAX 100
typedef char StackEntry;

typedef struct {
    StackEntry entry[MAX];
    int top;
} Stack;

void createStack(Stack *s);
int isStackEmpty(Stack s);
int isStackFull(Stack s);
void push(StackEntry e, Stack *s);
void pop(StackEntry *e, Stack *s);
StackEntry stackTop(Stack s);

#endif
