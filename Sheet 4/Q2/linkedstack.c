#include "stack.h"
// For Free functions and malloc
#include <stdlib.h>
#include <stdio.h>

void createStack(Stack *ps) {
    ps->head = NULL;
}

int isStackEmpty(Stack ps) {
    return ps.head == NULL;
}

int isStackFull(Stack ps) {
    return 0 ;
}

void push(Type item , Stack *l) {

    Node *p = (Node *)malloc(sizeof(Node));
    p->info = item;

    p->next = ps->head;
    ps->head = p;
}

Type pop(Stack *ps) {
        if (isStackEmpty(*ps)) {
        printf("List is empty.\n");
        return -1; 
    }

    Node *tmp, *q;
    Type item;

        tmp = ps->head;
        item = tmp->info;
        ps->head = tmp->next;
        free(tmp);  
        return item;
    }


Type peek(Stack ps) {
    return ps.head->info;    
}
