#include <stdio.h>
#include "stack.h"

int main() {
    char choice;
    stack_entry item;
    Stack s;
    create_stack(&s);

    while (1) {
        printf("\nMenu:\n");
        printf("a) Push an element\n");
        printf("b) Pop an element\n");
        printf("c) Show stack size\n");
        printf("d) Print stack contents\n");
        printf("e) Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                if (!stack_full(&s)) {
                    printf("Enter element: ");
                    scanf(" %c", &item);
                    push(item, &s);
                } else {
                    printf("Stack is full!\n");
                }
                break;

            case 'b':
                if (!stack_empty(&s)) {
                    pop(&item, &s);
                    printf("Popped: %c\n", item);
                } else {
                    printf("Stack is empty!\n");
                }
                break;

            case 'c':
                printf("Stack size: %d\n", stack_size(&s));
                break;

            case 'd':
                if (!stack_empty(&s)) {
                    printf("Stack contents:\n");
                    print_stack(s);
                } else {
                    printf("Stack is empty!\n");
                }
                break;

            case 'e':
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
