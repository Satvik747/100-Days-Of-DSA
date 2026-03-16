/*
Problem: Deque (Double-Ended Queue)

A Deque allows insertion and deletion from both front and rear.

Operations:
1. push_front
2. push_back
3. pop_front
4. pop_back
5. front
6. back
7. empty
8. size
9. clear
10. reverse
11. sort
12. display
13. exit
*/

#include <stdio.h>

#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

int isEmpty()
{
    return (front == -1 || front > rear);
}

void push_front(int x)
{
    if(front == -1)
    {
        front = rear = 0;
        dq[front] = x;
    }
    else if(front > 0)
    {
        dq[--front] = x;
    }
}

void push_back(int x)
{
    if(front == -1)
    {
        front = rear = 0;
        dq[rear] = x;
    }
    else
    {
        dq[++rear] = x;
    }
}

void pop_front()
{
    if(isEmpty())
        printf("Deque Empty\n");
    else
        front++;
}

void pop_back()
{
    if(isEmpty())
        printf("Deque Empty\n");
    else
        rear--;
}

void get_front()
{
    if(isEmpty())
        printf("-1\n");
    else
        printf("%d\n", dq[front]);
}

void get_back()
{
    if(isEmpty())
        printf("-1\n");
    else
        printf("%d\n", dq[rear]);
}

void size()
{
    if(isEmpty())
        printf("0\n");
    else
        printf("%d\n", rear - front + 1);
}

void empty()
{
    if(isEmpty())
        printf("1\n");
    else
        printf("0\n");
}

void clear()
{
    front = rear = -1;
}

void reverse()
{
    int i = front, j = rear, temp;
    while(i < j)
    {
        temp = dq[i];
        dq[i] = dq[j];
        dq[j] = temp;
        i++;
        j--;
    }
}

void sortDeque()
{
    int i, j, temp;
    for(i = front; i <= rear; i++)
    {
        for(j = i + 1; j <= rear; j++)
        {
            if(dq[i] > dq[j])
            {
                temp = dq[i];
                dq[i] = dq[j];
                dq[j] = temp;
            }
        }
    }
}

void display()
{
    if(isEmpty())
        printf("Deque Empty\n");
    else
    {
        for(int i = front; i <= rear; i++)
            printf("%d ", dq[i]);
        printf("\n");
    }
}

int main()
{
    int ch, x;

    while(1)
    {
        printf("\n1.Push Front\n2.Push Back\n3.Pop Front\n4.Pop Back\n5.Front\n6.Back\n7.Empty\n8.Size\n9.Clear\n10.Reverse\n11.Sort\n12.Display\n13.Exit\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                scanf("%d", &x);
                push_front(x);
                break;

            case 2:
                scanf("%d", &x);
                push_back(x);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                get_front();
                break;

            case 6:
                get_back();
                break;

            case 7:
                empty();
                break;

            case 8:
                size();
                break;

            case 9:
                clear();
                break;

            case 10:
                reverse();
                break;

            case 11:
                sortDeque();
                break;

            case 12:
                display();
                break;

            case 13:
                return 0;
        }
    }
}