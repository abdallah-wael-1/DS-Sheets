#ifndef LIST_H
#define LIST_H

#define MAX 100

typedef int Type;

typedef struct {
    int n;
    Type items[MAX];
} list;

void createList(list *l);
int listIsEmpty(list l);    
int listIsFull(list l);
Type insertInList(Type item, list *l);
Type removeFromList(list *l);
int insertAtPosition(Type item, int position, list *l);

#endif