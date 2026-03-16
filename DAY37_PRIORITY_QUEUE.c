/*
Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x)
{
    pq[size++] = x;
}

int findMinIndex()
{
    if(size == 0)
        return -1;

    int i, min = 0;
    for(i = 1; i < size; i++)
        if(pq[i] < pq[min])
            min = i;

    return min;
}

void delete()
{
    int idx = findMinIndex();
    if(idx == -1)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[idx]);

    for(int i = idx; i < size - 1; i++)
        pq[i] = pq[i + 1];

    size--;
}

void peek()
{
    int idx = findMinIndex();
    if(idx == -1)
        printf("-1\n");
    else
        printf("%d\n", pq[idx]);
}

int main()
{
    int n, x;
    char op[10];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "delete") == 0)
        {
            delete();
        }
        else if(strcmp(op, "peek") == 0)
        {
            peek();
        }
    }

    return 0;
}