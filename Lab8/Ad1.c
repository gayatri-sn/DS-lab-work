#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}


void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}


void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int isPresent(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data)
            return 1;
        temp = temp->next;
    }
    return 0;
}

struct Node* getUnion(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;

    struct Node* temp = list1;
    while (temp != NULL) {
        if (!isPresent(result, temp->data)) {
            insertAtEnd(&result, temp->data);
        }
        temp = temp->next;
    }

    temp = list2;
    while (temp != NULL) {
        if (!isPresent(result, temp->data)) {
            insertAtEnd(&result, temp->data);
        }
        temp = temp->next;
    }

    return result;
}

struct Node* getIntersection(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;

    struct Node* temp = list1;
    while (temp != NULL) {
        if (isPresent(list2, temp->data) && !isPresent(result, temp->data)) {
            insertAtEnd(&result, temp->data);
        }
        temp = temp->next;
    }

    return result;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n, m, value;

    printf("Enter number of elements in the first list: ");
    scanf("%d", &n);
    printf("Enter elements of the first list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtEnd(&list1, value);
    }

    printf("Enter number of elements in the second list: ");
    scanf("%d", &m);
    printf("Enter elements of the second list:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        insertAtEnd(&list2, value);
    }

    printf("List 1: ");
    displayList(list1);
    printf("List 2: ");
    displayList(list2);

    struct Node* unionList = getUnion(list1, list2);
    printf("Union of the two lists: ");
    displayList(unionList);

    struct Node* intersectionList = getIntersection(list1, list2);
    printf("Intersection of the two lists: ");
    displayList(intersectionList);

    return 0;
}
