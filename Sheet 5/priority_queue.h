#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

typedef struct Process {
    int processId;
    int priority;
    struct Process* next;
} Process;

typedef struct {
    Process* front;
    int size;
} PriorityQueue;

PriorityQueue* createPriorityQueue();
void addProcess(PriorityQueue* queue, int processId, int priority);
Process* serveProcess(PriorityQueue* queue);
void displayWaitingProcesses(PriorityQueue* queue);
int getNumberOfWaitingProcesses(PriorityQueue* queue);
void freePriorityQueue(PriorityQueue* queue);

#endif
