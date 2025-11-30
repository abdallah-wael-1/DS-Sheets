#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

PriorityQueue* createPriorityQueue() {
    PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    if (queue == NULL) exit(1);
    queue->front = NULL;
    queue->size = 0;
    return queue;
}

void addProcess(PriorityQueue* queue, int processId, int priority) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    if (newProcess == NULL) return;
    newProcess->processId = processId;
    newProcess->priority = priority;
    newProcess->next = NULL;

    if (queue->front == NULL || priority < queue->front->priority) {
        newProcess->next = queue->front;
        queue->front = newProcess;
    } else {
        Process* current = queue->front;
        Process* prev = NULL;
        while (current != NULL && current->priority <= priority) {
            prev = current;
            current = current->next;
        }
        newProcess->next = current;
        prev->next = newProcess;
    }
    queue->size++;
    printf("Process P%d with priority %d added successfully!\n", processId, priority);
}

Process* serveProcess(PriorityQueue* queue) {
    if (queue->front == NULL) {
        printf("No processes waiting!\n");
        return NULL;
    }
    Process* servedProcess = queue->front;
    queue->front = queue->front->next;
    queue->size--;
    printf("Serving Process P%d with priority %d\n", servedProcess->processId, servedProcess->priority);
    return servedProcess;
}

void displayWaitingProcesses(PriorityQueue* queue) {
    if (queue->front == NULL) {
        printf("No processes waiting!\n");
        return;
    }
    printf("\n=== Waiting Processes Information ===\n");
    printf("%-15s %-15s %-15s\n", "Position", "Process ID", "Priority");
    printf("----------------------------------------\n");
    Process* current = queue->front;
    int position = 1;
    while (current != NULL) {
        printf("%-15d P%-14d %-15d\n", position, current->processId, current->priority);
        current = current->next;
        position++;
    }
    printf("========================================\n");
}

int getNumberOfWaitingProcesses(PriorityQueue* queue) {
    return queue->size;
}

void freePriorityQueue(PriorityQueue* queue) {
    Process* current = queue->front;
    while (current != NULL) {
        Process* temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
}
