#include <stdio.h>
#include "list.h"

void insertFront_user(List *pl, ListEntry e) {
    insertFront(pl, e);
}

void insertBack_user(List *pl, ListEntry e) {
    insertBack(pl, e);
}

void destroyList_user(List *pl) {
    ListEntry e;
    while (!listEmpty(pl)) {
        e = getFront(pl);        
        deleteElement(pl, e);    
    }
}

int isPresent_user(List *pl, ListEntry e) {
    if (!deleteElement(pl, e))  
        return 0;

    insertFront(pl, e);          
    printf("[Cache Hit: Element %d moved to front]\n", e);
    return 1;
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


int getSize_user(List *pl) {
    int count = 0;
    List temp;
    createList(&temp);
    ListEntry e;

    while (!listEmpty(pl)) {
        e = getFront(pl);          
        deleteElement(pl, e);      
        insertBack(&temp, e);      
        count++;
    }

    while (!listEmpty(&temp)) {
        e = getFront(&temp);       
        deleteElement(&temp, e);   
        insertBack(pl, e);        
    }

    return count;
}

int main() {
    List myList;
    createList(&myList);

    insertBack_user(&myList, 10);
    insertBack_user(&myList, 20);
    insertBack_user(&myList, 30);
    insertBack_user(&myList, 40);
    insertBack_user(&myList, 50);

    printList_user(&myList);
    printf("Size: %d\n", getSize_user(&myList));

    isPresent_user(&myList, 30);
    printList_user(&myList);
    isPresent_user(&myList, 20);
    printList_user(&myList);

    destroyList_user(&myList);
    printList_user(&myList);

    return 0;
}
