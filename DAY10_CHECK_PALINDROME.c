/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/
#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int i = 0;
    int j = strlen(s) - 1;
    int isPalindrome = 1;

    while (i < j) {
        if (s[i] != s[j]) {
            isPalindrome = 0;
            break;
        }
        i++;
        j--;
    }

    if (isPalindrome)
        printf("YES");
    else
        printf("NO");

    return 0;
}