#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void display() {
    struct Node* current = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

void insertAtHead(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    struct Node* temp = head;

    if (temp == NULL) {
        newNode->next = newNode; 
    } else {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    head = newNode;
    display();
}

void insertAtTail(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    if (head == NULL) {
        newNode->next = newNode; 
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    display();
}

void insertAtPosition(int value, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertAtHead(value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* current = head;
    for (int i = 1; i < position - 1; i++) {
        current = current->next;
        if (current == head) {
            printf("Invalid position\n");
            free(newNode);
            return;
        }
    }

    newNode->next = current->next;
    current->next = newNode;
    display();
}

void deleteAtHead() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    if (temp == head) {
        free(head);
        head = NULL;
    } else {
        temp->next = head->next;
        free(head);
        head = temp->next;
    }

    display();
}

void deleteAtTail() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current->next != head) {
        prev = current;
        current = current->next;
    }

    if (current == head) {
        free(head);
        head = NULL;
    } else {
        prev->next = head;
        free(current);
    }

    display();
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    if (position == 1) {
        deleteAtHead();
        return;
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    int count = 1;

    do {
        prev = current;
        current = current->next;
        count++;
    } while (current != head && count < position);

    if (current == head && count < position) {
        printf("Invalid position\n");
        return;
    }

    prev->next = current->next;
    free(current);

    display();
}

int search(int value) {
    struct Node* current = head;
    int position = 1;
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }

    do {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    } while (current != head);

    printf("%d not found in the list\n", value);
    return -1;
}

int main() {
    int choice, data, position;
    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at Head\n");
        printf("2. Insert at Tail\n");
        printf("3. Insert at a Position\n");
        printf("4. Delete at Head\n");
        printf("5. Delete at Tail\n");
        printf("6. Delete at a Position\n");
        printf("7. Search for an Element\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insertAtHead(data);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insertAtTail(data);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 4:
                deleteAtHead();
                break;
            case 5:
                deleteAtTail();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &data);
                int result = search(data);
                if (result != -1) {
                    printf("%d found at position %d\n", data, result);
                }
                break;
            case 8:
                display();
                break;
            case 9:
            	printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
