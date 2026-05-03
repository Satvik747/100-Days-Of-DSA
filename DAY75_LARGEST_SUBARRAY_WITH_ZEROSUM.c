/*
Problem Statement:
Given an array of integers containing both positive and negative values, find the length 
of the longest contiguous subarray whose sum is equal to zero.

Input Format:
An integer array arr[].

Output Format:
Print the length of the longest subarray with sum equal to zero.

Sample Input:
15 -2 2 -8 1 7 10 23

Sample Output:
5

Explanation:
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int maxLen = 0;

    // Brute force approach
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                int len = j - i + 1;
                if (len > maxLen)
                    maxLen = len;
            }
        }
    }

    printf("%d", maxLen);

    free(arr);
    return 0;
}