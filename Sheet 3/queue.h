#ifndef QUEUE_H
#define QUEUE_H

#include "global.h"

typedef struct queue {
    Customer items[MAX];
    int front;
    int rear;
    int size;
} Queue;

void createQueue(Queue *q);
int isQueueEmpty(Queue *q);
int isQueueFull(Queue *q);
void enqueue(Queue *q, Customer c);
Customer dequeue(Queue *q);
void displayQueue(Queue *q);

#endif
