/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff;
    int exp;
    struct node* next;
};

struct node* insert(struct node* head,int c,int e){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=c;
    newnode->exp=e;
    newnode->next=NULL;

    if(head==NULL)
        return newnode;

    struct node* tmp=head;
    while(tmp->next!=NULL)
        tmp=tmp->next;

    tmp->next=newnode;
    return head;
}

void display(struct node* head){
    struct node* tmp=head;

    while(tmp!=NULL){
        if(tmp->exp==0)
            printf("%d",tmp->coeff);
        else if(tmp->exp==1)
            printf("%dx",tmp->coeff);
        else
            printf("%dx^%d",tmp->coeff,tmp->exp);

        if(tmp->next!=NULL)
            printf(" + ");

        tmp=tmp->next;
    }
}

int main(){
    int n,c,e;
    struct node* head=NULL;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d %d",&c,&e);
        head=insert(head,c,e);
    }

    display(head);

    return 0;
}