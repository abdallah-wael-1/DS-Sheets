#ifndef STACK_H
#define STACK_H

#define MAXSTACK 100
typedef char stack_entry;

typedef struct {
    int top;
    stack_entry entry[MAXSTACK];
} Stack;

void create_stack(Stack *ps);
int stack_full(Stack *ps);
int stack_empty(Stack *ps);
void push(stack_entry e, Stack *ps);
void pop(stack_entry *pe, Stack *ps);


int stack_size(Stack *ps);

void print_stack(Stack s);

#endif
