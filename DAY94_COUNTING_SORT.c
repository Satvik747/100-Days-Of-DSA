/*
Problem: Sort array of non-negative integers using counting sort.
Find max, build freq array, compute prefix sums, build output.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Find maximum element
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Frequency array
    int* count = (int*)calloc(max + 1, sizeof(int));

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Prefix sum array
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Output array
    int* output = (int*)malloc(n * sizeof(int));

    // Build output (stable)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy back to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    // Print sorted array
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);
    free(count);
    free(output);

    return 0;
}