#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

void displayMenu() {
    printf("\n=== CPU Priority Scheduling System ===\n");
    printf("1. Add a New Process\n");
    printf("2. Serve a Process\n");
    printf("3. Display Information about Waiting Processes\n");
    printf("4. Number of Waiting Processes\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    PriorityQueue* queue = createPriorityQueue();
    int choice, processId, priority;

    printf("Welcome to CPU Priority Scheduling System!\n");
    printf("Note: Lower priority values indicate higher priority\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Process ID: ");
                scanf("%d", &processId);
                printf("Enter Priority (lower value = higher priority): ");
                scanf("%d", &priority);
                addProcess(queue, processId, priority);
                break;

            case 2: {
                Process* served = serveProcess(queue);
                if (served != NULL) {
                    printf("Process P%d with priority %d has been served and removed from queue.\n", served->processId, served->priority);
                    free(served);
                }
                break;
            }
            case 3:
                displayWaitingProcesses(queue);  
                printf("Number of waiting processes: %d\n", getNumberOfWaitingProcesses(queue));
                break;

            case 4:
                printf("Number of waiting processes: %d\n", getNumberOfWaitingProcesses(queue));
                break;

            case 5:
                printf("Thank you for using CPU Priority Scheduling System!\n");
                freePriorityQueue(queue);
                return 0;

            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
        getchar();
        clearScreen();
    }

    return 0;
}
