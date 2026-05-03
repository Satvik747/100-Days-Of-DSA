/*
Problem Statement:
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format:
n m
u v w
...

Output Format:
Total weight of MST.

Sample Input:
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output:
6

Explanation:
One possible MST edges: (2-3), (3-4), (1-2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Node* createNode(int v, int w) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->weight = w;
    node->next = NULL;
    return node;
}

int minKey(int* key, int* mstSet, int n) {
    int min = INT_MAX, min_index = -1;
    for (int i = 1; i <= n; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node** adj = (struct Node**)malloc((n + 1) * sizeof(struct Node*));
    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        struct Node* newNode = createNode(v, w);
        newNode->next = adj[u];
        adj[u] = newNode;

        struct Node* newNode2 = createNode(u, w);
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    int* key = (int*)malloc((n + 1) * sizeof(int));
    int* mstSet = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++)
        key[i] = INT_MAX;

    key[1] = 0;  // Start from node 1

    int totalWeight = 0;

    for (int i = 1; i <= n; i++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;
        totalWeight += key[u];

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if (!mstSet[v] && w < key[v]) {
                key[v] = w;
            }
            temp = temp->next;
        }
    }

    printf("%d", totalWeight);

    for (int i = 1; i <= n; i++) {
        struct Node* temp = adj[i];
        while (temp) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }

    free(adj);
    free(key);
    free(mstSet);

    return 0;
}