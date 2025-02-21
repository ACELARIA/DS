#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;            
    struct Node* next;   
};

struct Queue {
    struct Node* front;  
    struct Node* rear;   
};

void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

int isEmpty(struct Queue* q) {
    return (q->front == NULL);  
}

int isFull() {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (!temp) {
        return 1; 
    }
    free(temp);
    return 0;
}

void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  
    newNode->data = value; 
    newNode->next = NULL; 

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;  
    }

    struct Node* temp = q->front;  
    int value = temp->data;        
    q->front = q->front->next;     
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);  
    return value;  
}

int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1; 
    }
    return q->front->data;  
}

int main() {
    struct Queue q;
    initQueue(&q); 

    int choice, value;

    while(1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if Queue is Empty\n");
        printf("5. Check if Queue is Full\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                printf("%d enqueued to the queue.\n", value);
                break;

            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("%d dequeued from the queue.\n", value);
                }
                break;

            case 3:
                value = peek(&q);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;

            case 4:
                if (isEmpty(&q)) {
                    printf("The queue is empty.\n");
                } else {
                    printf("The queue is not empty.\n");
                }
                break;

            case 5:
                if (isFull(&q)) {
                    printf("The queue is Full.\n");
                } else {
                    printf("The queue is not Full.\n");
                }
                break;
            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
