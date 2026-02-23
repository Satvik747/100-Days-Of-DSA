/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int size = 2 * n + 1;
    int *freq = (int *)calloc(size, sizeof(int));

    int sum = 0, count = 0;
    freq[n] = 1;   // sum = 0 mapped to index n

    for(int i = 0; i < n; i++) {
        sum += arr[i];
        count += freq[sum + n];
        freq[sum + n]++;
    }

    printf("%d", count);

    free(arr);
    free(freq);
    return 0;
}