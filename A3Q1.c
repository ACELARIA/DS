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
    struct Node* temp = NULL;

    head = createNode(1); 
    temp = createNode(2); 
    head->next = temp;     

    temp = createNode(3); 
    head->next->next = temp; 

    temp = createNode(4); 
    head->next->next->next = temp; 

    printf("The singly linked list is: ");
    displayList(head);

    return 0;
}
