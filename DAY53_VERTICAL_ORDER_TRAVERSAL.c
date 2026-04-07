/*
Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct QNode {
    struct Node* node;
    int hd;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    struct Node* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    free(queue);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    struct QNode* queue = (struct QNode*)malloc(n * sizeof(struct QNode));
    int front = 0, rear = 0;

    int* hd = (int*)malloc(n * sizeof(int));
    int* val = (int*)malloc(n * sizeof(int));
    int idx = 0;

    queue[rear++] = (struct QNode){root, 0};

    int min = 0, max = 0;

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* curr = temp.node;
        int h = temp.hd;

        val[idx] = curr->data;
        hd[idx] = h;
        idx++;

        if (h < min) min = h;
        if (h > max) max = h;

        if (curr->left)
            queue[rear++] = (struct QNode){curr->left, h - 1};
        if (curr->right)
            queue[rear++] = (struct QNode){curr->right, h + 1};
    }

    for (int i = min; i <= max; i++) {
        for (int j = 0; j < idx; j++) {
            if (hd[j] == i)
                printf("%d ", val[j]);
        }
        printf("\n");
    }

    free(arr);
    free(queue);
    free(hd);
    free(val);

    return 0;
}