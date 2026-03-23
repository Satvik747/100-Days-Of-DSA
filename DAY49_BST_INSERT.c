/*
Problem Statement:
Insert elements into a Binary Search Tree (BST) and print its inorder traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the inorder traversal of the BST

Example:
Input:
5
4 2 6 1 3

Output:
1 2 3 4 6
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void inorder(struct Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n, i, x;
    scanf("%d", &n);

    struct Node* root = NULL;

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    inorder(root);
    printf("\n");

    return 0;
}