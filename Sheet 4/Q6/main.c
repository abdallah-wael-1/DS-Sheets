#include <stdio.h>
#include "list.h"
#include <stdlib.h>

void push_back(List *pl, ListEntry e) {
    push_back_impl(pl, e);  
}
void JoinList(List1 *pl1, List1 *pl2)
{
    List1 temp;
    createList(&temp);
    type e;
    int s=listSize(pl2);
    while(!isEmptyList(pl1))
  {

    deleteList(pl1,0,&e);
    insertList(&temp,0,e);

}
while(!isEmptyList(&temp))
  {

    deleteList(&temp,0,&e);
    insertList(pl2,s,e);
    insertList(pl1,0,e);

}

}

void printEntry(ListEntry e) {
    printf("%d ", e);
}


void printList_user(List *pl) {
    if (listEmpty(pl)) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    traverseList(pl, printEntry);
    printf("\n");
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


