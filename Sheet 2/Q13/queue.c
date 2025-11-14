#include <stdio.h>
#include "queue.h"

/*
Pre: Queue q is initialized
Post: Queue q is empty and ready to use
*/
void createQueue(Queue *pq) {
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

/*
Pre: Queue q is initialized
Post: Returns true if queue is empty, false otherwise
*/
bool queueEmpty(Queue *pq) {
    return pq->size == 0;
}

/*
Pre: Queue q is initialized
Post: Returns true if queue is full, false otherwise
*/
bool queueFull(Queue *pq) {
    return pq->size == MAX_SIZE;
}

/*
Pre: Queue q is initialized and not full
Post: Adds item to the rear of the queue
*/
void append(QueueEntry e, Queue *pq) {
    if (queueFull(pq)) {
        printf("Queue is full!\n");
        return;
    }
    pq->rear = (pq->rear + 1) % MAX_SIZE;
    pq->items[pq->rear] = e;
    pq->size++;
}

/*
Pre: Queue q is initialized and not empty
Post: Removes and returns front item of the queue
*/
void serve(QueueEntry *pe, Queue *pq) {
    if (queueEmpty(pq)) {
        printf("Queue is empty!\n");
        return;
    }
    *pe = pq->items[pq->front];
    pq->front = (pq->front + 1) % MAX_SIZE;
    pq->size--;
}
