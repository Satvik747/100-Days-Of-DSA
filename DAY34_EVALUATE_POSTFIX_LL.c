/*
Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. 
Final stack top is result.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop()
{
    struct node *temp;
    int x;
    temp = top;
    x = temp->data;
    top = top->next;
    free(temp);
    return x;
}

int main()
{
    int a, b, result, num;
    char token;

    while(scanf("%d", &num) == 1)
    {
        push(num);
        token = getchar();
        if(token == '\n')
            break;
    }

    while(scanf(" %c", &token) == 1)
    {
        if(token=='+' || token=='-' || token=='*' || token=='/')
        {
            b = pop();
            a = pop();

            if(token=='+') result = a + b;
            if(token=='-') result = a - b;
            if(token=='*') result = a * b;
            if(token=='/') result = a / b;

            push(result);
        }
    }

    printf("%d", pop());

    return 0;
}