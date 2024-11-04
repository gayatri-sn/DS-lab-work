#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the structure for a tree node
struct Node {
    char value;
    struct Node *left, *right;
};

// Function to create a new tree node
struct Node* newNode(char value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

// Stack structure for nodes
struct Stack {
    int top;
    int capacity;
    struct Node** array;
};

// Function to create a stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (struct Node**)malloc(stack->capacity * sizeof(struct Node*));
    return stack;
}

// Stack utility functions
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, struct Node* node) {
    stack->array[++stack->top] = node;
}

struct Node* pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

// Function to create an expression tree from a postfix expression
struct Node* constructTree(char postfix[]) {
    struct Stack* stack = createStack(strlen(postfix));
    struct Node *t, *t1, *t2;

    // Iterate over each character in the postfix expression
    for (int i = 0; postfix[i] != '\0'; i++) {
        // If the character is an operand, create a new node and push it to the stack
        if (isdigit(postfix[i])) {
            t = newNode(postfix[i]);
            push(stack, t);
        }
        // If the character is an operator, pop two nodes and create a new node
        else {
            t = newNode(postfix[i]);

            // Pop two nodes from the stack
            t1 = pop(stack);
            t2 = pop(stack);

            // Make them children of the new node
            t->right = t1;
            t->left = t2;

            // Push the new node back to the stack
            push(stack, t);
        }
    }

    // The remaining node in the stack is the root of the expression tree
    t = pop(stack);
    free(stack);
    return t;
}

// Function to evaluate the expression tree
int evaluate(struct Node* root) {
    // Base case: If it's a leaf node (operand), return its integer value
    if (root->left == NULL && root->right == NULL)
        return root->value - '0';

    // Evaluate the left and right subtrees
    int leftEval = evaluate(root->left);
    int rightEval = evaluate(root->right);

    // Apply the operator at the root to the evaluated left and right subtrees
    switch (root->value) {
        case '+': return leftEval + rightEval;
        case '-': return leftEval - rightEval;
        case '*': return leftEval * rightEval;
        case '/': return leftEval / rightEval;
    }
    return 0;
}

// Function for in-order traversal of the expression tree (for debugging)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->value);
        inorder(root->right);
    }
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression (single-digit operands only): ");
    scanf("%s", postfix);

    struct Node* root = constructTree(postfix);

    printf("In-order traversal of the expression tree: ");
    inorder(root);
    printf("\n");

    int result = evaluate(root);
    printf("The result of the expression is: %d\n", result);

    return 0;
}
