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
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Return the unchanged node pointer
    return node;
}

// Function to search a given key in a BST
struct Node* search(struct Node* root, int key) {
    // Base case: root is NULL or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

int main() {
    struct Node* root = NULL;
    int n, key, searchKey;

    printf("Enter the number of elements to insert into the BST: ");
    scanf("%d", &n);

    // Insert elements into the BST
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &key);
        root = insert(root, key);
    }

    // Ask the user for the element to search
    printf("Enter the element to search in the BST: ");
    scanf("%d", &searchKey);

    // Search for the element
    struct Node* result = search(root, searchKey);
    if (result != NULL)
        printf("Element %d found in the BST.\n", searchKey);
    else
        printf("Element %d not found in the BST.\n", searchKey);

    return 0;
}
