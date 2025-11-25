#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* --- User-level functions --- */
stack_entry first_element_user(Stack ps) {
    Stack temp;
    createStack(&temp);
    stack_entry e, first;

    while (!isEmpty(&ps)) {
        e = pop(&ps);
        push(&temp, e);
        first = e;  
    }

    while (!isEmpty(&temp)) {
        e = pop(&temp);
        push(&ps, e);
    }

    return first;
}

stack_entry last_element_user(Stack ps) {
    if (isEmpty(&ps)) {
        printf("Stack is empty!\n");
        return -1; 
    }
    stack_entry top = pop(&ps);
    push(&ps, top);
    return top;
}

void destroy_stack_user(Stack *ps) {
    while (!isEmpty(ps)) {
        pop(ps);
    }
}

void copy_stack_user(Stack ps, Stack *newStack) {
    createStack(newStack);
    Stack temp;
    createStack(&temp);
    stack_entry e;

    while (!isEmpty(&ps)) {
        e = pop(&ps);
        push(&temp, e);
    }

    while (!isEmpty(&temp)) {
        e = pop(&temp);
        push(newStack, e);
        push(&ps, e);
    }
}

int stack_size_user(Stack ps) {
    int count = 0;
    Stack temp;
    createStack(&temp);
    stack_entry e;

    while (!isEmpty(&ps)) {
        e = pop(&ps);
        push(&temp, e);
        count++;
    }

    while (!isEmpty(&temp)) {
        e = pop(&temp);
        push(&ps, e);
    }

    return count;
}

void print_stack_user(Stack ps) {
    Stack temp;
    createStack(&temp);
    stack_entry e;

    while (!isEmpty(&ps)) {
        e = pop(&ps);
        printf("%d\n", e);
        push(&temp, e);
    }

    while (!isEmpty(&temp)) {
        e = pop(&temp);
        push(&ps, e);
    }
}

/* --- Main function --- */
int main() {
    Stack ps, copy;
    createStack(&ps);
    createStack(&copy);

    push(&ps, 10);
    push(&ps, 20);
    push(&ps, 30);
    push(&ps, 40);

    printf("Original Stack contents:\n");
    print_stack_user(ps);

    printf("First element entered (user): %d\n", first_element_user(ps));
    printf("Last element entered (user): %d\n", last_element_user(ps));

    copy_stack_user(ps, &copy);
    printf("Copied Stack contents (user):\n");
    print_stack_user(copy);

    printf("Size of original stack (user): %d\n", stack_size_user(ps));

    destroy_stack_user(&ps);
    printf("Original stack destroyed.\n");

    printf("Contents of original stack after destroy:\n");
    print_stack_user(ps);

    return 0;
}
