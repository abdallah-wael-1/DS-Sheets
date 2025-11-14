#include <stdio.h>
#include "queue.h"

int main() {
    Queue sectionQueue, groupQueue, mergedQueue;
    createQueue(&sectionQueue);
    createQueue(&groupQueue);
    createQueue(&mergedQueue);

    append(12, &sectionQueue);
    append(15, &sectionQueue);
    append(22, &sectionQueue);

    append(3, &groupQueue);
    append(7, &groupQueue);
    append(1, &groupQueue);

    while (!queueEmpty(&sectionQueue) && !queueEmpty(&groupQueue)) {
        int sec, grp;
        serve(&sec, &sectionQueue);
        serve(&grp, &groupQueue);

        int merged = sec * 10 + grp;
        append(merged, &mergedQueue);
    }

    printf("Merged Queue: ");
    while (!queueEmpty(&mergedQueue)) {
        int x;
        serve(&x, &mergedQueue);
        printf("%d ", x);
    }

    return 0;
}
