#include <stdio.h>
#include <stdlib.h>

void addNote() {
    FILE *file = fopen("notes.txt", "a");
    char note[200];

    printf("Enter your note: ");
    scanf(" %[^\n]", note);

    fprintf(file, "%s\n", note);
    fclose(file);

    printf("Note saved!\n\n");
}

void viewNotes() {
    FILE *file = fopen("notes.txt", "r");
    char line[200];

    printf("\n--- Your Notes ---\n");

    if (file == NULL) {
        printf("No notes found.\n\n");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        printf("- %s", line);
    }
    printf("\n");

    fclose(file);
}

void clearNotes() {
    FILE *file = fopen("notes.txt", "w");
    fclose(file);
    printf("All notes cleared!\n\n");
}

int main() {
    int choice;

    while (1) {
        printf("--------------------------\n");
        printf("     NOTES APPLICATION    \n");
        printf("--------------------------\n");
        printf("1. Add Note\n");
        printf("2. View Notes\n");
        printf("3. Clear Notes\n");
        printf("4. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addNote(); break;
            case 2: viewNotes(); break;
            case 3: clearNotes(); break;
            case 4: printf("Goodbye!\n"); exit(0);
            default: printf("Invalid choice!\n\n");
        }
    }

    return 0;
}

