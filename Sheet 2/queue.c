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
int queueEmpty(Queue *pq) {
    return pq->size == 0;
}

/*
Pre: Queue q is initialized
Post: Returns true if queue is full, false otherwise
*/
int queueFull(Queue *pq) {
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

/*
Pre: Queue q is initialized
Post: Returns number of elements in the queue
*/
int queueSize(Queue *pq) {
    return pq->size;
}

/*
Pre: Queue q is initialized and not empty
Post: Prints all elements from front to rear without modifying the queue
*/
void printQueue(Queue *pq) {
    if (queueEmpty(pq)) {
        printf("Queue is empty!\n");
        return;
    }

    int i = pq->front;
    int count = pq->size;
    printf("Queue contents:\n");
    while (count--) {
        printf("%d\n", pq->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
}


/*
Pre: Queue pq is initialized
Post: Returns the last element in the queue without modifying it.
Prints message and returns -1 if queue is empty 
*/
QueueEntry lastElement(Queue *pq) {
    if (queueEmpty(pq)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return pq->items[pq->rear];
}

/* 
Pre: Queue pq is initialized
Post: Returns a copy of the first element in the queue without modifying it.
Prints message and returns -1 if queue is empty 
*/
QueueEntry firstElementCopy(Queue *pq) {
    if (queueEmpty(pq)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return pq->items[pq->front];
}

/* 
Pre: Queue pq is initialized
Post: Queue pq is reset to empty state (front=0, rear=-1, size=0) 
*/
void destroyQueue(Queue *pq) {
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

/* 
Pre: Both source and new queues are initialized
Post: new becomes a copy of source queue (all elements and state copied) 
*/
void copyQueue(Queue *source, Queue *new) {
    *new = *source; // shallow copy is fine since items are in array implementation
}
