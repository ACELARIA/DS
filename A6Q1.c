#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

Node *top = NULL; 

void push(char item) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = item;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    char item = top->data;
    Node *temp = top;
    top = top->next;
    free(temp); 
    return item;
}

char peek() {
    if (top == NULL) {
        return '\0';
    }
    return top->data;
}

int isEmpty() {
    return top == NULL;
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '^':
            return 2;
        default:
            return 0; 
    }
}

void infixToPostfix(char *infix, char *postfix) {
    int postfixIndex = 0;
    int infixIndex = 0;

    while (infix[infixIndex] != '\0') {
        char currentChar = infix[infixIndex];

        if (isalnum(currentChar)) { 
            postfix[postfixIndex++] = currentChar;
        } else if (currentChar == '(') { 
            push(currentChar);
        } else if (currentChar == ')') { 
            while (peek() != '(') {
                postfix[postfixIndex++] = pop();
            }
            pop(); 
        } else if (strchr("+-*/^", currentChar)) { 
            while (!isEmpty() && precedence(currentChar) <= precedence(peek())) {
                postfix[postfixIndex++] = pop();
            }
            push(currentChar);
        }
        infixIndex++;
    }

    while (!isEmpty()) {
        postfix[postfixIndex++] = pop();
    }

    postfix[postfixIndex] = '\0';
}

int main() {
    char infix[100]; 
    char postfix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    while (top != NULL) {
        pop(); 
    }

    return 0;
}
