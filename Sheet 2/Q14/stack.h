#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

typedef int stack_entry;

typedef struct {
    stack_entry items[MAX_SIZE];
    int top;
} Stack;

void CreateStack(Stack *ps);
int StackFull(Stack *ps);
int StackEmpty(Stack *ps);
void Push(stack_entry pe, Stack *ps);
void Pop(stack_entry *pe, Stack *ps);

#endif
