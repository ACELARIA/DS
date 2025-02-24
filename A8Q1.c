#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;          
    int priority;      
    struct Node* next; 
};

struct PriorityQueue {
    struct Node* front; 
};

struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void initQueue(struct PriorityQueue* queue) {
    queue->front = NULL;
}

int isEmpty(struct PriorityQueue* queue) {
    return queue->front == NULL;
}

void enqueue(struct PriorityQueue* queue, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        struct Node* temp = queue->front;
        struct Node* prev = NULL;

        while (temp != NULL && temp->priority >= priority) {
            prev = temp;
            temp = temp->next;
        }

        if (prev == NULL) {
            newNode->next = queue->front;
            queue->front = newNode;
        } else {
            prev->next = newNode;
            newNode->next = temp;
        }
    }
}

int dequeue(struct PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1; 
    }

    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    free(temp);
    return data;
}

int peek(struct PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1; 
    }
    return queue->front->data; 
}

int isFull(struct PriorityQueue* queue) {
    return 0; 
}

int main() {
    struct PriorityQueue queue;
    initQueue(&queue);

    int choice, data, priority;

    do {
        printf("\nPriority Queue Operations:\n");
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
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                printf("Enter priority (higher value means higher priority): ");
                scanf("%d", &priority);
                enqueue(&queue, data, priority);
                printf("Enqueued %d with priority %d.\n", data, priority);
                break;

            case 2:
                data = dequeue(&queue);
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;

            case 3:
                data = peek(&queue);
                if (data != -1) {
                    printf("Front element is: %d\n", data);
                }
                break;

            case 4:
                if (isEmpty(&queue)) {
                    printf("The queue is empty.\n");
                } else {
                    printf("The queue is not empty.\n");
                }
                break;

            case 5:
                if (isFull(&queue)) {
                    printf("The queue is full.\n");
                } else {
                    printf("The queue is not full.\n");
                }
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
