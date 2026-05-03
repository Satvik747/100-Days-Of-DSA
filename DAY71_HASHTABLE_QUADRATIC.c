/*
Problem Statement:
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format:
Same as previous.

Output Format:
Result of SEARCH operations.

Sample Input:
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output:
FOUND
NOT FOUND

Explanation:
Collisions resolved using i² jumps.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1
#define DELETED -2

int hash(int key, int m) {
    return key % m;
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    int* table = (int*)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    while (q--) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            int h = hash(key, m);
            int i = 0;

            while (i < m) {
                int idx = (h + i * i) % m;
                if (table[idx] == EMPTY || table[idx] == DELETED) {
                    table[idx] = key;
                    break;
                }
                i++;
            }
        }
        else if (strcmp(op, "SEARCH") == 0) {
            int h = hash(key, m);
            int i = 0;
            int found = 0;

            while (i < m) {
                int idx = (h + i * i) % m;

                if (table[idx] == EMPTY)
                    break;

                if (table[idx] == key) {
                    found = 1;
                    break;
                }
                i++;
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    free(table);
    return 0;
}