#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

struct stack {
    int stArr[MAXSIZE];
    int top;
};
typedef struct stack STACK;

void create(STACK* s) {
    s->top = -1;  
}

int isFull(STACK* s) {
    if (s->top == MAXSIZE - 1) {
        return 1; 
    }
    return 0; 
}

int isEmpty(STACK* s) {
    if (s->top == -1) {
        return 1; 
    }
    return 0;  
}

void push(STACK* s, int data) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d onto the stack.\n", data);
        return;
    }
    s->stArr[++(s->top)] = data;  
    printf("%d pushed to stack.\n", data);
}

int pop(STACK* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1;
    }
    int poppedValue = s->stArr[s->top--];  
    printf("%d popped from stack.\n", poppedValue);
    return poppedValue;
}

int peek(STACK* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! No element to peek.\n");
        return -1;  
    }
    return s->stArr[s->top]; 
}

int main() {
    STACK s;
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
