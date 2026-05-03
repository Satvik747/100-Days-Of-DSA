/*
Problem Statement:
Given an array of integers where each element represents the number of pages in a book, 
and m students, allocate books such that each student gets at least one book and the 
maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format:
n m
n space-separated integers representing pages in books

Output Format:
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input:
4 2
12 34 67 90

Sample Output:
113

Explanation:
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).
*/

#include <stdio.h>
#include <stdlib.h>

int isPossible(int* arr, int n, int m, int maxPages) {
    int students = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;

        if (sum + arr[i] > maxPages) {
            students++;
            sum = arr[i];
        } else {
            sum += arr[i];
        }

        if (students > m)
            return 0;
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int* arr = (int*)malloc(n * sizeof(int));

    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int left = 0, right = sum;
    int ans = sum;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%d", ans);

    free(arr);
    return 0;
}