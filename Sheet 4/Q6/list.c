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
