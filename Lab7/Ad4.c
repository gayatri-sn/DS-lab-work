#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto the stack\n", data);
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    int poppedData = temp->data;
    free(temp);
    return poppedData;
}

void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Queue Overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    
    if (*rear == NULL) {
        *front = *rear = newNode;
        printf("Enqueued %d into the queue\n", data);
        return;
    }
    
    (*rear)->next = newNode;
    *rear = newNode;
    printf("Enqueued %d into the queue\n", data);
}

int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue Underflow\n");
        return -1;
    }
    struct Node* temp = *front;
    *front = (*front)->next;
    int dequeuedData = temp->data;
    free(temp);
    
    if (*front == NULL) {
        *rear = NULL;
    }
    
    return dequeuedData;
}

void displayQueue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    struct Node* stackTop = NULL; 
    struct Node* queueFront = NULL; 
    struct Node* queueRear = NULL;  

    int choice, data;

        printf("\nMenu:\n");
        printf("1. Push onto Stack\n");
        printf("2. Pop from Stack\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue into Queue\n");
        printf("5. Dequeue from Queue\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        
        while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&stackTop, data);
                break;
            case 2:
                data = pop(&stackTop);
                if (data != -1) {
                    printf("Popped %d from the stack\n", data);
                }
                break;
            case 3:
                displayStack(stackTop);
                break;
            case 4:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&queueFront, &queueRear, data);
                break;
            case 5:
                data = dequeue(&queueFront, &queueRear);
                if (data != -1) {
                    printf("Dequeued %d from the queue\n", data);
                }
                break;
            case 6:
                displayQueue(queueFront);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
