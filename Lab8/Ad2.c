#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int digit;        
    struct Node* next;   
    struct Node* prev;    
};

struct Node* createNode(int digit) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->digit = digit;
    newNode->next = newNode->prev = NULL;
    return newNode;
}


void insertAtHead(struct Node** head, int digit) {
    struct Node* newNode = createNode(digit);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(struct Node** head, int digit) {
    struct Node* newNode = createNode(digit);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void reverseList(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
}


void displayNumber(struct Node* head) {
    if (head == NULL) {
        printf("0");
    } else {
        while (head != NULL) {
            printf("%d", head->digit);
            head = head->next;
        }
    }
    printf("\n");
}

struct Node* addTwoNumbers(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;
    int carry = 0;

    while (num1 != NULL || num2 != NULL) {
        int sum = carry;

        if (num1 != NULL) {
            sum += num1->digit;
            num1 = num1->next;
        }
        if (num2 != NULL) {
            sum += num2->digit;
            num2 = num2->next;
        }

        carry = sum / 10; 
        sum = sum % 10;   

        insertAtEnd(&result, sum);
    }

    if (carry > 0) {
        insertAtEnd(&result, carry);
    }

    return result;
}

struct Node* readNumber() {
    char numStr[1000];
    struct Node* numList = NULL;

    printf("Enter a long integer: ");
    scanf("%s", numStr);

    int len = strlen(numStr);
    for (int i = len - 1; i >= 0; i--) {
        insertAtEnd(&numList, numStr[i] - '0');
    }

    return numList;
}

int main() {
    struct Node* num1 = NULL;
    struct Node* num2 = NULL;
    struct Node* result = NULL;

    printf("Input for Number 1:\n");
    num1 = readNumber();

    printf("Input for Number 2:\n");
    num2 = readNumber();

    result = addTwoNumbers(num1, num2);

    reverseList(&result);

    printf("Result of addition: ");
    displayNumber(result);

    return 0;
}
