#include <stdio.h>
#include "queue.h"

void createQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isQueueEmpty(Queue *q) {
    return q->size == 0;
}

int isQueueFull(Queue *q) {
    return q->size == MAX;
}

void enqueue(Queue *q, Customer c) {
    if (isQueueFull(q)) {
        printf("Queue Full!\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = c;
    q->size++;
}

Customer dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue Empty!\n");
        Customer dummy = {"", -1};
        return dummy;
    }
    Customer c = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return c;
}

void displayQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("No customers in queue.\n");
        return;
    }
    printf("\nCurrent waiting customers:\n");
    
    int current_index = q->front; 
    
    for (int count = 0; count < q->size; count++) {

        printf("ID: %d, Name: %s\n", q->items[current_index].ID, q->items[current_index].name);
        current_index = (current_index + 1) % MAX;
    }
}