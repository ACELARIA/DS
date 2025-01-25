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

int* listToArray(struct Node* head, int* size) {
    struct Node* current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    int* arr = (int*)malloc(count * sizeof(int));
    
    current = head;
    for (int i = 0; i < count; i++) {
        arr[i] = current->data;
        current = current->next;
    }

    *size = count;
    return arr;
}

void displayArray(int* arr, int size) {
    if (arr == NULL || size == 0) {
        printf("The array is empty.\n");
        return;
    }
    printf("The array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
    struct Node* head = NULL;
    struct Node* temp;
    
    head = createNode(1);
    temp = createNode(2);
    head->next = temp;
    temp = createNode(3);
    head->next->next = temp;
    temp = createNode(4);
    head->next->next->next = temp;

    displayList(head);

    int size = 0;
    int* arr = listToArray(head, &size);

    displayArray(arr, size);

    free(arr);

    return 0;
}
