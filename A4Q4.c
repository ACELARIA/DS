#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertAtFirst(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = *head;
    new_node->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = new_node;
    }

    *head = new_node;
}

void insertAtEnd(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

void insertAtMiddle(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;

    if (*head == NULL) {
        new_node->next = NULL;
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    struct Node* slow = *head;
    struct Node* fast = *head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    new_node->next = slow->next;
    new_node->prev = slow;
    
    if (slow->next != NULL) {
        slow->next->prev = new_node;
    }
    
    slow->next = new_node;
}

void insertAfterNode(struct Node** head, struct Node* given_node, int new_data) {
    if (given_node == NULL) {
        printf("Given node cannot be NULL.\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = given_node->next;
    new_node->prev = given_node;

    if (given_node->next != NULL) {
        given_node->next->prev = new_node;
    }

    given_node->next = new_node;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtFirst(&head,3);
    insertAtFirst(&head,2);
    insertAtFirst(&head,1);
    
    insertAtEnd(&head,4);
    insertAtEnd(&head,5);

    printf("Original List: ");
    display(head);

    insertAtMiddle(&head,10);

    struct Node* given_node = head->next; 
    insertAfterNode(&head,given_node,6);

    printf("Doubly Linked List: ");
    display(head);

    return 0;
}
