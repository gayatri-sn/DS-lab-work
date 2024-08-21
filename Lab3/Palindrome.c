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

void push(char item, struct Stack *stack)
{
    if(Full(stack)){
        printf("Stack overflow, cannot push %d\n",item);
        return;
    }
    stack -> top++;
    stack->items[stack->top]=item;
}
char pop(struct Stack *stack)
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

    char str[20];
    printf("Enter a word:\n");
    gets(str);

    int flag = 1,i,j;

    int len = strlen(str);

    for(i=0;i<len;i++){
        push(str[i],&stack);
    }

    for(j=0;j<len;j++){
        if(pop(&stack)!= str[j])
            flag = 0;
    }

    if(flag == 1){
        printf("%s is a palindrome.",str);
    }
    else {
        printf("%s is not a palindrome.",str);
    }
    return 0;

}
