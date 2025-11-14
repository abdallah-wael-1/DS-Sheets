#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#define MAX_SIZE 100
typedef int QueueEntry;

typedef struct {
    int front;
    int rear;
    int size;
    QueueEntry items[MAX_SIZE];
} Queue;

void createQueue(Queue *pq);
bool queueEmpty(Queue *pq);
bool queueFull(Queue *pq);
void append(QueueEntry e, Queue *pq);
void serve(QueueEntry *pe, Queue *pq);

#endif