#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value); 
    newNode->next = *head; 
    *head = newNode;        
}

void displayList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; 
    
    insertAtBeginning(&head, 4); 
    insertAtBeginning(&head, 3); 
    insertAtBeginning(&head, 2); 
    insertAtBeginning(&head, 1); 
    insertAtBeginning(&head, 0); 

    printf("The singly linked list is: ");
    displayList(head);

    return 0;
}
