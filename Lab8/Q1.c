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
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertAtRear(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* tail = *head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->prev = tail;
    }
    printf("Inserted %d at the rear.\n", data);
}

void deleteFromRear(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* tail = *head;
    if (tail->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->prev->next = NULL;
        free(tail);
    }
    printf("Deleted element from rear.\n");
}

void insertAtPosition(struct Node** head, int data, int pos) {
    struct Node* newNode = createNode(data);
    if (*head == NULL && pos == 1) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        for (int i = 1; temp != NULL && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL && pos != 1) {
            printf("Invalid position!\n");
            free(newNode);
            return;
        }
        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at position %d.\n", data, pos);
}

void deleteFromPosition(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (pos == 1) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
    } else {
        for (int i = 1; temp != NULL && i < pos; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position!\n");
            return;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
    printf("Deleted element from position %d.\n", pos);
}

void insertAfter(struct Node** head, int target, int data) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found!\n", target);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d after %d.\n", data, target);
}

void insertBefore(struct Node** head, int target, int data) {
    struct Node* temp = *head;
    if (temp != NULL && temp->data == target) {
        insertAtPosition(head, data, 1);
        return;
    }
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found!\n", target);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev->next = newNode;
    temp->prev = newNode;
    printf("Inserted %d before %d.\n", data, target);
}

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseList(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = NULL, *current = *head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
    printf("Reversed the list.\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, pos, target;

    printf("\n1. Insert at rear\n2. Delete from rear\n3. Insert at position\n4. Delete from position\n");
    printf("5. Insert after element\n6. Insert before element\n7. Traverse\n8. Reverse list\n9. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at rear: ");
                scanf("%d", &data);
                insertAtRear(&head, data);
                break;
            case 2:
                deleteFromRear(&head);
                break;
            case 3:
                printf("Enter data and position to insert: ");
                scanf("%d%d", &data, &pos);
                insertAtPosition(&head, data, pos);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteFromPosition(&head, pos);
                break;
            case 5:
                printf("Enter element after which to insert and data: ");
                scanf("%d%d", &target, &data);
                insertAfter(&head, target, data);
                break;
            case 6:
                printf("Enter element before which to insert and data: ");
                scanf("%d%d", &target, &data);
                insertBefore(&head, target, data);
                break;
            case 7:
                traverse(head);
                break;
            case 8:
                reverseList(&head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

