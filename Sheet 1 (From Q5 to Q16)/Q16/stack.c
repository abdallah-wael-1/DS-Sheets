#include "stack.h"

void createStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack s) {
    return s.top == -1;
}

int isStackFull(Stack s) {
    return s.top == MAX - 1;
}

void push(StackEntry e, Stack *s) {
    if (!isStackFull(*s))
        s->entry[++s->top] = e;
}

void pop(StackEntry *e, Stack *s) {
    if (!isStackEmpty(*s))
        *e = s->entry[s->top--];
}

StackEntry stackTop(Stack s) {
    if (!isStackEmpty(s))
        return s.entry[s.top];
    return '\0'; 
}
