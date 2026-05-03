/*
Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
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

void dfs(int v, struct Node** adj, int* visited, int* stack, int* top) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data]) {
            dfs(temp->data, adj, visited, stack, top);
        }
        temp = temp->next;
    }

    stack[(*top)++] = v;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node** adj = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int* visited = (int*)calloc(n, sizeof(int));
    int* stack = (int*)malloc(n * sizeof(int));
    int top = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, stack, &top);
        }
    }

    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    for (int i = 0; i < n; i++) {
        struct Node* temp = adj[i];
        while (temp) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }

    free(adj);
    free(visited);
    free(stack);

    return 0;
}
