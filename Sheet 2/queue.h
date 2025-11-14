#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 100
typedef int QueueEntry;

typedef struct {
    int front;
    int rear;
    int size;
    QueueEntry items[MAX_SIZE];
} Queue;

void createQueue(Queue *pq);
int queueEmpty(Queue *pq);
int queueFull(Queue *pq);
void append(QueueEntry e, Queue *pq);
void serve(QueueEntry *pe, Queue *pq);

int queueSize(Queue *pq);
void printQueue(Queue *pq);

QueueEntry lastElement(Queue *pq);
QueueEntry firstElementCopy(Queue *pq);
void destroyQueue(Queue *pq);
void copyQueue(Queue *source, Queue *new);

#endif
