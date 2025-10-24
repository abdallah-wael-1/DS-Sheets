#include "stack.h"
#include <stdio.h>

/* 
Pre: stack is initialized
Post: stack is empty
*/
void create_stack(Stack *ps) {
    ps->top = 0;
}

/* 
Pre: stack is initialized
Post: returns 1 if stack is full, 0 otherwise
*/
int stack_full(Stack *ps) {
    return ps->top == MAXSTACK;
}

/* 
Pre: stack is initialized
Post: returns 1 if stack is empty, 0 otherwise
*/
int stack_empty(Stack *ps) {
    return ps->top == 0;
}

/* 
Pre: stack is initialized and not full
Post: element e is added to the top of the stack
*/
void push(stack_entry e, Stack *ps) {
    ps->entry[ps->top++] = e;
}

/* 
Pre: stack is initialized and not empty
Post: removes top element and stores it in *pe
*/
void pop(stack_entry *pe, Stack *ps) {
    *pe = ps->entry[--ps->top];
}

/* 
Pre: stack is initialized
Post: returns first element entered or '\0' if stack is empty
*/
stack_entry first_element(Stack *ps) {
    if (stack_empty(ps)) {
        return '\0';
    }
    return ps->entry[1];
}

/* 
Pre: stack is initialized
Post: returns last element entered (top) or '\0' if stack is empty
*/
stack_entry last_element(Stack *ps) {
    if (stack_empty(ps)) {
        return '\0';
    }
    return ps->entry[ps->top - 1];
}

/* 
Pre: stack is initialized
Post: empties the stack
*/
void destroy_stack(Stack *ps) {
    ps->top = 0;
}

/* 
Pre: source stack is initialized
Post: copies all elements from source to dest stack
*/
void copy_stack(Stack *source, Stack *new) {
    new->top = source->top;
    for (int i = 0; i < source->top; i++)
        new->entry[i] = source->entry[i];
}

/* 
Pre: stack is initialized
Post: returns number of elements in stack
*/
int stack_size(Stack *ps) {
    return ps->top;
}
