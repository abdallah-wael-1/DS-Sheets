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

void push_back_impl(List *pl, ListEntry e);


#endif