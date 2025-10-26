#include <stdio.h>
#include "stack.h"

stack_entry firstElement(Stack s)
{
    Stack temp = s;
    stack_entry e;
    while (!stack_empty(&temp)) {
        pop(&e, &temp);
    }
    return e;
}

stack_entry last_element_user(Stack s) {
    stack_entry e;
    pop(&e, &s);
    return e;
}

void destroy_stack_user(Stack *s) {
    while (!stack_empty(s)) {
        stack_entry e;
        pop(&e, s);
    }
}

void copy_stack_user(Stack s, Stack *new) {
    createStack(new);
    Stack temp = s;
    stack_entry e;
    Stack tmp_rev;
   createStack(&tmp_rev);

    while (!stack_empty(&temp)) {
        pop(&e, &temp);
        push(e, &tmp_rev);
    }

    while (!stack_empty(&tmp_rev)) {
        pop(&e, &tmp_rev);
        push(e, new);
    }
}

int stacksize_user(Stack S)
{
    Stack temp;          
    createStack(&temp);
    Stack copy = S;      
    int counter = 0;
    stack_entry e;

    while (!stack_empty(&copy))
    {
        pop(&e, &copy);
        push(e, &temp);
        counter++;
    }
    
    while (!stack_empty(&temp))
    {
        pop(&e, &temp);
        push(e, &S);
    }

    return counter;
}


void print_stack_user(Stack s) {
    Stack temp = s;
    stack_entry e;
    while (!stack_empty(&temp)) {
        pop(&e, &temp);
        printf("%c\n", e);
    }
}


int main() {
    Stack s;
    create_stack(&s);
    char choice, item;
    Stack copy;

    while (1) {
        printf("\nMenu:\n");
        printf("a) Push element\n");
        printf("b) Pop element\n");
        printf("c) First element (user)\n");
        printf("d) Last element (user)\n");
        printf("e) Stack size (user)\n");
        printf("f) Copy stack (user)\n");
        printf("g) Print stack (user)\n");
        printf("h) Destroy stack (user)\n");
        printf("i) Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                if (!stack_full(&s)) {
                    printf("Enter element: ");
                    scanf(" %c", &item);
                    push(item, &s);
                } else printf("Stack full!\n");
                break;

            case 'b':
                if (!stack_empty(&s)) {
                    pop(&item, &s);
                    printf("Popped: %c\n", item);
                } else printf("Stack empty!\n");
                break;

            case 'c':
                if (!stack_empty(&s))
                    printf("First element: %c\n", first_element_user(s));
                else printf("Stack empty!\n");
                break;

            case 'd':
                if (!stack_empty(&s))
                    printf("Last element: %c\n", last_element_user(s));
                else printf("Stack empty!\n");
                break;

            case 'e':
                printf("Stack size: %d\n", stack_size_user(s));
                break;

            case 'f':
                copy_stack_user(s, &copy);
                printf("Stack copied.\n");
                break;

            case 'g':
                if (!stack_empty(&s)) {
                    printf("Stack contents:\n");
                    print_stack_user(s);
                } else printf("Stack empty!\n");
                break;

            case 'h':
                destroy_stack_user(&s);
                printf("Stack destroyed.\n");
                break;

            case 'i':
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
