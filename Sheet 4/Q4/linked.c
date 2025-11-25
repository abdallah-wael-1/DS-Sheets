#include "linked.h"
#include <stdlib.h>

void createQueue(Queue *pq) {
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}

void queueIsEmpty(Queue *pq) {
    return pq->size == 0;
}

void queueIsFull(Queue *pq) {
    return 0;
}

void enqueue(QueueEntry e , Queue *pq) {
    QueueNode *pn = (QueueNode *)malloc(sizeof(QueueNode));
    if(!pq->rear) {
        pq->front = pn;
    }
    else {
        pq->rear->next = pn;
        pq->rear = pn;
        pq->size++;
    }
}

void dequeue(QueueEntry *pe ,Queue *pq) {
    QueueNode *pn;
    *pe = pq->front->entry;
    pq->front = pn->next; 
    free(pn);
    if(!pq->front) {
        pq->rear = NULL;
    }
    pq->size--;
}

