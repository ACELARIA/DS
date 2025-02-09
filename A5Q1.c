#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode;  
    return newNode;
}

void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
        if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    int count = 1;

    while (count < position - 1 && temp->next != *head) {
        temp = temp->next;
        count++;
    }

    if (position == 1) {
        newNode->next = *head;
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = newNode;
        *head = newNode;
    } 
    else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }

    last->next = newNode;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }

    last->next = newNode;
    newNode->next = *head;
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    if (position == 1) {
        if (*head == (*head)->next) {
            free(*head);
            *head = NULL;
            return;
        }

        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }

        last->next = temp->next;
        *head = temp->next;
        free(temp);
        return;
    }

    int count = 1;
    while (count < position - 1 && temp->next != *head) {
        temp = temp->next;
        count++;
    }

    if (temp->next == *head) {
        printf("Position out of range.\n");
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    if (*head == (*head)->next) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }

    last->next = temp->next;
    *head = temp->next;
    free(temp);
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    if (*head == (*head)->next) {
        free(*head);
        *head = NULL;
        return;
    }

    while (temp->next->next != *head) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = *head;
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at Specific Position\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Delete at Specific Position\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Print List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("current list:\n");
                printList(head);
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                printf("New list:\n");
                printList(head);
                break;
            case 2:
            printf("current list:\n");
            printList(head);
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                printf("New list:\n");
                printList(head);
                break;
            case 3:
            printf("current list:\n");
            printList(head);
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printf("New list:\n");
                printList(head);
                break;
            case 4:
            printf("current list:\n");
            printList(head);
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                printf("New list:\n");
                printList(head);
                break;
            case 5:
            printf("current list:\n");
            printList(head);
                deleteAtBeginning(&head);
                printf("New list:\n");
                printList(head);
                break;
            case 6:
            printf("current list:\n");
            printList(head);
                deleteAtEnd(&head);
                printf("New list:\n");
                printList(head);
                break;
            case 7:
                printList(head);
                break;
            case 0:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
