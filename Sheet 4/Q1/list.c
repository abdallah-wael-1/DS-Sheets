#include <stdio.h>
#include "list.h"

void createList(list *l) {
    l->n = 0;
}

int listIsEmpty(list l) {
    return l.n == 0;
}

int listIsFull(list l) {
    return l.n == MAX;
}

Type insertInList(Type item, list *l) {
    if (listIsFull(*l)) {
        printf("List is full. Cannot add %d\n", item);
        return -1;
    }
    l->items[l->n] = item;
    l->n++;
    return 0;
}

Type removeFromList(list *l) {
    if (listIsEmpty(*l)) {
        printf("List is empty. Cannot remove item.\n");
        return -1;
    }
    Type item = l->items[l->n - 1];
    l->n--;
    return item;
}

int insertAtPosition(Type item, int position, list *l) {
    if (listIsFull(*l)) {
        printf("List is full. Cannot insert %d\n", item);
        return 0;
    }

    if (position < 0 || position > l->n) {
        printf("Invalid position.\n");
        return 0;
    }


    for (int i = l->n; i > position; i--) {
        l->items[i] = l->items[i - 1];
    }

    l->items[position] = item;
    l->n++;
    return 1; 
}
