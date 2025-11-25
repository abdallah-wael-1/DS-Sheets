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
int isEmptyList(List *pl);                         
int listSize(List *pl);                              
void insertList(List *pl, int pos, ListEntry e);  
void deleteList(List *pl, int pos, ListEntry *e);   
void traverseList(List *pl, void (*visit)(ListEntry)); 
void printList(List l);                              
void JoinList(List *pl1, List *pl2);                
void push_back_impl(List *pl, ListEntry e);     

#endif


