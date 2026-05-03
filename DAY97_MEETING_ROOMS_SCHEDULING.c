/*
Problem: Given meeting intervals, find minimum number of rooms required.
Approach: Sort intervals by start time and use a min-heap (priority queue) on end times.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

/* Comparison function for sorting by start time */
int compare(const void *a, const void *b) {
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;
    return m1->start - m2->start;
}

/* Min-heap for end times */
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyDown(int heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, n, smallest);
    }
}

void heapifyUp(int heap[], int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) {
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else {
            break;
        }
    }
}

void insertHeap(int heap[], int *n, int val) {
    heap[*n] = val;
    (*n)++;
    heapifyUp(heap, *n - 1);
}

void removeMin(int heap[], int *n) {
    heap[0] = heap[*n - 1];
    (*n)--;
    heapifyDown(heap, *n, 0);
}

int main() {
    int n;
    printf("Enter number of meetings: ");
    scanf("%d", &n);

    Meeting *arr = (Meeting *)malloc(n * sizeof(Meeting));

    printf("Enter start and end times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Meeting), compare);

    int *heap = (int *)malloc(n * sizeof(int));
    int heapSize = 0;

    insertHeap(heap, &heapSize, arr[0].end);

    for (int i = 1; i < n; i++) {
        /* If earliest ending meeting is free */
        if (heap[0] <= arr[i].start) {
            removeMin(heap, &heapSize);
        }
        insertHeap(heap, &heapSize, arr[i].end);
    }

    printf("Minimum number of rooms required = %d\n", heapSize);

    free(arr);
    free(heap);

    return 0;
}