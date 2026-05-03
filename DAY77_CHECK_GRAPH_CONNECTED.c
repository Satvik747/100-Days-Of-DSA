/*
Problem Statement:
Using BFS or DFS, check if the entire graph is connected.

Input Format:
n m
edges

Output Format:
CONNECTED
NOT CONNECTED

Sample Input:
4 2
1 2
3 4

Sample Output:
NOT CONNECTED
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void dfs(int v, struct Node** adj, int* visited) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data]) {
            dfs(temp->data, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node** adj = (struct Node**)malloc((n + 1) * sizeof(struct Node*));
    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        struct Node* newNode2 = createNode(u);
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    int* visited = (int*)calloc(n + 1, sizeof(int));

    // Start DFS from node 1
    dfs(1, adj, visited);

    int connected = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("CONNECTED");
    else
        printf("NOT CONNECTED");

    for (int i = 1; i <= n; i++) {
        struct Node* temp = adj[i];
        while (temp) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }

    free(adj);
    free(visited);

    return 0;
}