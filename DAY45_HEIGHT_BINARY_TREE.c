/*
Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3
*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create Node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build Tree from level order
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = createNode(arr[0]);

    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        Node* curr = queue[front++];

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    free(queue);
    return root;
}

// Find Height
int height(Node* root) {
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, n);

    printf("%d\n", height(root));

    free(arr);
    return 0;
}