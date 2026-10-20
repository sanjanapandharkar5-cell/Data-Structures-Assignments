#include <stdio.h>
#include <ctype.h>
#define max 10

int stack[max];
int top = -1;

struct Variable {
 char name;
 char value;
};

void push(int item) {
 if(top<max-1) {
    top++;
    stack[top] = item;
}
}

int pop() {
   if(top>=0) {
      int item = stack[top];
      top--;
      return item;
    }
    return 0;
}

int evaluate(char postfix[]){
    for(int i=0; postfix[i]!='\0'; i++){
        char ch = postfix[i];
        if(isalpha(ch)) {
           int val;
           printf("Enter value for %c:", ch);
           scanf("%d", &val);
           push(val);
        } else if(ch=='+' || ch=='-' || ch=='/' || ch=='*') {
               int op2= pop();
               int op1 = pop();
               switch(ch) {
                   case '+' : push(op1+op2);
                              break;
                   case '-' : push(op1-op2);
                              break;
                   case '*' : push(op1*op2);
                              break;
                   case '/' : push(op1/op2);
                              break;
                   default:   printf("wrong operator");
                              break;

               }
        }
    }
    return pop();
}
int main() {
   char postfix[max];
   scanf("%s", postfix);
   int ans = evaluate(postfix);
   printf("Solution: %d", ans);

}
