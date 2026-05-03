/*
Problem: For each element, count how many smaller elements appear on the right side.
Approach: Modified Merge Sort (Counting Inversions per index)
We track original indices and count how many smaller elements come after each element.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Node;

void merge(Node *arr, int *count, int left, int mid, int right, Node *temp) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].value < arr[i].value) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(Node *arr, int *count, int left, int right, Node *temp) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, count, left, mid, temp);
    mergeSort(arr, count, mid + 1, right, temp);
    merge(arr, count, left, mid, right, temp);
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *input = (int *)malloc(n * sizeof(int));
    Node *arr = (Node *)malloc(n * sizeof(Node));
    Node *temp = (Node *)malloc(n * sizeof(Node));
    int *count = (int *)calloc(n, sizeof(int));

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
        arr[i].value = input[i];
        arr[i].index = i;
    }

    mergeSort(arr, count, 0, n - 1, temp);

    printf("Count of smaller elements on right side:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    printf("\n");

    free(input);
    free(arr);
    free(temp);
    free(count);

    return 0;
}