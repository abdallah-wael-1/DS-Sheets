#include <stdio.h>
#include "queue.h"

QueueEntry lastElement_user(Queue q)
{
    Queue temp = q;
    QueueEntry e;
    while (!queueEmpty(&temp)) {
        serve(&e, &temp);
    }
    return e; 
}

QueueEntry firstElementCopy_user(Queue q)
{
    Queue temp = q;
    QueueEntry e;
    serve(&e, &temp);
    return e; 
}

void destroyQueue_user(Queue *q)
{
    QueueEntry e;
    while (!queueEmpty(q)) {
        serve(&e, q);
    }
}

void copyQueue_user(Queue q, Queue *newQ)
{
    createQueue(newQ);
    Queue temp = q;
    Queue rev;
    createQueue(&rev);
    QueueEntry e;

    while (!queueEmpty(&temp)) {
        serve(&e, &temp);
        append(e, &rev);
    }

    while (!queueEmpty(&rev)) {
        serve(&e, &rev);
        append(e, newQ);
    }
}

int queueSize_user(Queue q)
{
    int count = 0;
    Queue temp = q;
    QueueEntry e;

    while (!queueEmpty(&temp)) {
        serve(&e, &temp);
        count++;
    }

    return count;
}



int main() {
    Queue q;
    QueueEntry item;
    Queue copyQ;
    char choice;

    createQueue(&q);

    while (1) {
        printf("\nMenu:\n");
        printf("a) Append (enqueue) an element\n");
        printf("b) Serve (dequeue) an element\n");
        printf("c) Show queue size\n");
        printf("d) Print queue contents\n");
        printf("f) Last element in the queue\n");
        printf("g) Copy of first element in the queue\n");
        printf("h) Destroy queue\n");
        printf("i) Copy queue to another\n");
        printf("e) Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case 'a':
                if (!queueFull(&q)) {
                    printf("Enter element: ");
                    scanf("%d", &item); 
                    append(item, &q);
                } else {
                    printf("Queue is full!\n");
                }
                break;

            case 'b':
                if (!queueEmpty(&q)) {
                    serve(&item, &q);
                    printf("Served: %d\n", item); 
                } else {
                    printf("Queue is empty!\n");
                }
                break;

            case 'c':
                printf("Queue size: %d\n", queueSize(&q));
                break;

            case 'd':
                if (!queueEmpty(&q)) {
                    printQueue(&q);
                } else {
                    printf("Queue is empty!\n");
                }
                break;

            case 'f': 
                if (!queueEmpty(&q)) {
                    printf("Last element: %d\n", lastElement(&q));
                } else {
                    printf("Queue is empty!\n");
                }
                break;

            case 'g': 
                if (!queueEmpty(&q)) {
                    printf("Copy of first element: %d\n", firstElementCopy(&q));
                } else {
                    printf("Queue is empty!\n");
                }
                break;

            case 'h':  
                destroyQueue(&q);
                printf("Queue destroyed.\n");
                break;

            case 'i':  
                copyQueue(&q, &copyQ);
                printf("Queue copied.\n");
                break;

            case 'e':
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
