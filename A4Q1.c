#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to rotate the linked list counter-clockwise by k nodes
void rotateList(struct Node** head_ref, int k) {
    if (*head_ref == NULL || k == 0) {
        return;
    }

    // Determine the length of the linked list
    struct Node* current = *head_ref;
    int length = 1;
    while (current->next != NULL) {
        current = current->next;
        length++;
    }

    // If k is greater than or equal to length, take k modulo length
    k = k % length;
    if (k == 0) {
        return;
    }

    // Traverse to the (k-1)-th node
    current = *head_ref;
    for (int i = 1; i < k; i++) {
        current = current->next;
    }

    struct Node* new_head = current->next;
    current->next = NULL;

    struct Node* new_tail = new_head;
    while (new_tail->next != NULL) {
        new_tail = new_tail->next;
    }
    new_tail->next = *head_ref;
    *head_ref = new_head;
}

int main() {
    struct Node* head = NULL;

    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    printf("Original list: ");
    printList(head);

    int k;
    printf("Enter the number of nodes to rotate by: ");
    scanf("%d", &k);

    rotateList(&head, k);

    printf("Rotated list by %d nodes: ", k);
    printList(head);

    return 0;
}