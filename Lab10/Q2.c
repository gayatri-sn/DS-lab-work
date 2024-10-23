#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct Node* createBinaryTree() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct Node* newNode = createNode(data);

    printf("Enter left child of %d:\n", data);
    newNode->left = createBinaryTree();

    printf("Enter right child of %d:\n", data);
    newNode->right = createBinaryTree();

    return newNode;
}


void printBinaryTree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printBinaryTree(root->left);
    printf("%d ", root->data);
    printBinaryTree(root->right);
}


int main() {
    struct Node* root = NULL;

    root = createBinaryTree();

    printf("In-order Traversal of the Binary Tree:\n");
    printBinaryTree(root);

    return 0;
}
