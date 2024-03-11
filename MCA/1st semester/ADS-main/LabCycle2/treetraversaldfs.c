#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void inOrderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}
void preOrderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}
void breadthFirstTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    struct TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct TreeNode* currentNode = queue[front++];
        printf("%d ", currentNode->data);

        if (currentNode->left != NULL) {
            queue[rear++] = currentNode->left;
        }

        if (currentNode->right != NULL) {
            queue[rear++] = currentNode->right;
        }
    }
}
int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. In-Order Traversal\n");
        printf("2. Pre-Order Traversal\n");
        printf("3. Post-Order Traversal\n");
        printf("4. Breadth-First Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("In-Order Traversal: ");
                inOrderTraversal(root);
                break;
            case 2:
                printf("Pre-Order Traversal: ");
                preOrderTraversal(root);
                break;
            case 3:
                printf("Post-Order Traversal: ");
                postOrderTraversal(root);
                break;
            case 4:
                printf("Breadth-First Traversal: ");
                breadthFirstTraversal(root);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
