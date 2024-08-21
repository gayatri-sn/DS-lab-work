#include<stdio.h>
#define max 3

int queue[max];
int front = -1,rear = -1;

void enqueue(int ele){
    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[rear] = ele;
    }
    else if((rear + 1)% max == front){
        printf("Queue Overflow!!\n");
        return;
    }
    else{
        rear = (rear + 1)% max;
        queue[rear] = ele;
    }
}

int dequeue(){
    if (front == -1 && rear == -1){
        printf("Queue Underflow!!\n");
    }
    else if(front == rear){
        printf("Dequeued element = %d\n",queue[front]);
        front = -1;
        rear = -1;
    }
    else{
        printf("Dequeued element = %d\n",queue[front]);
        front = (front +1)%max;
    }
}

void display(){
    int i = front -1;
    if(front == -1 && rear == -1)
        printf("Queue is empty!!\n");
    else{
        printf("Elements are: \n");
        do{
            i = (i+1)%max;
            printf("%d\n",queue[i]);
        }while(i!=rear);
    }
}

int main(){
    int choice,x;
    printf("1 to Insert an element to Queue.\n");
    printf("2 to Delete an element from Queue.\n");
    printf("3 to Display elements in Queue.\n");
    printf("4 to Exit.\n");
    do{
    printf("Enter choice: ");
    scanf("%d",&choice);

    switch(choice){

    case 1:
        printf("Enter element to enqueue: ");
        scanf("%d",&x);
        enqueue(x);
        break;

    case 2:
        dequeue();
        break;

    case 3:
        display();
        break;

    case 4:
        printf("Exiting the program");
        return 0;

    default:
        printf("Invalid choice!\n");

    }}while(choice != 4);

    return 0;
}
