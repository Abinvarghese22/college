#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    int height;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int calculateHeight(struct Node* node) {
    int leftHeight = (node->left) ? node->left->height : 0;
    int rightHeight = (node->right) ? node->right->height : 0;
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}
void updateHeight(struct Node* node) {
    node->height = calculateHeight(node);
}
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T = x->right;
    x->right = y;
    y->left = T;
    updateHeight(y);
    updateHeight(x);
    return x;
}
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T = y->left;
    y->left = x;
    x->right = T;
    updateHeight(x);
    updateHeight(y);
    return y;
}
struct Node* balanceNode(struct Node* node) {
    int balance = (node->left ? node->left->height : 0) - (node->right ? node->right->height : 0);
    if (balance > 1) {
        if (node->left->left) {
            return rightRotate(node);
        } else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (balance < -1) {
        if (node->right->right) {
            return leftRotate(node);
        } else {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    return node;
}
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        struct Node* newNode = createNode(value);
        return newNode;
    }
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    updateHeight(root);
    return balanceNode(root);
}
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL)
        return root;
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    updateHeight(root);
    return balanceNode(root);
}
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;
    if (value < root->data)
        return search(root->left, value);
    return search(root->right, value);
}
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}
int main() {
    struct Node* root = NULL;
    int choice, value;
    do {
        printf("\nBalanced Binary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. In-order Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                if (search(root, value) == NULL)
                    root = insert(root, value);
                else
                    printf("%d is already in the tree.\n", value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                if (search(root, value) != NULL)
                    root = deleteNode(root, value);
                else
                    printf("%d not found in the tree.\n", value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* result = search(root, value);
                if (result != NULL)
                    printf("%d found in the tree.\n", value);
                else
                    printf("%d not found in the tree.\n", value);
                break;

            case 4:
                printf("In-order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
    while (root != NULL) {
        struct Node* temp = root;
        root = deleteNode(root, temp->data);
    }
    return 0;
}
