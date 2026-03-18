/*
Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers (level-order input)
- Use -1 to represent NULL nodes

Output:
- Print the level order traversal of the binary tree
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

// Build Tree from level order input
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

// Level Order Traversal (BFS)
void levelOrder(Node* root) {
    if (root == NULL) return;

    Node** queue = (Node**)malloc(1000 * sizeof(Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* curr = queue[front++];
        printf("%d ", curr->data);

        if (curr->left)
            queue[rear++] = curr->left;

        if (curr->right)
            queue[rear++] = curr->right;
    }

    free(queue);
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, n);

    levelOrder(root);
    printf("\n");

    free(arr);
    return 0;
}