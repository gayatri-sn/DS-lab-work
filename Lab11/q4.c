#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new BST node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a key into the BST
struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

// In-order traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Pre-order traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

int main() {
    struct Node* root = NULL;
    int n, key;

    printf("Enter the number of elements to insert into the BST: ");
    scanf("%d", &n);

    // Insert elements into the BST
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &key);
        root = insert(root, key);
    }

    // Perform and print in-order traversal
    printf("\nIn-order traversal of the BST: ");
    inorder(root);
    printf("\n");

    // Perform and print pre-order traversal
    printf("Pre-order traversal of the BST: ");
    preorder(root);
    printf("\n");

    // Perform and print post-order traversal
    printf("Post-order traversal of the BST: ");
    postorder(root);
    printf("\n");

    return 0;
}

