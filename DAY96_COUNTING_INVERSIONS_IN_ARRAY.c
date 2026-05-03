/*
Problem: Count number of inversions using modified merge sort.
An inversion is a pair (i, j) such that i < j and a[i] > a[j].
*/

#include <stdio.h>
#include <stdlib.h>

long long merge(int *arr, int *temp, int left, int mid, int right) {
    int i = left;      // left subarray
    int j = mid + 1;   // right subarray
    int k = left;
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); // key inversion count
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

long long mergeSort(int *arr, int *temp, int left, int right) {
    long long inv_count = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid, right);
    }

    return inv_count;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long inversion_count = mergeSort(arr, temp, 0, n - 1);

    printf("Number of inversions = %lld\n", inversion_count);

    free(arr);
    free(temp);

    return 0;
}