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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert_at_rear(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void delete_from_rear(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->prev->next = NULL;
        free(temp);
    }
}

void insert_at_position(struct Node** head, int data, int pos) {
    struct Node* newNode = createNode(data);
    if (pos == 1) { 
        newNode->next = *head;
        if (*head != NULL)
            (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void delete_at_position(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (pos == 1) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return;
    }
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    free(temp);
}

void insert_after(struct Node** head, int after, int data) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != after)
        temp = temp->next;
    if (temp == NULL) {
        printf("Element %d not found.\n", after);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void insert_before(struct Node** head, int before, int data) {
    struct Node* temp = *head;
    if (temp != NULL && temp->data == before) {
        insert_at_position(head, data, 1);
        return;
    }
    while (temp != NULL && temp->data != before)
        temp = temp->next;
    if (temp == NULL) {
        printf("Element %d not found.\n", before);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = newNode;
    temp->prev = newNode;
}

void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse_list(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        *head = temp->prev;
}

int main() {
    struct Node* head = NULL;
    int choice, data, pos, element;

    while (1) {
        printf("\n1. Insert at rear\n2. Delete from rear\n3. Insert at position\n4. Delete from position\n");
        printf("5. Insert after element\n6. Insert before element\n7. Traverse list\n8. Reverse list\n9. Exit\n");
        while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at rear: ");
                scanf("%d", &data);
                insert_at_rear(&head, data);
                break;
            case 2:
                delete_from_rear(&head);
                break;
            case 3:
                printf("Enter position and data to insert: ");
                scanf("%d%d", &pos, &data);
                insert_at_position(&head, data, pos);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete_at_position(&head, pos);
                break;
            case 5:
                printf("Enter element after which to insert and data: ");
                scanf("%d%d", &element, &data);
                insert_after(&head, element, data);
                break;
            case 6:
                printf("Enter element before which to insert and data: ");
                scanf("%d%d", &element, &data);
                insert_before(&head, element, data);
                break;
            case 7:
                traverse(head);
                break;
            case 8:
                reverse_list(&head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    }

    return 0;
}
