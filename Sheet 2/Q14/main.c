#include <stdio.h>
#include "stack.h"

int main() {
    Stack groupIDStack, sectionStack, groupStack;

    CreateStack(&groupIDStack);
    CreateStack(&sectionStack);
    CreateStack(&groupStack);
    
    Push(123, &groupIDStack);
    Push(157, &groupIDStack);
    Push(221, &groupIDStack);

    while (!StackEmpty(&groupIDStack)) {
        int group_id;
        Pop(&group_id, &groupIDStack);

        int section_code = group_id / 10;
        int group_code   = group_id % 10;

        Push(section_code, &sectionStack);
        Push(group_code, &groupStack);
    }

    printf("Section codes stack: ");
    while (!StackEmpty(&sectionStack)) {
        int x;
        Pop(&x, &sectionStack);
        printf("%d ", x);
    }

    printf("\nGroup codes stack: ");
    while (!StackEmpty(&groupStack)) {
        int x;
        Pop(&x, &groupStack);
        printf("%d ", x);
    }

    return 0;
}
