#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>


typedef int QueueEntry;

typedef struct QueueNode {
    QueueEntry entry;
    struct QueueNode *next;
} QueueNode;


typedef struct {
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

void createQueue(Queue *pq);                           
int queueIsEmpty(Queue *pq); 
int void queueIsFull(Queue *pq);                     
int appendQueue(QueueEntry e, Queue *pq);      
int serveQueue(QueueEntry *pe, Queue *pq);      
