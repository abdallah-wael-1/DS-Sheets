#include "stack.h"
#include <stdio.h>

/*
Pre: None
Post: The stack is initialized to be empty
*/
void create_stack(Stack *ps) {
    ps->top = 0;
}

/*
Pre: None
Post: Returns 1 if the stack is full, otherwise returns 0
*/
int stack_full(Stack *ps) {
    return ps->top == MAXSTACK;
}

/*
Pre: None
Post: Returns 1 if the stack is empty, otherwise returns 0
*/
int stack_empty(Stack *ps) {
    return ps->top == 0;
}

/*
Pre: The stack is initialized and not full
Post: The element e has been stored at the top of the stack; and e does not change
*/
void push(stack_entry e, Stack *ps) {
    ps->entry[ps->top++] = e;
}

/*
Pre: The stack is initialized and not empty
Post: The top element of the stack is removed and stored in *pe
*/
void pop(stack_entry *pe, Stack *ps) {
    *pe = ps->entry[--ps->top];
}

/*
Pre: The stack is initialized
Post: Returns number of elements without changing the stack
*/
int stack_size(Stack *ps) {
    return ps->top;
}

/*
Pre: The stack is initialized
Post: Prints all elements of the stack without changing it
*/
void print_stack(Stack s) {
    for (int i = s.top - 1; i >= 0; i--) {
        printf("%c\n", s.entry[i]);
    }
}
