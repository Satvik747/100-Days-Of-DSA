/*
Problem: Implement topological sorting using in-degree array and queue (Kahn's Algorithm).
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

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node** adj = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int* indegree = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        indegree[v]++;
    }

    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        count++;

        struct Node* temp = adj[u];
        while (temp) {
            indegree[temp->data]--;
            if (indegree[temp->data] == 0)
                queue[rear++] = temp->data;
            temp = temp->next;
        }
    }

    if (count != n) {
        printf("Cycle detected");
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
    free(indegree);
    free(queue);

    return 0;
}
