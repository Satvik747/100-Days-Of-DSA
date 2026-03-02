/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create(struct node *head, int n) {
    struct node *temp = NULL, *newnode = NULL;
    int i, value;

    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

struct node* deleteFirst(struct node *head, int key) {
    struct node *temp = head;
    struct node *prev = NULL;

    if(temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }


    if(temp == NULL)
        return head;

    prev->next = temp->next;
    free(temp);

    return head;
}

void display(struct node *head) {
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, key;
    struct node *head = NULL;
    scanf("%d", &n);
    head = create(head, n);
    scanf("%d", &key);
    head = deleteFirst(head, key);
    display(head);
    return 0;
}