#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createList(struct Node* head) {
    int n, data;
    struct Node* temp;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    if (n == 0) return head;
    
    printf("Enter the data for node 1: ");
    scanf("%d", &data);
    head = createNode(data);
    temp = head;
    
    for (int i = 2; i <= n; i++) {
        printf("Enter the data for node %d: ", i);
        scanf("%d", &data);
        temp->next = createNode(data);
        temp = temp->next;
    }
    
    return head;
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* insertBefore(struct Node* head, int value, int before) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }
    
    if (head->data == before) {
        newNode->next = head;
        return newNode;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != before) {
        temp = temp->next;
    }
    
    if (temp->next == NULL) {
        printf("Element %d not found in the list.\n", before);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    return head;
}

struct Node* insertAfter(struct Node* head, int value, int after) {
    struct Node* newNode = createNode(value);
    struct Node* temp = head;
    
    while (temp != NULL && temp->data != after) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", after);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    return head;
}

struct Node* deleteElement(struct Node* head, int value) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    
    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }
    
    if (head->data == value) {
        temp = head->next;
        free(head);
        return temp;
    }
    
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", value);
    } else {
        prev->next = temp->next;
        free(temp);
    }
    
    return head;
}

struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

struct Node* sortList(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* current = head;
    struct Node* index = NULL;
    int temp;
    
    while (current != NULL) {
        index = current->next;
        
        while (index != NULL) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
    
    return head;
}

struct Node* deleteAlternate(struct Node* head) {
    if (head == NULL)
        return head;
    
    struct Node* current = head;
    struct Node* temp = NULL;
    
    while (current != NULL && current->next != NULL) {
        temp = current->next;
        current->next = current->next->next;
        free(temp);
        current = current->next;
    }
    
    return head;
}

struct Node* insertInSortedList(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    struct Node* temp = head;
    
    if (head == NULL || head->data >= value) {
        newNode->next = head;
        return newNode;
    }
    
    while (temp->next != NULL && temp->next->data < value) {
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    
    return head;
}

int main() {
    struct Node* head = NULL;
    int choice, value, element;
    
        printf("\nMenu:\n");
        printf("1. Create List\n2. Insert Before an Element\n3. Insert After an Element\n4. Delete an Element\n5. Traverse the List\n6. Reverse the List\n7. Sort the List\n8. Delete Every Alternate Node\n9. Insert in Sorted List\n10. Exit\n");
        while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                head = createList(head);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the element before which to insert: ");
                scanf("%d", &element);
                head = insertBefore(head, value, element);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the element after which to insert: ");
                scanf("%d", &element);
                head = insertAfter(head, value, element);
                break;
            case 4:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                head = deleteElement(head, value);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                head = reverseList(head);
                printf("The list has been reversed.\n");
                break;
            case 7:
                head = sortList(head);
                printf("The list has been sorted.\n");
                break;
            case 8:
                head = deleteAlternate(head);
                printf("Every alternate node has been deleted.\n");
                break;
            case 9:
                printf("Enter the value to insert in sorted list: ");
                scanf("%d", &value);
                head = insertInSortedList(head, value);
                break;
            case 10:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
