#include <stdio.h>
#include "stack.h"
#include "queue.h"

int main() {
    Queue q, tempQ;
    Stack s;
    Customer c, tempCustomer;
    int choice;

    createQueue(&q);
    createStack(&s);

    do {
        printf("\n===== Car Workshop Menu =====\n");
        printf("1. Add a New Customer\n");
        printf("2. Serve a Customer\n");
        printf("3. Display Customers Information\n");
        printf("4. Display Customers in Most-Recent Order\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("\nEnter Customer ID: ");
                scanf("%d", &c.ID);
                printf("Enter Customer Name: ");
                scanf(" %[^\n]", c.name);

                enqueue(&q, c);
                printf("Customer Added Successfully!\n");
                break;

            case 2:
                if (isQueueEmpty(&q)) {
                    printf("\nNo customers to serve.\n");
                } else {
                    c = dequeue(&q);
                    printf("\nServing Customer:\n");
                    printf("ID: %d, Name: %s\n", c.ID, c.name);
                }
                break;

            case 3:
                displayQueue(&q);
                break;

            case 4:
                createStack(&s);
                createQueue(&tempQ);

                while (!isQueueEmpty(&q)) {
                    tempCustomer = dequeue(&q);
                    push(&s, tempCustomer);      
                    enqueue(&tempQ, tempCustomer);
                }

                printf("\n--- Customers (Most Recent First) ---\n");
                displayStack(&s);

                while (!isQueueEmpty(&tempQ)) {
                    tempCustomer = dequeue(&tempQ);
                    enqueue(&q, tempCustomer);
                }

                break;

            case 5:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid choice, try again.\n");
        }

    } while (choice != 5);

    return 0;
}
