#ifndef LIST_H
#define LIST_H

typedef int ListEntry;

typedef struct Node {
    ListEntry data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} List;


void createList(List *pl);
int listEmpty(List *pl);
int ListFull(List l); 
void insertFront(List *pl, ListEntry e);
void insertBack(List *pl, ListEntry e);
int deleteElement(List *pl, ListEntry e);
void traverseList(List *pl, void (*visit)(ListEntry));
void destroyList(List *pl);
ListEntry getFront(List *pl);

#endif