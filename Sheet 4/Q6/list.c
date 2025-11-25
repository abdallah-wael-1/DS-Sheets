#include "list.h"
#include <stdlib.h>

void createList(List *pl) {
    pl->head = NULL;
    pl->size = 0;
}

int isEmptyList(List *pl) {
    return pl->size == 0;
}

int listSize(List *pl) {
    return pl->size;
}


void insertList(List *pl, int pos, ListEntry e) {
    if (pos < 0 || pos > pl->size) return; 

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = e;
    newNode->next = NULL;

    if (pos == 0) { 
        newNode->next = pl->head;
        pl->head = newNode;
    } else {
        Node *cur = pl->head;
        for (int i = 0; i < pos - 1; i++) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }

    pl->size++;
}


void deleteList(List *pl, int pos, ListEntry *e) {
    if (pos < 0 || pos >= pl->size || pl->head == NULL) 
        listSizereturn; 

    Node *toDelete;
    if (pos == 0) { 
        toDelete = pl->head;
        pl->head = pl->head->next;
    } else {
        Node *cur = pl->head;
        for (int i = 0; i < pos - 1; i++) {
            cur = cur->next;
        }
        toDelete = cur->next;
        cur->next = toDelete->next;
    }

    *e = toDelete->data; 
    free(toDelete);
    pl->size--;
}


void push_back_impl(List *pl, ListEntry e) {
    Node *newNode = (Node*)malloc(sizeof(Node));
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

void JoinList(List *pl1, List *pl2) {
    Node *cur = pl1->head;
    while (cur != NULL) {
        push_back(pl2, cur->data); 
        cur = cur->next;
    }
}

void printList(List l) {
    Node *cur = l.head;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void traverseList(List *pl, void (*visit)(ListEntry)) {
    Node *current = pl->head;
    while (current != NULL) {
        visit(current->data);
        current = current->next;
    }
}

