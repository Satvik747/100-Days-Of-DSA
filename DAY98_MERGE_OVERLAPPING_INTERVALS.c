/*
Problem: Given intervals, merge all overlapping ones.
Approach: Sort intervals by start time, then iterate and merge overlapping intervals.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

/* Sort by start time */
int compare(const void *a, const void *b) {
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;
    return i1->start - i2->start;
}

int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval *arr = (Interval *)malloc(n * sizeof(Interval));

    printf("Enter intervals (start end):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Interval), compare);

    Interval *merged = (Interval *)malloc(n * sizeof(Interval));
    int idx = 0;

    merged[0] = arr[0];

    for (int i = 1; i < n; i++) {
        /* If overlap, merge */
        if (arr[i].start <= merged[idx].end) {
            if (arr[i].end > merged[idx].end) {
                merged[idx].end = arr[i].end;
            }
        } 
        else {
            idx++;
            merged[idx] = arr[i];
        }
    }

    printf("Merged intervals:\n");
    for (int i = 0; i <= idx; i++) {
        printf("%d %d\n", merged[i].start, merged[i].end);
    }

    free(arr);
    free(merged);

    return 0;
}