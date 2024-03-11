#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    newNode->next = *head;
    *head = newNode;
}
void insertAtTail(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position. Position must be non-negative.\n");
        return;
    }
    if (position == 0) {
        insertAtHead(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int currentPosition = 0;
    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }
    if (current == NULL) {
        printf("Position exceeds the length of the list.\n");
        return;
    }
    newNode->prev = current;
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}
void deleteAtHead(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}
void deleteAtTail(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
}
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (position < 0) {
        printf("Invalid position. Position must be non-negative.\n");
        return;
    }
    if (position == 0) {
        deleteAtHead(head);
        return;
    }
    struct Node* current = *head;
    int currentPosition = 0;
    while (current != NULL && currentPosition < position) {
        current = current->next;
        currentPosition++;
    }
    if (current == NULL) {
        printf("Position exceeds the length of the list.\n");
        return;
    }
    current->prev->next = current->next;
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
}
int search(struct Node* head, int key) {
    struct Node* current = head;
    int position = 0;
    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
}
void displayForward(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void displayBackward(struct Node* head) {
    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}
int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at the Head\n");
        printf("2. Insert at the Tail\n");
        printf("3. Insert at a Position\n");
        printf("4. Delete at the Head\n");
        printf("5. Delete at the Tail\n");
        printf("6. Delete at a Position\n");
        printf("7. Search for an Element\n");
        printf("8. Display Forward\n");
        printf("9. Display Backward\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the head: ");
                scanf("%d", &data);
                insertAtHead(&head, data);
                break;

            case 2:
                printf("Enter data to insert at the tail: ");
                scanf("%d", &data);
                insertAtTail(&head, data);
                break;

            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;

            case 4:
                deleteAtHead(&head);
                break;

            case 5:
                deleteAtTail(&head);
                break;

            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;

            case 7:
                printf("Enter element to search: ");
                scanf("%d", &data);
                position = search(head, data);
                if (position != -1) {
                    printf("Element %d found at position %d\n", data, position);
                } else {
                    printf("Element %d not found in the linked list\n", data);
                }
                break;

            case 8:
                printf("Doubly Linked List (Forward): ");
                displayForward(head);
                break;

            case 9:
                printf("Doubly Linked List (Backward): ");
                displayBackward(head);
                break;

            case 10:
                freeList(head);
                exit(0);
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}


