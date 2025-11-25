#include <stdio.h>
#include "list.h"
#include <stdlib.h>


void push_back(List *pl, ListEntry e) {
    push_back_impl(pl, e);  
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

int main() {
    List l1 = {NULL, NULL, 0};
    List l2 = {NULL, NULL, 0};

    push_back(&l1, 1);
    push_back(&l1, 2);
    push_back(&l1, 3);

    push_back(&l2, 10);
    push_back(&l2, 20);

    printf("List 1 before join:\n");
    printList(l1);

    printf("List 2 before join:\n");
    printList(l2);

    JoinList(&l1, &l2);

    printf("List 2 after joining List 1:\n");
    printList(l2);

    return 0;
}
