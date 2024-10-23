#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* mergeSortedLists(struct Node* X, struct Node* Y) {
    if (X == NULL) return Y;
    if (Y == NULL) return X;

    struct Node* mergedList = NULL;


    if (X->data <= Y->data) {
        mergedList = X;  
        mergedList->next = mergeSortedLists(X->next, Y);
    } else {
        mergedList = Y; 
        mergedList->next = mergeSortedLists(X, Y->next);
    }

    return mergedList;
}

struct Node* insertNode(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* X = NULL;
    struct Node* Y = NULL;

  
    X = insertNode(X, 1);
    X = insertNode(X, 3);
    X = insertNode(X, 5);
    Y = insertNode(Y, 2);
    Y = insertNode(Y, 4);
    Y = insertNode(Y, 6);

    printf("List X: ");
    printList(X);

    printf("List Y: ");
    printList(Y);
    struct Node* Z = mergeSortedLists(X, Y);
    printf("Merged List Z: ");
    printList(Z);

    return 0;
}
