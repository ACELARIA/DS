#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct stack {
    struct Node* top;
};

void create(struct stack* s) {
    s->top = NULL;  
}

int isFull(struct stack* s) {
    return 0;  
}

int isEmpty(struct stack* s) {
    return s->top == NULL;  
}

void push(struct stack* s, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  
    if (newNode == NULL) {
        printf("Memory allocation failed! Cannot push %d onto the stack.\n", data);
        return;
    }
    newNode->data = data;         
    newNode->next = s->top;         
    s->top = newNode;               
    printf("%d pushed to stack.\n", data);
}

int pop(struct stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1;  
    }
    struct Node* temp = s->top;  
    int poppedValue = temp->data;  
    s->top = s->top->next;  
    free(temp);  
    printf("%d popped from stack.\n", poppedValue);
    return poppedValue;
}

int peek(struct stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! No element to peek.\n");
        return -1;  
    }
    return s->top->data; 
}

int main() {
    struct stack s;
    int choice, data;

    create(&s);  

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if Stack is Full\n");
        printf("5. Check if Stack is Empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&s, data);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                data = peek(&s);
                if (data != -1) {
                    printf("Top element is: %d\n", data);
                }
                break;
            case 4:
            if (isFull(&s)) {
                printf("Stack is full.\n");
            } else {
                printf("Stack is not full.\n");
            }
            break;
            case 5:
                if (isEmpty(&s)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
