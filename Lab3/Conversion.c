#include<stdio.h>
#include<string.h>
#define max_size 100

struct Stack{
    char items[max_size];
    int top;
};

void initialize(struct Stack *stack){
    stack -> top = -1;
}

int Empty(struct Stack *stack)
{
    return stack -> top == -1;
}

int Full(struct Stack *stack)
{
    return stack->top == max_size -1;
}

void push(int item, struct Stack *stack)
{
    if(Full(stack)){
        printf("Stack overflow, cannot push %d\n",item);
        return;
    }
    stack -> top++;
    stack->items[stack->top]=item;
}
int pop(struct Stack *stack)
{
    if(Empty(stack)){
        printf("Stack underflow,cannot pop\n");
        return -1;
    }
    return stack->items[stack->top--];
}

char peek(struct Stack *stack){
    if (Empty(stack)){
        printf("Stack is empty, cannot peek\n");
        return -1;
        }
    return stack->items[stack->top];
}

int main()
{
    struct Stack stack;
    initialize(&stack);

    int num;
    int base;
    printf("Enter a number:\n");
    scanf("%d",&num);
    printf("Enter base:\n");
    scanf("%d",&base);

int topush=0;
    while(num!=0){
        topush = num%base;
        num = num/base;
        push(topush,&stack);}

printf("It converts to \t");
    while(stack.top!=-1){
            printf("%d",pop(&stack));}

    return 0;

}
