#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    top++;
    stack[top] = item;
}

char pop() {
    char item = stack[top];
    top--;
    return item;
}

int isempty() {
    return top == -1;
}

int isfull() {
    return top == MAX - 1;
}

int isp(char ch) {
    switch (ch) {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
        case '(': return 0;
        default:  return 0;
    }
}


int icp(char ch) {
    switch (ch) {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 4; 
        case '(': return 5; 
        default:  return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;

    while (infix[i] != '\0') {
        ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } 
        else if (ch == ')') {
            while (!isempty() && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (!isempty()) {
                pop(); 
            }
        } 
        
        else {
            while (!isempty() && isp(stack[top]) >= icp(ch)) {
                postfix[j++] = pop();
            }
            if (!isfull()) {
                push(ch);
            }
        }
        i++;
    }

    while (!isempty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
