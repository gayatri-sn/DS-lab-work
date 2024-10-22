#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {

    if (n == 0)
        return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter data for node: ");
    scanf("%d", &(newNode->data));

    newNode->next = createList(n - 1);
    
    return newNode;
}

void traverseList(struct Node* head) {

    if (head == NULL)
        return;

    printf("%d -> ", head->data);

    traverseList(head->next);
}

int main() {
    int n;
    struct Node* head = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("The linked list is: ");
    traverseList(head);
    printf("NULL\n");

    return 0;
}
