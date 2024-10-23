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
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertLevelOrder(int arr[], struct Node* root, int i, int n) {
    if (i < n) {
        struct Node* temp = createNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

void inOrderTraversal(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
    printf("\n");
}

void postOrderTraversal(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* lastVisited = NULL;
    struct Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top];

        if (current->right == NULL || current->right == lastVisited) {
            printf("%d ", current->data);
            lastVisited = current;
            top--;
            current = NULL;
        } else {
            current = current->right;
        }
    }
    printf("\n");
}

void preOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        struct Node* node = stack[top--];
        printf("%d ", node->data);

        if (node->right != NULL) stack[++top] = node->right;
        if (node->left != NULL) stack[++top] = node->left;
    }
    printf("\n");
}

struct Node* findParent(struct Node* root, int value) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return NULL;

    if ((root->left != NULL && root->left->data == value) ||
        (root->right != NULL && root->right->data == value)) {
        return root;
    }

    struct Node* leftParent = findParent(root->left, value);
    if (leftParent != NULL) return leftParent;

    return findParent(root->right, value);
}

int depth(struct Node* root) {
    if (root == NULL) return 0;
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int printAncestors(struct Node* root, int value) {
    if (root == NULL) return 0;

    if (root->data == value) return 1;

    if (printAncestors(root->left, value) || printAncestors(root->right, value)) {
        printf("%d ", root->data);
        return 1;
    }

    return 0;
}

int countLeafNodes(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Node* root = insertLevelOrder(arr, root, 0, n);

    printf("In-order Traversal: ");
    inOrderTraversal(root);

    printf("Post-order Traversal: ");
    postOrderTraversal(root);

    printf("Pre-order Traversal: ");
    preOrderTraversal(root);

    int value;
    printf("Enter a value to find its parent: ");
    scanf("%d", &value);
    struct Node* parent = findParent(root, value);
    if (parent != NULL) {
        printf("Parent of %d: %d\n", value, parent->data);
    } else {
        printf("No parent found for %d.\n", value);
    }

    printf("Depth of the tree: %d\n", depth(root));

    printf("Enter a value to find its ancestors: ");
    scanf("%d", &value);
    printf("Ancestors of %d: ", value);
    if (!printAncestors(root, value)) {
        printf("No ancestors found for %d.\n", value);
    } else {
        printf("\n");
    }

    printf("Number of leaf nodes: %d\n", countLeafNodes(root));

    return 0;
}
