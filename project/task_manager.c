#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100

int main() {
    char tasks[MAX_TASKS][100];
    int taskCount = 0;
    int choice;

    while (1) {
        printf("-----------------------------------\n");
        printf("       TASK MANAGER PROGRAM        \n");
        printf("-----------------------------------\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Last Task\n");
        printf("4. Exit\n");
        printf("Choose: ");

        // FIX: validate scanf
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                if (taskCount < MAX_TASKS) {
                    printf("Enter new task: ");
                    scanf(" %[^\n]", tasks[taskCount]);
                    taskCount++;
                    printf("Task added!\n\n");
                } else {
                    printf("Task list full!\n\n");
                }
                break;

            case 2:
                if (taskCount == 0) {
                    printf("No tasks to show.\n\n");
                } else {
                    printf("\nYour Tasks:\n");
                    for (int i = 0; i < taskCount; i++) {
                        printf("%d. %s\n", i + 1, tasks[i]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                if (taskCount > 0) {
                    taskCount--;
                    printf("Last task deleted!\n\n");
                } else {
                    printf("No tasks to delete.\n\n");
                }
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n\n");
        }
    }

    return 0;
}

