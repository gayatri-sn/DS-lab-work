#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}node;
node* x1 = NULL;
node* x2 = NULL;

node* insert(node* first,int val){
    node* cur;
    node* temp = (node*)malloc(sizeof(node));
    temp -> data = val;
    temp -> next = NULL;
    temp -> prev = NULL;

    if(first == NULL){
        first = temp;
    }
    else {
        for(cur = first;cur -> next != NULL ; cur = cur -> next);
        cur -> next = temp;
        temp -> prev = cur;
    }
    return first;
}

void display(node* first){
    if(first == NULL){
        printf("Empty List");
    }
    node* cur;
    for(cur = first; cur != NULL; cur = cur -> next){
        printf("%d\t", cur -> data);
    }
    printf("\n");
}

int main(){
    x1 = insert(x1,10);
    x1 = insert(x1,20);
    x1 = insert(x1,30);
    display(x1);

    x2 = insert(x2,100);
    x2 = insert(x2,200);
    x2 = insert(x2,300);
    display(x2);


    node* cur;
    for(cur = x1;cur -> next != NULL;cur = cur -> next);
    cur -> next = x2;
    x2 -> prev = cur;
    display(x1);
    return 0;
}
