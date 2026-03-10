/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    return stack[top--];
}

char peek(){
    return stack[top];
}

int precedence(char op){
    if(op=='+' || op=='-') return 1;
    if(op=='*' || op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}

int main(){
    char infix[100], postfix[100];
    int i=0,j=0;

    scanf("%s",infix);

    while(infix[i] != '\0'){

        if(isalnum(infix[i])){
            postfix[j++] = infix[i];
        }

        else if(infix[i]=='('){
            push(infix[i]);
        }

        else if(infix[i]==')'){
            while(peek()!='(')
                postfix[j++] = pop();
            pop();
        }

        else{
            while(top!=-1 && precedence(peek()) >= precedence(infix[i]))
                postfix[j++] = pop();

            push(infix[i]);
        }

        i++;
    }

    while(top!=-1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("%s",postfix);

    return 0;
}