/*
Problem Statement:
Given a string s consisting of lowercase letters, find the first repeated character in the string. 
A character is considered repeated if it appears more than once, and among all such characters, 
the one whose second occurrence has the smallest index should be returned.

Input Format:
A single string s.

Output Format:
Print the first repeated character. If no character is repeated, print -1.

Sample Input:
geeksforgeeks

Sample Output:
e
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';

        if (freq[idx] == 1) {
            printf("%c", s[i]);
            return 0;
        }

        freq[idx]++;
    }

    printf("-1");
    return 0;
}