#ifndef STACK_H
#define STACK_H

#define MAXSTACK 100
typedef char stack_entry;

typedef struct {
    int top;
    stack_entry entry[MAXSTACK];
} Stack;


void createStack(Stack *ps);
int stack_full(Stack *ps);
int stack_empty(Stack *ps);
void push(stack_entry e, Stack *ps);
void pop(stack_entry *pe, Stack *ps);
stack_entry first_element(Stack *ps);
stack_entry last_element(Stack *ps);
void destroy_stack(Stack *ps);
void copy_stack(Stack *source, Stack *new);
int stack_size(Stack *ps);



#endif
