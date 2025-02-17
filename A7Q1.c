#include <stdio.h>
#include <ctype.h>  
#define MAXSIZE 100

typedef struct {
    int items[MAXSIZE];
    int top;
} STACK;

void initStack(STACK* s) {
    s->top = -1;
}
void push(STACK* s, int value) {
    if (s->top < MAXSIZE - 1) {
        s->items[++(s->top)] = value;
    } else {
        printf("Stack Overflow\n");
    }
}
int pop(STACK* s) {
    if (s->top >= 0) {
        return s->items[(s->top)--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}
int evaluatePostfix(char* postfix) {
    STACK stack;
    initStack(&stack); 
    int i = 0;

    while (postfix[i] != '\0') {
        char currentChar = postfix[i];
        
        if (isdigit(currentChar)) {
            push(&stack, currentChar - '0'); 
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            
            switch (currentChar) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                    case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator\n");  
                    return -1;
                }
            }
            
            i++;
        }
        return pop(&stack);
    }
    int main() {
        char postfix[100];
        
        printf("Enter postfix expression: ");
        scanf("%s", postfix);
    
        int result = evaluatePostfix(postfix);
        
        printf("Output: %d\n", result);
        
        return 0;
    }    