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

// Function to find the minimum value node in a tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    // Loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node with a given key in the BST
struct Node* deleteNode(struct Node* root, int key) {
    // Base case: if the tree is empty
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key, go to the left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key, go to the right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // If the key is the same as the root's key, delete this node
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// In-order traversal to print the BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, key, deleteKey;

    printf("Enter the number of elements to insert into the BST: ");
    scanf("%d", &n);

    // Insert elements into the BST
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &key);
        root = insert(root, key);
    }

    // Print the BST
    printf("In-order traversal of the BST: ");
    inorder(root);
    printf("\n");

    // Delete an element from the BST
    printf("Enter the element to delete from the BST: ");
    scanf("%d", &deleteKey);
    root = deleteNode(root, deleteKey);

    // Print the BST after deletion
    printf("In-order traversal of the BST after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
