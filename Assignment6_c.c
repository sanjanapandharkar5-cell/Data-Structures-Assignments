#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
#define MAX_STR_LEN 200

char stack[MAX][MAX_STR_LEN];
int top = -1;

void push(char item[]) {
    if (top < MAX - 1) {
        top++;
        strcpy(stack[top], item);
    }
}

void pop(char item[]) {
    if (top >= 0) {
        strcpy(item, stack[top]);
        top--;
    }
}

int isempty() {
    return top == -1;
}

int isfull() {
    return top == MAX - 1;
}

void postfixToInfix(char postfix[], char infix[]) {
    int i = 0;
    char ch;
    char op1[MAX_STR_LEN], op2[MAX_STR_LEN], temp[MAX_STR_LEN];

    while (postfix[i] != '\0') {
        ch = postfix[i];

        if (isalnum(ch)) {
            temp[0] = ch;
            temp[1] = '\0';
            push(temp);
        }
        else {
            if (!isempty()) {
               pop(op2);
}
            if (!isempty()) {
               pop(op1);
}
            temp[0] = '(';
            temp[1] = '\0';
            strcat(temp, op1);
            char opStr[2] = {ch, '\0'};
            strcat(temp, opStr);
            strcat(temp, op2);
            strcat(temp, ")");
            push(temp);
        }
        i++;
    }

    if (!isempty()) {
        pop(infix);
    } else {
        infix[0] = '\0';
    }
}

int main() {
    char postfix[MAX], infix[MAX_STR_LEN];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    top = -1;
    postfixToInfix(postfix, infix);

    printf("Infix expression: %s\n", infix);

    return 0;
}
