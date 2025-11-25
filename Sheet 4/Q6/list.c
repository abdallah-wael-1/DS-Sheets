#include "list.h"
#include <stdlib.h>

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