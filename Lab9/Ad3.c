#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char name[50];   
    int rentDuration;   
    struct User* next;   
    struct User* prev;  
};

struct User* createUser(char name[], int rentDuration) {
    struct User* newUser = (struct User*)malloc(sizeof(struct User));
    strcpy(newUser->name, name);
    newUser->rentDuration = rentDuration;
    newUser->next = newUser->prev = NULL;
    return newUser;
}

void insertUser(struct User* header, char name[], int rentDuration) {
    struct User* newUser = createUser(name, rentDuration);
    struct User* temp = header->prev;

    newUser->next = header;
    newUser->prev = temp;
    temp->next = newUser;
    header->prev = newUser;
}

void processQueue(struct User* header) {
    struct User* current = header->next;

    while (current != header) {
        printf("%s is using the washing machine for %d minutes.\n", current->name, current->rentDuration);

        current = current->next;
    }
    printf("All users have used the washing machine.\n");
}

struct User* initializeHeader() {
    struct User* header = createUser("Header", 0);
    header->next = header->prev = header; 
    return header;
}

int main() {
    struct User* header = initializeHeader();
    int choice;

    do {
        printf("\nWashing Machine Renting System\n");
        printf("1. Book washing machine\n");
        printf("2. Start processing the queue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50];
                int duration;
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter the duration (in minutes) you want to book: ");
                scanf("%d", &duration);
                insertUser(header, name, duration);
                break;
            }
            case 2:
                processQueue(header);
                break;
            case 3:
                printf("Exiting system...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
