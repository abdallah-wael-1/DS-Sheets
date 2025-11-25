#include "list.h"
#include <stdlib.h>
#include <stdio.h>


void createList(List *pl) {
    pl->head = NULL;
    pl->tail = NULL;
    pl->size = 0;
}

int listEmpty(List *pl) {
    return pl->head == NULL;
}

int ListFull(List l) {
    return 0;
}

void insertFront(List *pl, ListEntry e) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    newNode->data = e;
    newNode->next = pl->head;
    pl->head = newNode;
    
    if (pl->tail == NULL) {  
        pl->tail = newNode;
    }
    
    pl->size++;
}


void insertBack(List *pl, ListEntry e) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    newNode->data = e;
    newNode->next = NULL;
    
    if (pl->head == NULL) { 
        pl->head = pl->tail = newNode;
    } else {
        pl->tail->next = newNode;
        pl->tail = newNode;
    }
    
    pl->size++;
}

int deleteElement(List *pl, ListEntry e) {
    if (pl->head == NULL) {
        return 0; 
    }
    
    Node *current = pl->head;
    Node *previous = NULL;
    
    while (current != NULL && current->data != e) {
        previous = current;
        current = current->next;
    }
    
    if (current == NULL) {
        return 0;  
    }
    
    if (previous == NULL) {  
        pl->head = current->next;
        if (pl->head == NULL) {  
            pl->tail = NULL;
        }
    } else {
        previous->next = current->next;
        if (current == pl->tail) {  
            pl->tail = previous;
        }
    }
    
    free(current);
    pl->size--;
    return 1;  
}


void traverseList(List *pl, void (*visit)(ListEntry)) {
    Node *current = pl->head;
    while (current != NULL) {
        visit(current->data);
        current = current->next;
    }
}


void destroyList(List *pl) {
    Node *current = pl->head;
    Node *temp;
    
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    
    pl->head = NULL;
    pl->tail = NULL;
    pl->size = 0;
}

ListEntry getFront(List *pl) {
    if (pl->head == NULL) {
        printf("Error: List is empty!\n");
        return -1;
    }
    return pl->head->data;
}