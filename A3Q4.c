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

struct Node* copyArrayToList(int arr[], int size) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* last = NULL;

    for (int i = 0; i < size; i++) {
        temp = createNode(arr[i]); 
        if (head == NULL) {
            head = temp; 
        } else {
            last->next = temp; 
        }
        last = temp; 
    }

    return head;
}

void displayList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("The singly linked list is: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct Node* head = copyArrayToList(arr, size);

    displayList(head);

    return 0;
}
