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

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void removeDuplicates(struct Node* head) {
    struct Node *current = head, *prev = NULL, *temp = NULL;
    
    while (current != NULL && current->next != NULL) {
        prev = current;
        temp = current->next;

        while (temp != NULL) {
            if (current->data == temp->data) {
                prev->next = temp->next;
                free(temp); 
                temp = prev->next; 
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(1);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(3);
    head->next->next->next->next->next = createNode(3);
    head->next->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next->next->next = createNode(5);

    printf("Original List: ");
    printList(head);

    removeDuplicates(head);

    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}
