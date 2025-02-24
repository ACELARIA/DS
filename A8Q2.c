#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

int isEmpty() {
    return front == NULL;
}

void enqueue(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode;
        rear->next = front; 
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; 
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1; 
    }
    
    struct Node* temp = front;
    int data = front->data;
    
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front; 
    }

    free(temp); 
    return data;
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1; 
    }
    return front->data;
}


int isFull(int maxSize) {
    int size = 0;
    struct Node* temp = front;
    while (temp != NULL) {
        size++;
        temp = temp->next;
        if (size >= maxSize) {
            return 1; 
        }
    }
    return 0; 
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    
    struct Node* temp = front;
    printf("Queue: ");
    while (temp != rear) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", rear->data); 
}

int main() {
    int choice, data, maxSize = 5; 
    
    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Check if Queue is Empty\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                if (isFull(maxSize)) {
                    printf("Queue is full!\n");
                } else {
                    enqueue(data);
                    printf("Enqueued %d\n", data);
                }
                break;
                
            case 2:
                data = dequeue();
                if (data != -1) {
                    printf("Dequeued %d\n", data);
                }
                break;
                
            case 3:
                data = peek();
                if (data != -1) {
                    printf("Front element: %d\n", data);
                }
                break;
                
            case 4:
                display();
                break;
                
            case 5:
                if (isEmpty()) {
                    printf("Queue is empty!\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
                
            case 6:
                printf("Exiting program...\n");
                return 0;
                
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    
    return 0;
}
