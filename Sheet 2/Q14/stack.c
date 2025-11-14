#include "stack.h"

void CreateStack(Stack *ps) {
    ps->top = -1;
}

int StackFull(Stack *ps) {
    return ps->top == MAX_SIZE - 1;
}

int StackEmpty(Stack *ps) {
    return ps->top == -1;
}

void Push(stack_entry pe, Stack *ps) {
    if (!StackFull(ps)) {
        ps->items[++(ps->top)] = pe;
    }
}

void Pop(stack_entry *pe, Stack *ps) {
    if (!StackEmpty(ps)) {
        *pe = ps->items[(ps->top)--];
    }
}
