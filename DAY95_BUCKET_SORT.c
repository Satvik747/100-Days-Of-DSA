/*
Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    float data;
    struct Node* next;
};

struct Node* createNode(float data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Insert in sorted order (for bucket)
void insertSorted(struct Node** head, float value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next && temp->next->data < value)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {
    int n;
    scanf("%d", &n);

    float* arr = (float*)malloc(n * sizeof(float));

    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    // Create buckets
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int idx = (int)(arr[i] * n);
        insertSorted(&buckets[idx], arr[i]);
    }

    // Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while (temp) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }

    // Print sorted array
    for (int i = 0; i < n; i++)
        printf("%.6f ", arr[i]);

    // Free memory
    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while (temp) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }

    free(buckets);
    free(arr);

    return 0;
}