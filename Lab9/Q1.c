#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode;
    newNode->next = newNode;
    return newNode;
}
void insert_element(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* tail = (*head)->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    printf("Inserted %d into the list.\n", data);
}

void delete_element(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    do {
        if (temp->data == data) {
            if (temp->next == temp) { 
                *head = NULL;
            } else {
                if (temp == *head) {
                    *head = temp->next;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            free(temp);
            printf("Deleted %d from the list.\n", data);
            return;
        }
        temp = temp->next;
    } while (temp != *head);

    printf("Element %d not found in the list.\n", data);
}

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    printf("\n1. Insert an element\n2. Delete an element\n3. Traverse the list\n4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert_element(&head, data);
                break;
            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                delete_element(&head, data);
                break;
            case 3:
                traverse(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
