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

// Function to find the height of the tree
int height(struct Node* node) {
    if (node == NULL)
        return 0;
    else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // Return the larger of the two heights plus 1
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

// Function to print nodes at a given level
void printGivenLevel(struct Node* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->key);
    else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

// Function to perform level order traversal
void levelOrder(struct Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, i);
        printf("\n"); // Print each level on a new line (optional)
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

    // Perform and print level order traversal
    printf("\nLevel order traversal of the BST:\n");
    levelOrder(root);

    return 0;
}
