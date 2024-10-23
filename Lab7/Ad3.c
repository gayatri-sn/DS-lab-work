#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

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

struct Node* mergeAlternating(struct Node* list1, struct Node* list2) {
    struct Node* list3 = NULL;
    struct Node** lastPtrRef = &list3; 

    while (list1 != NULL && list2 != NULL) {
        *lastPtrRef = list1;
        list1 = list1->next;
        lastPtrRef = &((*lastPtrRef)->next);

      
        *lastPtrRef = list2;
        list2 = list2->next;
        lastPtrRef = &((*lastPtrRef)->next);
    }

    
    if (list1 != NULL) {
        *lastPtrRef = list1;
    }


    if (list2 != NULL) {
        *lastPtrRef = list2;
    }

    return list3;
}


void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

  
    list1 = insertNode(list1, 1);
    list1 = insertNode(list1, 2);
    list1 = insertNode(list1, 3);

  
    list2 = insertNode(list2, 10);
    list2 = insertNode(list2, 20);
    list2 = insertNode(list2, 30);
    list2 = insertNode(list2, 40);

    printf("List1: ");
    printList(list1);

    printf("List2: ");
    printList(list2);

    
    struct Node* list3 = mergeAlternating(list1, list2);

    printf("Merged List3: ");
    printList(list3);

    return 0;
}
